#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Rus");
	double x, y, a, b, z, phi;
	int choose;
	cout << "Введите значение z: " << endl;
	cin >> z;
	if (z > 0) x = 1 / pow(z, 2) + 2 * z;
	else  x = 1 - pow(z, 3);
	cout << "Введите значение a: " << endl;
	cin >> a;
	cout << "Введите значение b: " << endl;
	cin >> b;
	cout << "Выберите значение функции phi: " << endl << "1) Phi=2x" << endl << "2) Phi=x^2" << endl << "3) Phi=x/3" << endl;
	cin >> choose;
	switch (choose)
	{
	case 1: phi = 2 * x;
		cout << "Phi=2x" << endl;
		y = ((2.5 * a*exp(-3 * x)) - (4 * b*pow(x, 2))) / (log(fabs(x)) + phi);
		break;
	case 2: phi = pow(x, 2);
		cout << "Phi=x^2" << endl;
		y = ((2.5 * a*exp(-3 * x)) - (4 * b*pow(x, 2))) / (log(fabs(x)) + phi);
		break;
	case 3: phi = x / 3;
		cout << "Phi=x/3" << endl;
		y = ((2.5 * a*exp(-3 * x)) - (4 * b*pow(x, 2))) / (log(fabs(x)) + phi);
		break;
	default: cout << "Некоректный ввод!" << endl; 
	}
	cout << "Значение y = " << y << endl; 
	if (z > 0) cout << "Значение z > 0, поэтому x = 1/(z^2 + 2z)" << endl;
	else cout << "Значение z <= 0, поэтому  х = 1 - z^3" << endl;
	system("pause");
	return 0;
}