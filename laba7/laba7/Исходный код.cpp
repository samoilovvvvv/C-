#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	int n;
	cout << "¬ведите количество слов" << endl;
	cin >> n;
	string *a = new string[n];
	for (int i = 0; i < n; ++i)
	{
		cout << "¬ведите слово " << i + 1 << endl;
		cin >> a[i];
	}

	/* while (k < st.size())
	{
		if (st[k] == ' ')
		{
			n++;
		}
		if (st[k] != ' ')
		{
			slova[n] = slova[n] + st[k];
		}
		k++;
	} */
	int i;
	string temp;
	 for (i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	} 
	for (int i = 0; i <= 3; i++)
	{
		cout << a[i] << endl;
	} 
    system("pause");
	return 0;
}
