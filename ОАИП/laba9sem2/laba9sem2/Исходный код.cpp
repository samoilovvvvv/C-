#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;


float f(double x) { return (x*x*x + 6 * x *x - 0.02*exp(x) - 14); }  // вычисляемая функция
float df(float x) { return (3 * x*x + 12 * x - 0.02*exp(x)); }       // производная функции

void reshenie()
{
	double x, x1, temp = 0, a = -6, b = 2, h = 0.1, e = 0.0000000001;
	for (x = a; x < b; x += h)
		if (f(x)*f(x + h) < 0) // проверка на существование корня(пересечения графика оси Ох)
		{
			x1 = a;
			while (fabs(x1 - temp) > e)   
			{
				x1 = x - f(x) / df(x);    
				temp = x;
				x = x1;
			}
			cout << "x= " << x1 << "    y= " << f(x1) << endl;
		}

}


int main()
{
	reshenie();
	system("pause");
}

