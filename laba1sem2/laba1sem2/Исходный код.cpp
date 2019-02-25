#include <iostream>
#include <clocale>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
using namespace std;

const int N = 256;

ofstream fout;
ifstream fin;
struct stud
{
	string FIO;
	int god_r, mat, nomer_gr, fiz, inf, chem;
	double sred_b;
};
void zapis1(stud*, int);
void add(stud *, int);
int main()
{
	setlocale(LC_ALL, "Rus");
	stud student[20];
	int nomer, size, g, x,key,count = 0;
	char rezult[1001];
	char rezult1[1001];
	int kod,temp, n, a, i, z;
	char s[N];
	while (true)
	{
		cout << "1.View - 1\n2.Add - 2\n3.Edit - 3\n4.Individual task - 4\n5.EXIT - 5" << endl;
		cin >> kod;
		switch (kod)
		{
		case 1:
			fin.open("zapisi.txt");
			if (fin.peek()==EOF)
			{	
				cout << "Файл пуст. Добавьте информацию в файл." << endl;
				break;
			}
			while (!fin.eof())
			{

				fin.getline(s, N);
				cout << s << endl;
			}
			fin.close();
			break;
		case 2:
			fout.open("zapisi.txt", ios_base::app);
			cout << "Введите количество студентов которых хотите добавить" << endl;
			cin >> n;
			if (n == 0)
			{
				cout << "Попробуйте еще раз" << endl;
				break;
			}
				for (a = 0; a < n; a++)
				{
					count++;
					add(student, a);
				} 
				zapis1(student, count);
			fout.close();
			break;
		case 3:
			fout.open("zapisi.txt", ios_base::trunc);
			cout << "Номер студента данные которого хотите изменить " << endl;
			cin >> z;
			z = z - 1;
			add(student, z);
			zapis1(student, count);
			fout.close();
			break;
		case 4:
			cout << "Введите номер группы" << endl; cin >> key;
			cout << "Студенты группы " << key << " имеющие оценку по информатике 9 и 10" << endl;
			for (int i = 0; i < count; i++)
			{
				if ((student[i].nomer_gr) == key && (student[i].inf) >= 9)
				{
					cout << "1.ФИО: " << student[i].FIO << endl;
					cout << "2.Год рождения: " << student[i].god_r << endl;
				}
			}
			break;
		case 5:
			goto konec;
		default :
			cout << "Выберите один вариант из списка" << endl;
		}
	}
	konec:
	system("pause");
	return 0;
}
void zapis1(stud * arr, int count)
{
	for (int i = 0; i < count; i++)
	{
		fout << "1.ФИО: " << arr[i].FIO << endl;
		fout << "2.Год рождения: " << arr[i].god_r << endl;
		fout << "3.Номер группы: " << arr[i].nomer_gr << endl;
		fout << "4.Оценка по математике: " << arr[i].mat << endl;
		fout << "5.Оценка по физике: " << arr[i].fiz << endl;
		fout << "6.Оценка по информатике: " << arr[i].inf << endl;
		fout << "7.Оценка по химии: " << arr[i].chem << endl;
		fout << "8.Средний балл: " << arr[i].sred_b << endl;
	}
}
void add(stud * arr, int i)
{
	cout << "Введите имя и инициалы " << i + 1 << " студента" << endl;
	getline(cin, arr[i].FIO);
	getline(cin, arr[i].FIO);
	cout << "Введите год рождения " << i + 1 << " студента" << endl;
	cin >> arr[i].god_r;
	cout << "Введите номер группы " << i + 1 << " студента" << endl;
	cin >> arr[i].nomer_gr;
	cout << "Введите оценку по математике " << i + 1 << " студента" << endl;
	cin >> arr[i].mat;
	cout << "Введите оценку по физике " << i + 1 << " студента" << endl;
	cin >> arr[i].fiz;
	cout << "Введите оценку по информатике " << i + 1 << " студента" << endl;
	cin >> arr[i].inf;
	cout << "Введите оценку по химии " << i + 1 << " студента" << endl;
	cin >> arr[i].chem;
	arr[i].sred_b = (arr[i].mat + arr[i].fiz + arr[i].inf + arr[i].chem) / 4.0;
}