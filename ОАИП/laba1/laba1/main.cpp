#include <iostream>
#include <math.h>
#include <cstdlib>
using namespace std;
int main()
{ setlocale(LC_ALL, "Russian");
float x, z, y, b;
cout << "������� ����� x:" << endl;
cin >> x;
cout << "������� ����� y:" << endl;
cin >> y;
cout << "������� ����� z:" << endl;
cin >> z;
b = pow(y, pow(labs(x), 1. / 3)) + ((pow(cos(y), 3) * labs(x - y) * (1 + (pow(sin(z), 2) / sqrt(x + y)))) / (exp(labs(x - y)) + x / 2));
cout << "������� �������� �����:" << b << endl;
system("pause");
	return 0;

}