#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int array_operations(int i, int n, int a[])
{
	int min_e = a[0];
	int min_i = 0;
	for (i = 1; i < n; i++)
	{
		if (a[i] < min_e)
		{
			min_e = a[i];
			min_i = i;
		}
	}
	cout << "Минимальное значение массива = " << min_e << endl;
	int b = 0;
	for (i = min_i + 1; i < n; i++)
	{
		b += a[i];
	}
	cout << "Сумма= " << b << endl;
	return 0;
}

int array(int i, int n, int a[])
{
	cout << "Ваш массив : ";
	for (i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}

int rychn(int i, int n, int a[])
{
	for (i = 0; i < n; i++)
	{
		cout << "[ " << i << " ]" << " :";
		cin >> a[i];
	}
	return a[i];
}

int random(int i, int n, int a[])
{
	srand(time(NULL));
	for (i = 0; i < n; i++)
	{
		a[i] = rand() % 20;
		cout << "[ " << i << " ]" << " :" << a[i] << endl;
	}
	return a[i];
}
int main()
{
	setlocale(LC_ALL, "Rus");
	int i = 0, n;
	cout << "Введите размер массива: "; cin >> n;
	int *a = new int[n];
	int operation;
	cout << "Выберите способ задачи массива: " << endl << "1.Ручной" << endl << "2.Рандомный" << endl; 
	cin >>  operation;
	switch (operation)
	{
	case 1:
	{
		rychn(i, n, a);
		break;
	}
	case 2:
	{   random(i, n, a);
		break;
	}
	default:
	{
		cout << "Такого варианта нет в списке" << endl;
		system("pause");
	}
	}
	array(i, n, a);
	array_operations(i, n, a);
	delete [] a;
	system("pause");
	return 0;
}