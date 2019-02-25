#include <iostream> 
#include <math.h> 
#include <cstdlib> 
using namespace std;

double phi(double a)
{
	double phi = 0;
	phi = ((pow(a, 2) / 4) + (a / 2) + 1) * exp(a / 2);
	return phi;
}

int fact(int q) 
{
	long double fact = 1;
	for (int i = q; i > 0; i--)
	{
		fact *= i;
	}
	return fact;
}

double funct_sum(double n, double x)
{
	double sum = 0;
	for (double k = 0; k <= n; k++)
	{
		sum += ((pow(k, 2) + 1) / fact(k) * (pow(x / 2, k)));
	}
	return sum;
}

void Out_Rez(double x, double sum, double y)
{
	setlocale(LC_ALL, "Rus");
	cout << "\nПри х= " << x << " S(X)= " << sum << " Y(X)= " << y << " |Y(X)-S(X)|= " << fabs(y - sum) << endl;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	double x, a, b, h, sum, y;
	int i, n, k;
	cout << "Введите a, b, h, n через пробел: "; cin >> a >> b >> h >> n;
	for (x = a; x <= b; x += h)
	{
		y = phi(x);
		sum = funct_sum(n, x);
		Out_Rez(x, y, sum);
	}
	system("pause");
	return 0;
}