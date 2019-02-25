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
				cout << "���� ����. �������� ���������� � ����." << endl;
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
			cout << "������� ���������� ��������� ������� ������ ��������" << endl;
			cin >> n;
			if (n == 0)
			{
				cout << "���������� ��� ���" << endl;
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
			cout << "����� �������� ������ �������� ������ �������� " << endl;
			cin >> z;
			z = z - 1;
			add(student, z);
			zapis1(student, count);
			fout.close();
			break;
		case 4:
			cout << "������� ����� ������" << endl; cin >> key;
			cout << "�������� ������ " << key << " ������� ������ �� ����������� 9 � 10" << endl;
			for (int i = 0; i < count; i++)
			{
				if ((student[i].nomer_gr) == key && (student[i].inf) >= 9)
				{
					cout << "1.���: " << student[i].FIO << endl;
					cout << "2.��� ��������: " << student[i].god_r << endl;
				}
			}
			break;
		case 5:
			goto konec;
		default :
			cout << "�������� ���� ������� �� ������" << endl;
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
		fout << "1.���: " << arr[i].FIO << endl;
		fout << "2.��� ��������: " << arr[i].god_r << endl;
		fout << "3.����� ������: " << arr[i].nomer_gr << endl;
		fout << "4.������ �� ����������: " << arr[i].mat << endl;
		fout << "5.������ �� ������: " << arr[i].fiz << endl;
		fout << "6.������ �� �����������: " << arr[i].inf << endl;
		fout << "7.������ �� �����: " << arr[i].chem << endl;
		fout << "8.������� ����: " << arr[i].sred_b << endl;
	}
}
void add(stud * arr, int i)
{
	cout << "������� ��� � �������� " << i + 1 << " ��������" << endl;
	getline(cin, arr[i].FIO);
	getline(cin, arr[i].FIO);
	cout << "������� ��� �������� " << i + 1 << " ��������" << endl;
	cin >> arr[i].god_r;
	cout << "������� ����� ������ " << i + 1 << " ��������" << endl;
	cin >> arr[i].nomer_gr;
	cout << "������� ������ �� ���������� " << i + 1 << " ��������" << endl;
	cin >> arr[i].mat;
	cout << "������� ������ �� ������ " << i + 1 << " ��������" << endl;
	cin >> arr[i].fiz;
	cout << "������� ������ �� ����������� " << i + 1 << " ��������" << endl;
	cin >> arr[i].inf;
	cout << "������� ������ �� ����� " << i + 1 << " ��������" << endl;
	cin >> arr[i].chem;
	arr[i].sred_b = (arr[i].mat + arr[i].fiz + arr[i].inf + arr[i].chem) / 4.0;
}