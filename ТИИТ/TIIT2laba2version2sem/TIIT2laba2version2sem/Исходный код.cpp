#include <stdio.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
using namespace std;

fstream fin;
ofstream fout;


const int MAX = 1000;
const int INF = 0x3F3F3F3F;
int g[MAX][MAX];
int n;

void input(void) {
	vector<int> digits(3, 0);
	int i1;
	int digit;
	fin.open("input.txt");
	string str;
	getline(fin, str);
	stringstream ss;
	ss << str;
	while (ss >> digit) {
		n = digit;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				g[i][j] = 0;                         /*
													 заполняем главную диагональ нулями и все остальное бесконечностью*/
			}
			else {
				g[i][j] = INF;
			}
		}
	}

	while (!fin.eof()) {                                 /*заполняем 
														 матрицу
														 смеежности*/
		i1 = 0;
		getline(fin, str);
		stringstream ss;
		ss << str;
		while (ss >> digit) {
			digits[i1] = digit;
			i1++;
		}
		g[digits[0] - 1][digits[1] - 1] = digits[2];
		g[digits[1] - 1][digits[0] - 1] = digits[2];                 
	}
	fin.close();
}

void floyd(void)
{
	int i, j, k;
	for (k = 0; k < n; k++)
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)                           // заполняем МС по алгоритму Флойда
				if (g[i][k] + g[k][j] < g[i][j]) {
					g[i][j] = g[i][k] + g[k][j];
					//cout << g[i][j] << endl;
				}
}

int main() {
	int diam = 0, max; // диаметр графа
	input();
	floyd();

	for (int i = 0; i < n; i++)
	{                                                   // ищем максимальное расстояние в новой МС
		max = 0;
		for (int j = 0; j < n; j++)
			if (g[i][j] > max) max = g[i][j];
		if (max > diam) diam = max;
	}
	fout.open("output.txt");
	fout << diam;
	fout.close();
	return 0;
}
