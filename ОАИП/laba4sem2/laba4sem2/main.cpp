#include <iostream>
#include <clocale>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
using namespace std;

ofstream fout;
ifstream fin;

const int N = 256;

struct stud
{
	string FIO, adres;
	int mat, nomer_gr, fiz, inf, chem;
	double sred_b;
};

int search(stud *a, int left, int right, string key);
void Sort_Struct(stud *a, int size);
void Sort_Two(string *a, int begin, int end);
void Sort_One(string *a, int size);
void zapis1(stud*, int);
void add(stud *, int);

int main()
{
	setlocale(LC_ALL, "Rus");
	stud z[2], y;
	int n;
	int count = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		add(z, count);
		count++;
	}
	fout.open("text.dat", ios::binary);
	fout.write((char*)&z[1], sizeof(z[1]));
	fout.close();
	fin.open("text.dat", ios::binary);
	fin.read((char*)&y, sizeof(y));
	cout << y.FIO << endl<< y.adres << endl << y.mat << endl;
	system("pause");
	return 0;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	stud student[20], sstudent[20];
	int  st = 0, size, count = 0, min = 0,  count1 = 0, count2 = 1, count_kolvo_indiv = 0;
	int kod, a, kolvo = 0, kolvo_indiv = 0, temp, n, kod1;
	char s[N];
	string str, FIO[N], key3;
	while (true)
	{
		cout << "1.Просмотреть - 1\n2.Добавить - 2\n3.Линейный поиск - 3\n4.Бинарный поиск - 4\n5.EXIT - 0" << endl;
		cout << endl;
		cin >> kod;
		cout << endl;
		switch (kod)
		{
		case 1:
			fin.open("zapisi.txt");
			if (!fin.is_open())
			{
				cout << "Ошибка открытия файла! Добавьте информацию в файл" << endl;
			}
			else
			{
				if (fin.peek() == EOF)
				{
					cout << "Файл пуст. Добавьте информацию в файл." << endl;
					break;
				}
				while (!fin.eof())
				{

					fin.getline(s, N);
					cout << s << endl;
				}
			}
			fin.close();
			break; 
		    fin.read((char*)&sstudent[0], sizeof(sstudent[0]));
			fin.close();
			cout << sstudent[0].FIO << endl << sstudent[0].adres << endl << sstudent[0].mat << endl;
			break;
		case 2:
			cout << "Введите количество студентов которых хотите добавить" << endl;
			cin >> n;
			if (n == 0)
			{
				cout << "Попробуйте еще раз" << endl;
				break;
			}
			for (a = 0; a < n; a++)
			{
				count;
				add(student, count);
				fout.write((char*)&student[count], sizeof(student[count]));
				count++;
			}
			fout.close();
			break;
		case 3:
			fin.open("zapisi.txt");
			if (!fin.is_open())
			{
				cout << "Ошибка открытия файла!" << endl;
				break;
			}
			else
			{
				if (fin.peek() == EOF)
				{
					cout << "Файл пуст!" << endl;
				}
				else
				{
					int j = 1, k = 0, i = 0;
					string temp;
					while (!fin.eof())
					{
						while (fin)
						{
							if (j == 1 + k)
							{
								getline(fin, student[i].FIO);	
								count1++;
								kolvo = count1 - 1;
							}
							if (j == 2 + k)
							{
								getline(fin, student[i].adres);
								count1++;
								kolvo = count1 - 1;
							}
							if (j == 3 + k)
							{
								getline(fin, temp);
								student[i].nomer_gr = stoi(temp);
							}
							if (j == 4 + k)
							{
								getline(fin, temp);
								student[i].mat = stoi(temp);
							}
							if (j == 5 + k)
							{
								getline(fin, temp);
								student[i].fiz = stoi(temp);
							}
							if (j == 6 + k)
							{
								getline(fin, temp);
								student[i].sred_b = stoi(temp);
							}
							if (j == 7 + k)
							{
								getline(fin, temp);
								cout << temp << endl;
								j++;
								break;
							}
							j++;
						}
						k += 7;
						i++;
					}

				}
			}
			fin.close();
			kolvo_indiv = 0;
			st = 0;
			for (int i = 0; i < kolvo; i++)
			{
				if ((student[i].sred_b) >= 8.5 && (student[i].adres) == "Minsk")
				{
					FIO[st] = "";
					FIO[st] = student[i].FIO;
					kolvo_indiv++;
					st++;
				}

			}
			cout << "Количество студнтов из города Минск со средним баллом больше 8.5: " << kolvo_indiv << endl;
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
			fin.open("zapisi.txt");
			if (!fin.is_open())
			{
				cout << "Ошибка открытия файла!" << endl;
				break;
			}
			else
			{
				if (fin.peek() == EOF)
				{
					cout << "Файл пуст!" << endl;
				}
				else
				{
					int j = 1, k = 0, i = 0;
					string temp;
					while (!fin.eof())
					{
						while (fin)
						{
							if (j == 1 + k)
							{
								getline(fin, student[i].FIO);
								count1++;
								kolvo = count1 - 1;
							}
							if (j == 2 + k)
							{
								getline(fin, student[i].adres);
							}
							if (j == 3 + k)
							{
								getline(fin, temp);
								student[i].nomer_gr = stoi(temp);
							}
							if (j == 4 + k)
							{
								getline(fin, temp);
								student[i].mat = stoi(temp);
							}
							if (j == 5 + k)
							{
								getline(fin, temp);
								student[i].fiz = stoi(temp);
							}
							if (j == 6 + k)
							{
								getline(fin, temp);
								student[i].sred_b = stoi(temp);
							}
							if (j == 7 + k)
							{
								getline(fin, temp);
								cout << temp << endl;
								j++;
								break;
							}
							j++;
						}
						k += 7;
						i++;
					}

				}
			}
			fin.close();
			Sort_Struct(student, kolvo);
			cout << "Введите Фамилию и инициалы студента, которого хотите найти(пример: Samoilov I A)" << endl; 
			cout << endl;
			getline(cin, key3);
			getline(cin, key3);
			cout << endl;
			for (int i = 0; i < kolvo; i++)
			{
				if (key3 == student[i].FIO)
				{
					cout << student[search(student, 0, kolvo, key3)].FIO << endl;
					cout << student[search(student, 0, kolvo, key3)].adres << endl;
					cout << student[search(student, 0, kolvo, key3)].nomer_gr << endl;
					cout << student[search(student, 0, kolvo, key3)].mat << endl;
					cout << student[search(student, 0, kolvo, key3)].fiz << endl;
					cout << student[search(student, 0, kolvo, key3)].sred_b << endl;
					cout << endl;
					goto metka;
				}
			}
			cout << "Такого студента в списке нет!" << endl;
			cout << endl;
			metka:
			break;
		case 0:
			goto konec;
		default:
			cout << "Выберите один вариант из списка" << endl;
		}
	}
konec:
	system("pause");
	return 0;
}
void zapis1(stud * arr, int i)
{
	fout.write((char*)&arr[i], sizeof(arr[i]));
}
void add(stud * arr, int i)
{
	cout << "Введите имя и инициалы " << i + 1 << " студента(пример: Samoilov I A)" << endl;
	getline(cin, arr[i].FIO);
	getline(cin, arr[i].FIO);
	cout << "Адрес " << i + 1 << " студента(пример: Minsk, Moscow, Kiev, London, Brest)" << endl;
	getline(cin, arr[i].adres);
	cout << "Введите номер группы " << i + 1 << " студента" << endl;
	cin >> arr[i].nomer_gr;
	cout << "Введите оценку по математике " << i + 1 << " студента" << endl;
	cin >> arr[i].mat;
	cout << "Введите оценку по физике " << i + 1 << " студента" << endl;
	cin >> arr[i].fiz;
	arr[i].sred_b = (arr[i].mat + arr[i].fiz) / 2.0;
}
void Sort_One(string *a, int size)
{
	const char *CFIO[N];
	for (int i = 0; i < size; i++)
	{
		CFIO[i] = a[i].c_str();
	}
	string temp;
	int min, i;
	const char * ctemp;
	ctemp = temp.c_str();
	for (int i = 0; i < size - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (strcmp(CFIO[min], CFIO[j]) > 0)
			{
				min = j;
			}
		}
		ctemp = CFIO[i];
		CFIO[i] = CFIO[min];
		CFIO[min] = ctemp;
	}
	for (int i = 0; i < size; i++)
	{
		cout << CFIO[i] << endl;
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
	const char *CFIO[N];
	const char *Ckey;
	Ckey = key.c_str();
	for (int i = 0; i < right; i++)
	{
		CFIO[i] = a[i].FIO.c_str();
	}
	int middle = 0;
	while (1)
	{
		middle = (left + right) / 2;
		if (strcmp(Ckey, CFIO[middle]) < 0) right = middle - 1;

		else if (strcmp(Ckey, CFIO[middle]) > 0) left = middle + 1;

		if ((strcmp(Ckey, CFIO[middle]) == 0)) return middle;

		if (left > right) return -1;
	}
	return 0;
} 