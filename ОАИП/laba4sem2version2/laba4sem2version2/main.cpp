#include<iostream>
#include<fstream>
#include<string>
using namespace std;

const int N = 256;

ofstream fout("text.dat", ios_base::binary | ios_base::app | ios_base::out);
ifstream fin("text.dat", ios_base::binary);

struct stud
{
	string FIO, adres;
	int n_g, mat, fiz;
	double s_b;
};

void Sort_One(string *a, int size);
void Sort_Two(string *a, int begin, int end);
void Sort_Struct(stud *a, int size);
int search(stud *a, int left, int right, string key);

int main()
{
	setlocale(LC_ALL, "Rus");
	int kod, n = 0, count, st, kod1;
	stud student[20];
	string FIO[20], key2;
	if (fin.peek() == EOF)
	{
		cout << "Файл пуст! Введите информацию в файл!" << endl;
	}
	else
	{
		while (!fin.eof())
		{
			fin.read((char*)&student[n], sizeof(student[n]));
			n++;
		}
	}
	fin.close();
	while (1)
	{
		cout << endl <<  "1.Просмотр - 1\n2.Добавление - 2\n3.Линейный поиск - 3\n4.Бинарный поиск - 4\n5.EXIT - 0" << endl << endl;
		cin >> kod;
		cout << endl;
		switch (kod)
		{
		case 1:
			for (int i = 0; i < n - 1; i++)
			{
				cout << student[i].FIO << endl;
				cout << student[i].adres << endl;
				cout << student[i].n_g << endl;
				cout << student[i].mat << endl;
				cout << student[i].fiz << endl;
				cout << student[i].s_b << endl;
				cout << endl;
			}
			break;
		case 2:
			cout << "Введите имя и инициалы студента(пример: Samoilov I A)" << endl;
			cin >> student[n].FIO;
			cout <<  "Адрес студента(пример: Minsk, Moscow, Kiev, London, Brest)" << endl;
			cin >> student[n].adres;
			cout << "Введите номер группы студента" << endl;
			cin >> student[n].n_g;
			cout <<"Введите оценку по математике студента" << endl;
			cin >> student[n].mat;
			cout << "Введите оценку по физике студента" << endl;
			cin >> student[n].fiz;
			student[n].s_b = (student[n].mat + student[n].fiz) / 2.0;
			fout.write((char*)&student[n], sizeof(student[n]));
			fout.close();
			n = 0;
			fin.open("text.dat", ios_base::binary);
			if (!fin.is_open())
			{
				cout << "Ошибка открытия файла!" << endl;
			}
			else
			{
				while (!fin.eof())
				{
					fin.read((char*)&student[n], sizeof(student[n]));
					n++;
				}
			}
			fin.close();
			break;
		case 3:
			st = 0;
			count = 0;
			for (int i = 0; i < n - 1; i++)
			{
				if (student[i].s_b >= 8.5 && student[i].adres == "Minsk")
				{
					count++;
					FIO[st] = student[i].FIO;
					st++;
				}
			}
			cout << "Количество студентов из Минска с баллом выше 8.5 равно " << count << endl << endl;
			cout << "1.Прямая сортировка - 1\n2.QuickSort - 2" << endl;
			cin >> kod1;
			cout << endl;
			switch (kod1)
			{
			case 1:
				Sort_One(FIO, st);
				break;
			case 2:
				Sort_Two(FIO, 0, st - 1);
				for (int i = 0; i < st; i++)
				{
					cout << FIO[i] << endl;
					cout << endl;
				}
				break;
			}
			break;
		case 4:
			Sort_Struct(student, n - 1);
			cout << "Введите Фамилию и инициалы студента, которого хотите найти(пример: Samoilov I A)" << endl;
			cout << endl;
			cin >> key2;
			cout << endl;
			cout << student[search(student, 0, n - 1, key2)].FIO << endl;
			cout << student[search(student, 0, n - 1, key2)].adres << endl;
			cout << student[search(student, 0, n - 1, key2)].n_g << endl;
			cout << student[search(student, 0, n - 1, key2)].mat << endl;
			cout << student[search(student, 0, n - 1, key2)].fiz << endl;
			cout << student[search(student, 0, n - 1, key2)].s_b << endl;
			cout << endl;
			break;
		case 0:
			exit(0);
			break;
		default:
			cout << "Выберите номер из списка!" << endl;
		}
	}
	system("pause");
	return 0;
}

void Sort_One(string *a, int size)
{
	string temp;
	int min;
	for (int i = 0; i < size - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (a[min] > a[j])
			{
				min = j;
			}
		}
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << endl;
		cout << endl;
	}
}

void Sort_Two(string *a, int begin, int end)
{
	int left = begin;
	int right = end;
	string p, temp;
	p = a[(left + right) / 2];
	do
	{
		while (a[left] < p) left++;
		while (a[right] > p) right--;

		if (left <= right)
		{
			temp = a[left];
			a[left] = a[right];
			a[right] = temp;
			left++;
			right--;
		}
	} while (left <= right);
	if (begin < right)
	{
		Sort_Two(a, begin, right);
	}
	if (left < end)
	{
		Sort_Two(a, left, end);
	}
}

void Sort_Struct(stud *a, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = size - 1; j > i; j--)
		{
			if (a[j - 1].FIO > a[j].FIO)
			{
				stud temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;
			}
		}
	}
}

int search(stud *a, int left, int right, string key)
{
	int middle = 0;
	while (1)
	{
		middle = (left + right) / 2;
		if (key < a[middle].FIO) right = middle - 1;

		else if (key > a[middle].FIO) left = middle + 1;

		if (key == a[middle].FIO) return middle;

		if (left > right) return -1;
	}
	return 0;
}