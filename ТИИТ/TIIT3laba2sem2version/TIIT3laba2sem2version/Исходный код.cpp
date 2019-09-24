#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>
#include <stack>
#include <algorithm>

using namespace std;

enum brace_type { ORIENTED_OPEN = '<', ORIENTED_CLOSE = '>', REGULAR_OPEN = '{', REGULAR_CLOSE = '}' };	// ���� ������
enum mnogestvo_type { ORIENTED, REGULAR };	// ���� ��������
enum element_type { SINGLE, MNOGESTVO };	// ��� ��-��: ��������� ��� ������

class Mnogestvo;
class Element;
class Operations;

class Element
{
private:
	element_type _type;	// ��� ��-��

public:
	string value;	// ����-�� ����. ��-��
	Mnogestvo * mnogestvo;	// ����-�� ����. ���������
	Element(element_type);
	~Element();
	const element_type type() const;
	void setValue(string &);
	void setValue(Mnogestvo *);
	string toString() const;
	bool operator<(const Element &) const;
};

class Mnogestvo
{
private:
	vector<Element> elements;	// ������ ��� ��������� ���������
	mnogestvo_type _type;	// ��� ���������
	Element * _getElementPtr(string &, unsigned int &, unsigned int);
	bool _checkBalance(string &);

public:
	bool isSorted;
	bool isCorrect;
	Mnogestvo(mnogestvo_type);
	Mnogestvo(string &);
	~Mnogestvo();
	const mnogestvo_type type() const;
	void pushElement(Element *);
	void show(int);
	int size();
	void sort();
	string toString();
	bool hasElement(string &);
	friend class Operations;
};

class Operations
{
public:
	Mnogestvo * symDifference(Mnogestvo *, Mnogestvo *);
};


Mnogestvo::Mnogestvo(mnogestvo_type typ)
{
	// ����������� ����.
	_type = typ;	// typ - ��� ���
	isSorted = true;
}

Mnogestvo::Mnogestvo(string & strok)
{
	// ����������� ����.
	_type = REGULAR;	// strok - ������ ���������
	isSorted = true;
	isCorrect = true;
	if (!_checkBalance(strok))
	{
		cerr << " Ne pravilno (proverte sootvetstvie skobok): " << strok << endl;
		isCorrect = false;
	}
	else
	{
		unsigned int start = 1;
		while (start < strok.length() - 1)
		{
			Element * el = _getElementPtr(strok, start, strok.length() - 1);
			if (el != NULL)
				pushElement(el);
			else
				break;
		}
		if (strok != toString())
		{
			cerr << "Ne pravily vvod" << endl;
			cerr << " Polycheno: " << strok << endl;
			cerr << " Analiziryemyi kak: " << toString() << endl;
			isCorrect = false;
		}
	}
}

Mnogestvo::~Mnogestvo()
{
	/*
	TODO: fix memleaks
	vector<Element>::iterator i;
	for (i=elements.begin(); i < elements.end(); ++i)
	elements.erase(i);
	*/
}

const mnogestvo_type Mnogestvo::type() const
{
	return _type;	// ����������� ���� ���������
}

bool Mnogestvo::_checkBalance(string & line)
{
	stack<char> braces;
	for (unsigned int i = 1; i < line.length() - 1; ++i)
	{
		if (line[i] == REGULAR_OPEN)
		{
			braces.push(REGULAR_OPEN);
		}
		else if (line[i] == REGULAR_CLOSE)
		{
			if (braces.empty() || (!braces.empty() && braces.top() != REGULAR_OPEN))
				return false;
			else braces.pop();
		}
		else if (line[i] == ORIENTED_OPEN)
		{
			braces.push(ORIENTED_OPEN);
		}
		else if (line[i] == ORIENTED_CLOSE)
		{
			if (braces.empty() || (!braces.empty() && braces.top() != ORIENTED_OPEN))
				return false;
			else braces.pop();
		}
	}
	return braces.empty();
}

Element * Mnogestvo::_getElementPtr(string & line, unsigned int & begin, unsigned int end)
{
	// ��������� ��������� ��������
	// begin, end - ������������ ������� ��� ��������� ����. ��-��
	Mnogestvo * mnogestvo;
	if (line[begin] == REGULAR_OPEN)
	{
		mnogestvo = new Mnogestvo(REGULAR);
	}
	else if (line[begin] == ORIENTED_OPEN)
	{
		mnogestvo = new Mnogestvo(ORIENTED);
	}
	Element * element = NULL;
	if ((line[begin] >= '0' && line[begin] <= '9') || (line[begin] >= 'A' && line[begin] <= 'z'))
	{
		string ch;
		while (line[begin] != ',' && begin < end)
		{
			ch = ch + line[begin];
			++begin;
		}
		++begin;
		element = new Element(SINGLE);
		element->setValue(ch);
	}
	else if (line[begin] == ORIENTED_OPEN)
	{
		unsigned int i = begin;
		int braces = 0;
		while (line[i] != ORIENTED_CLOSE || braces != 1)
		{
			if (line[i] == ORIENTED_OPEN)
				++braces;
			else if (line[i] == ORIENTED_CLOSE)
				--braces;
			++i;
		}
		element = new Element(MNOGESTVO);
		Mnogestvo * mnogestvo;
		mnogestvo = new Mnogestvo(ORIENTED);
		++begin;
		while (begin < i)
			mnogestvo->pushElement(_getElementPtr(line, begin, i));
		element->setValue(mnogestvo);
		begin = i + 2;
	}
	else if (line[begin] == REGULAR_OPEN)
	{
		unsigned int i = begin;
		int braces = 0;
		while (line[i] != REGULAR_CLOSE || braces != 1)
		{
			if (line[i] == REGULAR_OPEN)
				++braces;
			else if (line[i] == REGULAR_CLOSE)
				--braces;
			++i;
		}
		element = new Element(MNOGESTVO);
		Mnogestvo * mnogestvo;
		mnogestvo = new Mnogestvo(REGULAR);
		++begin;
		while (begin < i)
			mnogestvo->pushElement(_getElementPtr(line, begin, i));
		element->setValue(mnogestvo);
		begin = i + 2;
	}
	else
	{
		begin = end;
	}
	return element;
}

void Mnogestvo::pushElement(Element * el)
{
	// ���������� ������ ��-�� �� ���������
	elements.push_back(*el);	// el - ��������� �� ����� ��-�
	isSorted = false;
}

void Mnogestvo::show(int dert = 0)
{	// dert - ������� ������������
	vector<Element>::const_iterator i;
	for (i = elements.begin(); i != elements.end(); ++i)
	{
		for (int d = 0; d <= dert; ++d)
			cout << " ";
		if (i->type() == SINGLE)
		{
			cout << "Element: " << i->value << endl;
		}
		else
		{
			cout << "Mnogestvo (" <<
				(i->mnogestvo->type() == REGULAR ? "regular" : "oriented") <<
				", " << (i->mnogestvo->isSorted ? "sorted" : "unsorted") <<
				"): " << endl;
			i->mnogestvo->show(dert + 1);
		}
	}
}

int Mnogestvo::size()
{
	return elements.size();	// ����������� ������� ���������
}

void Mnogestvo::sort()
{
	if (isSorted)
		return;
	if (type() == REGULAR)
	{
		std::sort(elements.begin(), elements.end());
	}
	else
	{
		vector<Element>::iterator i;	// ����������� ����������
		for (i = elements.begin(); i < elements.end(); ++i)
			if (i->type() == MNOGESTVO)
				i->mnogestvo->sort();
	}
	isSorted = true;
}

string Mnogestvo::toString()
{
	// ����������� ��������� ��� ������
	string mnogestvo = "";
	vector<Element>::iterator i;
	for (i = elements.begin(); i != elements.end(); ++i)
	{
		mnogestvo += i->toString();
		if (i + 1 != elements.end())
			mnogestvo += ',';
	}
	if (type() == REGULAR)
		mnogestvo = (char)REGULAR_OPEN + mnogestvo + (char)REGULAR_CLOSE;
	else mnogestvo = (char)ORIENTED_OPEN + mnogestvo + (char)ORIENTED_CLOSE;
	return mnogestvo;
}

bool Mnogestvo::hasElement(string & elemS)
{
	// �������� �������� �� ����������� � ���������
	vector<Element>::iterator i;	// elemS - ��������� ������������� ��� ������
	for (i = elements.begin(); i < elements.end(); ++i)
		if (i->toString() == elemS)
			return true;
	return false;
}

Element::Element(element_type dez)
{
	// ����������� ��-��
	_type = dez;	// dez - element type
	value = "";
	mnogestvo = NULL;
}

Element::~Element()
{
	/*
	if (_type==Mnogestvo)
	delete mnogestvo;;
	*/
}

void Element::setValue(string & dia)
{
	value = dia;	// dia - ��������� ����.
}

void Element::setValue(Mnogestvo * sif)
{
	// ����� ��-�� �� ���������
	mnogestvo = new Mnogestvo(sif->type());	// sif - ��������������� ��� ���������
	*mnogestvo = *sif;
}

const element_type Element::type() const
{
	return _type;	// ��� ������������� ��������
}

string Element::toString() const
{
	// ������������� ��-�� ����������� ��� ������
	if (type() == SINGLE)
		return value;
	else
		return mnogestvo->toString();
}

bool Element::operator<(const Element & reil) const
{
	// ��������, ����������� ���. �� ��-� ������ ��� ������
	// reil - ����� �� ����. ����������
	if (type() == MNOGESTVO)
		mnogestvo->sort();
	if (reil.type() == MNOGESTVO)
		reil.mnogestvo->sort();
	if (type() == SINGLE && reil.type() == SINGLE)
		return value < reil.value;
	else if (type() == MNOGESTVO && reil.type() == MNOGESTVO)
		return toString() < reil.toString();
	else if (type() == SINGLE && reil.type() == MNOGESTVO)
		return true;
	else return false;
}


Mnogestvo * Operations::symDifference(Mnogestvo * levoe, Mnogestvo * pravoe)
{
	// ���������� ������������� �������� ���������
	levoe->sort();	// levoe & pravoe - ��������� �� ��� ���������
	pravoe->sort();
	vector<string> elements;
	vector<string>::iterator j;
	string result;
	vector<Element>::iterator i;
	string t = "";
	for (i = levoe->elements.begin(); i < levoe->elements.end(); ++i)
	{
		t = i->toString();
		if (!pravoe->hasElement(t))
			elements.push_back(t);
	}
	bool already = false;
	for (i = pravoe->elements.begin(); i < pravoe->elements.end(); ++i)
	{
		t = i->toString();
		if (!levoe->hasElement(t))
		{
			for (j = elements.begin(); j < elements.end(); ++j)
				if (*j == t)
				{
					already = true;
					break;
				}
			if (!already)
				elements.push_back(t);
		}
	}
	result = (char)REGULAR_OPEN;
	for (j = elements.begin(); j < elements.end(); ++j)
		result += *j + ',';
	if (result.length() != 1)
		result = result.substr(0, result.length() - 1);
	result += REGULAR_CLOSE;
	Mnogestvo * mnogestvo = new Mnogestvo(result);
	return mnogestvo;
}

int main()
{
	ifstream in("input.txt");	//������� ����������� ����
	string mnogestvoExpression;
	Operations * psycho = new Operations;
	Mnogestvo * result = new Mnogestvo(REGULAR);
	while (getline(in, mnogestvoExpression))
	{
		unsigned int pos = mnogestvoExpression.find("=");
		if (pos != string::npos)
		{
			mnogestvoExpression = mnogestvoExpression.substr(pos + 1);
			Mnogestvo * mnogestvo = new Mnogestvo(mnogestvoExpression);
			if (!mnogestvo->isCorrect)
			{
				cout << "Nepravilnyi vvod. Exit!" << endl;
				return 0;
			}
			result = psycho->symDifference(result, mnogestvo);
			delete mnogestvo;
		}
	}
	cout << "Rezultat= " << result->toString() << endl;
	_getch();
	return 0;
}