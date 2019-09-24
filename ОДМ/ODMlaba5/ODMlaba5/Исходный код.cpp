// одм.cpp: определяет точку входа для консольного приложения.
#include <iostream>
#include <vector>
#include <stdio.h>
#include <conio.h>

using namespace std;

struct S
{
	vector <int> X;
	vector <int> Y;
	vector <pair <int, int> > G;
};

void print(S s_cheak)
{
	printf("< {");
	for (vector <int>::iterator i = s_cheak.X.begin(); i < s_cheak.X.end(); i++)
	{
		printf("%i ", *i);
	}
	printf("}, { ");
	for (vector <int>::iterator i = s_cheak.Y.begin(); i < s_cheak.Y.end(); i++)
	{
		printf("%i ", *i);
	}
	printf("}, { ");
	for (vector <pair <int, int> >::iterator i = s_cheak.G.begin(); i < s_cheak.G.end(); i++)
	{
		printf("< %i %i > ", i->first, i->second);
	}
	printf("} >;");
}
bool cheak(int N, int elem, vector <int> kek)
{
	int super_cheak = 0;
	for (int j(0); j < N; j++)
	{
		if (kek[j] == elem)
		{
			super_cheak++;
		}
	}
	if (super_cheak == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
vector <int> set_intersection(vector <int> s_1, vector <int> s_2)
{
	vector <int> s_int;
	for (vector <int>::iterator i = s_1.begin(); i < s_1.end(); i++)
	{
		for (vector <int>::iterator j = s_2.begin(); j < s_2.end(); j++)
		{
			if (*i == *j)
			{
				s_int.push_back(*i);
			}
		}
	}
	return s_int;
}
vector <pair <int, int> > graph_intersection(vector <pair <int, int> > s_1, vector <pair <int, int> > s_2)
{
	vector <pair <int, int> > g_int;
	for (vector <pair <int, int>>::iterator i = s_1.begin(); i < s_1.end(); i++)
	{
		for (vector <pair <int, int>>::iterator j = s_2.begin(); j < s_2.end(); j++)
		{
			if (i->first == j->first && i->second == j->second)
			{
				g_int.push_back(make_pair(i->first, i->second));
			}
		}
	}
	return g_int;
}
S intersection(S s_1, S s_2)
{
	S s_intersection;
	s_intersection.X = set_intersection(s_1.X, s_2.X);
	s_intersection.Y = set_intersection(s_1.Y, s_2.Y);
	s_intersection.G = graph_intersection(s_1.G, s_2.G);
	return s_intersection;
}
vector <int> set_incorporation(vector <int> s_1, vector <int> s_2)
{
	vector <int> s_inc;
	int cheak;
	s_inc = s_1;
	for (vector <int>::iterator i = s_2.begin(); i < s_2.end(); i++)
	{
		cheak = 0;
		for (vector <int>::iterator j = s_inc.begin(); j < s_inc.end(); j++)
		{
			if (*i == *j)
			{
				cheak++;
			}
		}
		if (cheak == 0)
		{
			s_inc.push_back(*i);
		}
	}
	return s_inc;
}
vector <pair <int, int> > graph_incorporation(vector <pair <int, int> > s_1, vector <pair <int, int> > s_2)
{
	vector <pair <int, int> > g_inc;
	int cheak;
	g_inc = s_1;
	for (vector <pair <int, int> >::iterator i = s_2.begin(); i < s_2.end(); i++)
	{
		cheak = 0;
		for (vector <pair <int, int> >::iterator j = g_inc.begin(); j < g_inc.end(); j++)
		{
			if (i->first == j->first && i->second == j->second)
			{
				cheak++;
			}
		}
		if (cheak == 0)
		{
			g_inc.push_back(make_pair(i->first, i->second));
		}
	}
	return g_inc;
}
S incorporation(S s_1, S s_2)
{
	S s_incorporation;
	s_incorporation.X = set_incorporation(s_1.X, s_2.X);
	s_incorporation.Y = set_incorporation(s_1.Y, s_2.Y);
	s_incorporation.G = graph_incorporation(s_1.G, s_2.G);
	return s_incorporation;
}

void сontinuation(S &s)
{
	cout << "< { ";
	for (int i = 0; i < s.X.size(); i++)
	{
		cout << s.X[i] << " ";
	}
	cout << "}, { ";
	for (int i = 0; i < s.Y.size(); i++)
	{
		cout << s.Y[i] << " ";
	}
	cout << "}, { ";
	for (int i = 0; i < s.X.size(); i++)
	{
		for (int j = 0; j < s.Y.size(); j++)
		{
			cout << "<" << s.X[i] << ", " << s.Y[j] << "> ";
		}
	}
	cout << "} >";
}


vector <int> set_difference(vector <int> s_1, vector <int> s_2)
{
	vector <int> s_diff;
	int cheak;
	for (vector <int>::iterator i = s_1.begin(); i < s_1.end(); i++)
	{
		cheak = 0;
		for (vector <int>::iterator j = s_2.begin(); j < s_2.end(); j++)
		{
			if (*i == *j)
			{
				cheak++;
			}
		}
		if (cheak == 0)
		{
			s_diff.push_back(*i);
		}
	}
	return s_diff;
}
vector <pair <int, int> > graph_difference(vector <pair <int, int> > s_1, vector <pair <int, int> > s_2)
{
	vector <pair <int, int> > g_diff;
	int cheak;
	for (vector <pair <int, int> >::iterator i = s_1.begin(); i < s_1.end(); i++)
	{
		cheak = 0;
		for (vector <pair <int, int> >::iterator j = s_2.begin(); j < s_2.end(); j++)
		{
			if (i->first == j->first && i->second == j->second)
			{
				cheak++;
			}
		}
		if (cheak == 0)
		{
			g_diff.push_back(make_pair(i->first, i->second));
		}
	}
	return g_diff;
}
S difference(S s_1, S s_2)
{
	S s_difference;
	s_difference.X = set_difference(s_1.X, s_2.X);
	s_difference.Y = set_difference(s_1.Y, s_2.Y);
	s_difference.G = graph_difference(s_1.G, s_2.G);
	return s_difference;
}
vector <pair <int, int> > graph_inversion(vector <pair <int, int> > s_1)
{
	vector <pair <int, int> > g_inv;
	for (vector <pair <int, int> >::iterator i = s_1.begin(); i < s_1.end(); i++)
	{
		g_inv.push_back(make_pair(i->second, i->first));
	}
	return g_inv;
}
S inversion(S s_1)
{
	S s_inversion;
	s_inversion.X = s_1.Y;
	s_inversion.Y = s_1.X;
	s_inversion.G = graph_inversion(s_1.G);
	return s_inversion;
}
vector <pair <int, int> > graph_composition(vector <pair <int, int> > s_1, vector <pair <int, int> > s_2)
{
	vector <pair <int, int> > g_comp;
	for (vector <pair <int, int> >::iterator i = s_1.begin(); i < s_1.end(); i++)
	{
		for (vector <pair <int, int> >::iterator j = s_2.begin(); j < s_2.end(); j++)
		{
			int cheak = 0;
			if (i->second == j->first)
			{
				for (vector <pair <int, int> >::iterator k = g_comp.begin(); k < g_comp.end(); k++)
				{
					if (i->first == k->first && j->second == k->second)
					{

						cheak++;
					}
				}
				if (cheak == 0)
				{
					g_comp.push_back(make_pair(i->first, j->second));
				}
			}
		}
	}
	return g_comp;
}

void contraction(S &s, vector <int> &A)
{
	pair <int, int> p;
	S result;
	result.X = s.X;
	result.Y = s.Y;
	for (int i = 0; i < A.size(); i++)
	{
		for (int j = 0; j < s.Y.size(); j++)
		{
			p.first = A[i];
			p.second = s.Y[j];
			for (int k = 0; k < s.G.size(); k++)
			{
				if (p == s.G[k])
				{
					result.G.push_back(p);
				}
			}
		}
	}
	print(result);
}


S composition(S s_1, S s_2)
{
	S s_composition;
	s_composition.X = s_1.X;
	s_composition.Y = s_2.Y;
	s_composition.G = graph_composition(s_1.G, s_2.G);
	return s_composition;
}
vector <pair <int, int> > dp(vector <int> s_1, vector <int> s_2)
{
	vector <pair <int, int> > s_dp;
	for (vector <int>::iterator i = s_1.begin(); i < s_1.end(); i++)
	{
		for (vector <int>::iterator j = s_2.begin(); j < s_2.end(); j++)
		{
			s_dp.push_back(make_pair(*i, *j));
		}
	}
	return s_dp;
}
vector <int> pr_1(vector <pair <int, int> > s_1)
{
	vector <int> s_pr_1;
	for (vector <pair <int, int> >::iterator i = s_1.begin(); i < s_1.end(); i++)
	{
		s_pr_1.push_back(i->first);
	}
	return s_pr_1;
}
vector <int> pr_2(vector <pair <int, int> > s_1)
{
	vector <int> s_pr_2;
	for (vector <pair <int, int> >::iterator i = s_1.begin(); i < s_1.end(); i++)
	{
		s_pr_2.push_back(i->second);
	}
	return s_pr_2;
}
void print_set(vector <int> print)
{
	printf(" {");
	for (vector <int>::iterator i = print.begin(); i < print.end(); i++)
	{
		printf(" %i", *i);
	}
	printf(" }");
}
int main()
{
	setlocale(LC_ALL, "Russian");
	S s_1, s_2, s_3, s_4, s_5, s_6, s_7, s_8, s_9, s_10, s_11;
	int N_X, N_Y, N_G, N_W, N_Z, N_P, N_A, N_A1, N_B, N_B1, elem;
	vector <int> A_1, A_4, A1_1, A1_4, B_1, B_4, B1_1, B1_4, A;
	vector <pair <int, int> > A_2, A_3, A1_2, A1_3, B_2, B_3, B1_2, B1_3;
	printf("Введите мощность области отправления Х соответствия А: ");
	scanf_s("%i", &N_X);
	s_1.X.resize(N_X);
	for (int i(0); i < N_X; i++)
	{
		printf("Введите %i-ый элемент области отправления X соответствия А: ", i + 1);
		scanf_s("%i", &elem);
		s_1.X[i] = elem;
	}
	printf("--------------------------------------------------------------------------------");
	printf("Введите мощность области прибытия У соответстивия А: ");
	scanf_s("%i", &N_Y);
	s_1.Y.resize(N_Y);
	for (int i(0); i < N_Y; i++)
	{
		printf("Введите %i-ый элемент области отправления Y: ", i + 1);
		scanf_s("%i", &elem);
		s_1.Y[i] = elem;
	}
	printf("--------------------------------------------------------------------------------");
	printf("Введите мощность графика G соответстивия A: ");
	scanf_s("%i", &N_G);
	s_1.G.resize(N_G);
	for (int i(0); i < N_G; i++)
	{
		bool cheak_1 = true, cheak_2 = true;
		while (cheak_1)
		{
			printf("Введите первую компоненту %i-го кортежа графика G: ", i + 1);
			scanf_s("%i", &elem);
			cheak_1 = cheak(N_X, elem, s_1.X);
			if (cheak_1)
			{
				printf("Значение первого элемента %i-го кортежа не соответствует области отправления!Введите значение ещё раз!\n", i + 1);
			}
			else
			{
				s_1.G[i].first = elem;
			}
		}
		while (cheak_2)
		{
			printf("Введите вторую компоненту %i-го кортежа графика G: ", i + 1);
			scanf_s("%i", &elem);
			cheak_2 = cheak(N_Y, elem, s_1.Y);
			if (cheak_2)
			{
				printf("Значение второго элемента %i-го кортежа не соответствует области отправления!Введите значение ещё раз!\n", i + 1);
			}
			else
			{
				s_1.G[i].second = elem;
			}
		}
	}
	printf("================================================================================");
	printf("Введите мощность области отправления U соответствия B: ");
	scanf_s("%i", &N_W);
	s_2.X.resize(N_W);
	for (int i(0); i < N_W; i++)
	{
		printf("Введите %i-ый элемент области отправления U: ", i + 1);
		scanf_s("%i", &elem);
		s_2.X[i] = elem;
	}
	printf("--------------------------------------------------------------------------------");
	printf("Введите мощность области прибытия V соответстивия B: ");
	scanf_s("%i", &N_Z);
	s_2.Y.resize(N_Z);
	for (int i(0); i < N_Z; i++)
	{
		printf("Введите %i-ый элемент области прибытия V: ", i + 1);
		scanf_s("%i", &elem);
		s_2.Y[i] = elem;
	}
	printf("--------------------------------------------------------------------------------");
	printf("Введите мощность графика F соответстивия B: ");
	scanf_s("%i", &N_P);
	s_2.G.resize(N_P);
	for (int i(0); i < N_P; i++)
	{
		bool cheak_1 = true, cheak_2 = true;
		while (cheak_1)
		{
			printf("Введите первую компоненту %i-го кортежа графика F: ", i + 1);
			scanf_s("%i", &elem);
			cheak_1 = cheak(N_W, elem, s_2.X);
			if (cheak_1)
			{
				printf("Значение первого элемента %i-го кортежа не соответствует области отправления!Введите значение ещё раз!\n", i + 1);
			}
			else
			{
				s_2.G[i].first = elem;
			}
		}
		while (cheak_2)
		{
			printf("Введите вторую компоненту %i-го кортежа графика F: ", i + 1);
			scanf_s("%i", &elem);
			cheak_2 = cheak(N_Z, elem, s_2.Y);
			if (cheak_2)
			{
				printf("Значение второго элемента %i-го кортежа не соответствует области отправления!Введите значение ещё раз!\n", i + 1);
			}
			else
			{
				s_2.G[i].second = elem;
			}
		}
	}
	while (true)
	{
		system("cls");
		printf("А = < { ");
		print(s_1);
		printf("\nВ = < { ");
		print(s_2);
		printf("\n1.Пересечение соответствий A и B.\n2.Объединение соответствий A и B.\n3.Разность соответствий A и B.\n4.Разность соответствий B и A.\n5.Симметрическая разность соответствий A и B.\n6.Инверсия соответствия A.\n7.Инверсия соответствия B.\n8.Композиция соответствий A и B.\n9.Композиция соответствий B и A.\n10.Образ множества M при соответствии A.\n11.Прообраз множества N при соответствии A.\n12.Сужение соответствия A на множестве W.\n13.Продолжение соответствия A\n14.Завершение работы программы.\nВаше действие: ");
		int input;
		scanf_s("%i", &input);
		switch (input)
		{
		case(1) :
			system("cls");
			printf("A = < { ");
			print(s_1);
			printf("\nB = < { ");
			print(s_2);
			s_3 = intersection(s_1, s_2);
			printf("\nПересечение соответствий A и B= < { ");
			print(s_3);
			s_3.X.clear();
			s_3.Y.clear();
			s_3.G.clear();
			_getch();
			break;
		case(2) :
			system("cls");
			printf("A = < { ");
			print(s_1);
			printf("\nB = < { ");
			print(s_2);
			s_4 = incorporation(s_1, s_2);
			printf("\nОбъединение соответствий A и B = < { ");
			print(s_4);
			s_4.X.clear();
			s_4.Y.clear();
			s_4.G.clear();
			_getch();
			break;
		case(3) :
			system("cls");
			printf("A = < { ");
			print(s_1);
			printf("\nB = < { ");
			print(s_2);
			s_5 = difference(s_1, s_2);
			printf("\nРазность соответствий A и B= < { ");
			print(s_5);
			s_5.X.clear();
			s_5.Y.clear();
			s_5.G.clear();
			_getch();
			break;
		case(4) :
			system("cls");
			printf("B = < { ");
			print(s_2);
			printf("\nA = < { ");
			print(s_1);
			s_6 = difference(s_2, s_1);
			printf("\nРазность соответствий B и A = < { ");
			print(s_6);
			s_6.X.clear();
			s_6.Y.clear();
			s_6.G.clear();
			_getch();
			break;
		case(5) :
			system("cls");
			printf("A = < { ");
			print(s_1);
			printf("\nB = < { ");
			print(s_2);
			s_5 = difference(s_1, s_2);
			s_6 = difference(s_2, s_1);
			s_7 = incorporation(s_5, s_6);
			printf("\nCимметрическая разность соответствий B и A= < { ");
			print(s_7);
			s_5.X.clear();
			s_5.Y.clear();
			s_5.G.clear();
			s_6.X.clear();
			s_6.Y.clear();
			s_6.G.clear();
			s_7.X.clear();
			s_7.Y.clear();
			s_7.G.clear();
			_getch();
			break;
		case(6) :
			system("cls");
			printf("A = < { ");
			print(s_1);
			s_8 = inversion(s_1);
			printf("\nИнверсия соответствия A = < { ");
			print(s_8);
			s_8.X.clear();
			s_8.Y.clear();
			s_8.G.clear();
			_getch();
			break;
		case(7) :
			system("cls");
			printf("B = < { ");
			print(s_2);
			s_9 = inversion(s_2);
			printf("\nИнверсия соответствия B = < { ");
			print(s_9);
			s_9.X.clear();
			s_9.Y.clear();
			s_9.G.clear();
			_getch();
			break;
		case(8) :
			system("cls");
			printf("A = < { ");
			print(s_1);
			printf("\nB = < { ");
			print(s_2);
			s_10 = composition(s_1, s_2);
			printf("\nКомпозиция соответствий A и B = < { ");
			print(s_10);
			s_10.X.clear();
			s_10.Y.clear();
			s_10.G.clear();
			_getch();
			break;
		case(9) :
			system("cls");
			printf("B = < { ");
			print(s_2);
			printf("\nA = < { ");
			print(s_1);
			s_11 = composition(s_2, s_1);
			printf("\nКомпозиция соответствий B и A= < { ");
			print(s_11);
			s_11.X.clear();
			s_11.Y.clear();
			s_11.G.clear();
			_getch();
			break;
		case(10) :
			system("cls");
			printf("A = < { ");
			print(s_1);
			printf("\nВведите мощность множества M: ");
			scanf_s("%i", &N_A);
			for (int i(0); i < N_A; i++)
			{
				bool cheak_1 = true;
				while (cheak_1)
				{
					printf("Введите %i-ый элемент множества M: ", i + 1);
					scanf_s("%i", &elem);
					cheak_1 = cheak(N_X, elem, s_1.X);
					if (cheak_1)
					{
						printf("Значение %i-го элемента не соответствует области отправления!Введите значение ещё раз!\n", i + 1);
					}
					else
					{
						A_1.push_back(elem);
					}
				}
			}
			A_2 = dp(A_1, s_1.Y);
			A_3 = graph_intersection(A_2, s_1.G);
			A_4 = pr_2(A_3);
			printf("--------------------------------------------------------------------------------");
			printf("Образ множества M при соответствии A: A(M) = ");
			print_set(A_4);
			A_1.clear();
			A_2.clear();
			A_3.clear();
			A_4.clear();
			_getch();
			break;

		case(11) :
			system("cls");
			printf("Г1 = < { ");
			print(s_1);
			printf("\nВведите мощность множества N: ");
			scanf_s("%i", &N_B);
			for (int i(0); i < N_B; i++)
			{
				bool cheak_1 = true;
				while (cheak_1)
				{
					printf("Введите %i-ый элемент множества N: ", i + 1);
					scanf_s("%i", &elem);
					cheak_1 = cheak(N_Y, elem, s_1.Y);
					if (cheak_1)
					{
						printf("Значение %i-го элемента не соответствует области прибытия!Введите значение ещё раз!\n", i + 1);
					}
					else
					{
						B_1.push_back(elem);
					}
				}
			}
			B_2 = dp(s_1.X, B_1);
			B_3 = graph_intersection(B_2, s_1.G);
			B_4 = pr_2(B_3);
			printf("--------------------------------------------------------------------------------");
			printf("Пробраз множества N при соответствии A: A^-1(N) = ");
			print_set(B_4);
			B_1.clear();
			B_2.clear();
			B_3.clear();
			B_4.clear();
			_getch();
			break;

		case(12) :
			cout << "Введите мощность множества W: " << endl;
			int n;
			cin >> n;
			A.resize(n);
			cout << "Введите элементы множества W:" << endl;
			for (int i = 0; i < n; i++)
			{
				cin >> A[i];
			}
			contraction(s_1, A);
			_getch();
			break;

		case(13) :
			сontinuation(s_1);
			_getch();
			break;

		case(14) :
			system("cls");
			printf("Для завершения работы программы нажмите любую кнопку!");
			s_1.X.clear();
			s_1.Y.clear();
			s_1.G.clear();
			s_2.X.clear();
			s_2.Y.clear();
			s_2.G.clear();
			_getch();
			return 0;
		}
	}
}

