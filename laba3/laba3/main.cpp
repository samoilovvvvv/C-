#include <iostream> 
#include <math.h> 
#include <cstdlib> 
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	double x, a, b, h, sum, y;
	int i, n, k;
	long double fact;
	cout << "Введите a, b, h, n через пробел: "; cin >> a >> b >> h >> n;
	for (x = a; x <= b; x += h) 
	{
		y = ((pow(x, 2) / 4) + (x / 2) + 1) * exp(x / 2);
		sum = 0;
		for (k = 0; k <= n; k++) 
		{
			fact = 1;
			for (i = k; i > 0; i--) 
			{
				fact *= i;
			}
			sum += ((pow(k, 2) + 1) / fact) * (pow(x / 2, k));
		}
		cout << "\nПри х= " << x << " S(X)= " << sum << " Y(X)= " << y << " |Y(X)-S(X)|= " << fabs(y - sum) << endl;
	}
	system("pause");
	return 0;
}