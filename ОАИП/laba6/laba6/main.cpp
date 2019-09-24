#include <iostream> 
#include <cstdlib> 
#include <ctime> 
using namespace std;

int operationn(int n, int m, int **arr)
{
	int min_k = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m-1; j++)
		{
			if (j + 2 == m) break;
			if (arr[i][j] < arr[i][j+1] && arr[i][j+1] < arr[i][j + 2])
				min_k += 1;
		}
	}
	return min_k;
}

int rychn(int n, int m, int** arr)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "Введите элемент массива " << i + 1 << "." << j + 1 << endl;
			cin >> arr[i][j];
			cout << endl;
		}
	}
	return **arr;
}

int random(int n, int m, int** arr)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = rand() % 20;
		}
	}
	return **arr;
}

void vivod(int n, int m, int** arr)
{
	cout << "Ваш массив: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}
int main()
{
	setlocale(LC_ALL, "Rus");
	int n, m, operation, min_k;
	cout << "Введите количество строк: "; cin >> n; 
	cout << "Введите количество столбцов: "; cin >> m;
	int **arr = new int*[n];
	
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}

	cout << "Выберите способ задачи массива: " << endl << "1.Ручной" << endl << "2.Рандомный" << endl;
	cin >> operation;
	switch (operation)
	{
	case 1:
	{
		rychn(n, m, arr);
		break;
	}
	case 2:
	{   
		random(n, m, arr);
	break;
	}
	default:
	{
		cout << "Такого варианта нет в списке" << endl;
		system("pause");
	}
	}
	
	vivod(n, m, arr);
	min_k = operationn(n, m, arr);
	cout << endl;
	cout << "Искомое количество элементов матрицы = " << min_k << endl;
	for (int i = 0; i < n; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	system("pause");
	return 0;
}




