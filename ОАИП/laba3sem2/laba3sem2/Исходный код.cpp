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
	cout << "������� ����� M " << endl;
	cin >> M;
	cout << "������� ����� N " << endl;
	cin >> N;
	if (M==N)
	{
		cout << "��� ����� " << M << " � " << N << ": " << N << endl;
		system("pause");
		return 0;
	}
	if (M % N==0)
	{
		cout << "��� ����� " << M << " � " << N << ": " << N << endl;
		system("pause");
		return 0;
	}
	if (N % M == 0)
	{
		cout << "��� ����� " << M << " � " << N << ": " << M << endl;
		system("pause");
		return 0;
	}
	if (N % M != 0)
	{
		cout << "1.�����������" << endl;
		cout << "2.�������" << endl;
		cin >> kod;
		switch (kod)
		{
		case 1:
			cout << "��� ����� " << M << " � " << N << ": " << NODR(M, N) << endl;
			break;
		case 2:
			cout << "��� ����� " << M << " � " << N << ": " << NOD(M, N) << endl;
			break;
		}
	}
	system("pause");
	return 0;
}