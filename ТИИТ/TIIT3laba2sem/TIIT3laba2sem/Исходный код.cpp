#include <iostream>
#include <string>
#include <vector>

using namespace std;
string str, setName;
vector <string> AllItems, newItem;

void GenNewItem(int n)
{
	int i = 0;
	while (n) {
		if (n & 1)
			newItem.push_back(AllItems[i]);
		i++;
		n >>= 1;
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Введите множество" << endl;
	getline(cin, str);

	int eq = str.find("=");
	setName = str.substr(0, eq);
	str.erase(0, eq + 2);
	str.erase(str.size() - 1, 1);

	int start = 0, opening = 0, closing = 0;
	int size = str.size();
	bool foundCommas = true;

	while (foundCommas) {
		foundCommas = false;
		for (int i = 0; i < str.size(); i++) {
			if (str.substr(i, 1) == "<" || str.substr(i, 1) == "{") 	opening++;
			if (str.substr(i, 1) == ">" || str.substr(i, 1) == "}")		closing++;
			if (str.substr(i, 1) == "," && opening == closing)
			{
				AllItems.push_back(str.substr(0, i));
				str.erase(0, i + 1);
				foundCommas = true;
				opening = 0;
				closing = 0;
				break;
			}
		}
	}
	AllItems.push_back(str);
	cout << "{";

	int r, i, N = AllItems.size();
	r = 1 << N; //Тоже самое что и 2^N
	for (i = 1; i < r; i++) {
		GenNewItem(i);
		if (newItem.size() == 1) {
			cout << "{";
			cout << newItem[0];
			cout << "}";
		}
		if (newItem.size() > 1)
		{
			cout << "{";
			int size = newItem.size();
			for (int j = 0; j < size; j++) {
				cout << newItem[j];
				if (j != size - 1)
					cout << ", ";
			}
			cout << "}";
		}
		newItem.clear();
		if (i != r - 1)
			cout << ", ";
	}
	cout << ", {}}" << endl;
	system("pause");
	return 0;
}