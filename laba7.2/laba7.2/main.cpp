#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string Give_Word(unsigned);

void Sort_Words(string *, unsigned, unsigned);

void Show_Words(string *, unsigned);

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "������� ���������� ���� " << endl;
	unsigned n;
	cin >> n;
	cin.get();
	string *a = new string[n];
	unsigned max_len = 0;
	for (unsigned u = 0; u < n; ++u)
	{
		string str = Give_Word(u);
		if (str.size() > max_len)
		{
			max_len = str.size();
		}
		a[u] = str;
	}

	Sort_Words(a, n, max_len);

	Show_Words(a, n);
	
	system("pause");
	return 0;
}

string Give_Word(unsigned u)
{
	string str;
	for (;;) // ����������� ����, ����������� ���� �� ����� break 
	{
		cout << "������� ����� " << u + 1 << endl;
		getline(cin, str);
		if (str.size() == 0)
		{
			cout << "������ �����. ��������� ���� �����" << endl;
			str.clear();
			continue;
		}
		bool valid = true;
		for (const char &c : str) // ����������� ��������� ����� �� ������
		{
			if (c == ' ')
			{
				valid = false;
				break;
			}
		}
		if (valid) 
		{
			break;
		}
		else
		{
			cout << "������ �����. ��������� ���� �����" << endl;
			str.clear();
			continue;
		}
	} 
	return str;
}

void Sort_Words(string *a, unsigned n, unsigned max_len)
{
	for (long long u = max_len - 1; u >= 0; --u)
	{
		auto p = [u](string s1, string s2)
		{
			size_t s1_len = s1.size();
			size_t s2_len = s2.size();
			size_t short_ = (s1_len < s2_len) ? s1_len : s2_len; // �������� ����� ���������� �� �����

			if (u <= short_ - 1) // short_ - 1 ������ ���������� ������� � �������� �����
			{
				return toupper((unsigned char)s1[u]) < toupper((unsigned char)s2[u]); // ���������� �������� �� ������� ��������� ASCII 
			}
			else
			{
				return s1_len < s2_len; /* ���� ����� ������� ����� ������ ��� �������,
										�� sort ������ �� �������, ���� ������, �� �� �������*/
			}
		};
		sort(a, a + n, p);
	}
}

void Show_Words(string *a, unsigned n)
{
	cout << endl;
	for (unsigned u = 0; u < n; ++u)
	{
		cout << a[u] << endl;
	}
	cout << endl;
}