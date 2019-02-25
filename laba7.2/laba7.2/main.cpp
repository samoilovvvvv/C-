#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string Give_Word(unsigned);

void Sort_Words(string *, unsigned, unsigned);

void Show_Words(string *, unsigned);

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Введите количество слов " << endl;
	unsigned n;
	cin >> n;
	cin.get();
	string *a = new string[n];
	unsigned max_len = 0;
	for (unsigned u = 0; u < n; ++u)
	{
		string str = Give_Word(u);
		if (str.size() > max_len)
		{
			max_len = str.size();
		}
		a[u] = str;
	}

	Sort_Words(a, n, max_len);

	Show_Words(a, n);
	
	system("pause");
	return 0;
}

string Give_Word(unsigned u)
{
	string str;
	for (;;) // бесконечный цикл, выполняется пока не будет break 
	{
		cout << "Введите слово " << u + 1 << endl;
		getline(cin, str);
		if (str.size() == 0)
		{
			cout << "Ошибка ввода. Повторите ввод слова" << endl;
			str.clear();
			continue;
		}
		bool valid = true;
		for (const char &c : str) // посимвольно проверяет слово на пробел
		{
			if (c == ' ')
			{
				valid = false;
				break;
			}
		}
		if (valid) 
		{
			break;
		}
		else
		{
			cout << "Ошибка ввода. Повторите ввод слова" << endl;
			str.clear();
			continue;
		}
	} 
	return str;
}

void Sort_Words(string *a, unsigned n, unsigned max_len)
{
	for (long long u = max_len - 1; u >= 0; --u)
	{
		auto p = [u](string s1, string s2)
		{
			size_t s1_len = s1.size();
			size_t s2_len = s2.size();
			size_t short_ = (s1_len < s2_len) ? s1_len : s2_len; // содержил длину кратчайшей из строк

			if (u <= short_ - 1) // short_ - 1 индекс последнего символа в коротком слове
			{
				return toupper((unsigned char)s1[u]) < toupper((unsigned char)s2[u]); // сравнивает значения по таблице кодировки ASCII 
			}
			else
			{
				return s1_len < s2_len; /* если длина первого слова больше чем второго,
										то sort меняет их местами, если меньше, то не трогает*/
			}
		};
		sort(a, a + n, p);
	}
}

void Show_Words(string *a, unsigned n)
{
	cout << endl;
	for (unsigned u = 0; u < n; ++u)
	{
		cout << a[u] << endl;
	}
	cout << endl;
}