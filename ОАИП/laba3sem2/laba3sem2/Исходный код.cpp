#include <iostream>
using namespace std;

int NOD(int a, int b)
{
	while (a != b)
	{
		if (a > b)
		{
			a = a - b;
		}
		else
		{
			b = b - a;
		}
	}
	return b;
}

int NODR(int a, int b)
{
	if (a)
	{   
			return NODR(b%a, a);
	}
	else
	{
		return b;
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int M, N, kod;
	cout << "Введите число M " << endl;
	cin >> M;
	cout << "Введите число N " << endl;
	cin >> N;
	if (M==N)
	{
		cout << "НОД чисел " << M << " и " << N << ": " << N << endl;
		system("pause");
		return 0;
	}
	if (M % N==0)
	{
		cout << "НОД чисел " << M << " и " << N << ": " << N << endl;
		system("pause");
		return 0;
	}
	if (N % M == 0)
	{
		cout << "НОД чисел " << M << " и " << N << ": " << M << endl;
		system("pause");
		return 0;
	}
	if (N % M != 0)
	{
		cout << "1.Рекурсивный" << endl;
		cout << "2.Обычный" << endl;
		cin >> kod;
		switch (kod)
		{
		case 1:
			cout << "НОД чисел " << M << " и " << N << ": " << NODR(M, N) << endl;
			break;
		case 2:
			cout << "НОД чисел " << M << " и " << N << ": " << NOD(M, N) << endl;
			break;
		}
	}
	system("pause");
	return 0;
}