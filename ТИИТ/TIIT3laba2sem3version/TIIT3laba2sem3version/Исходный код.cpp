#include <vector>
#include <iostream>
#include <utility>
#include <string>
#include <algorithm>
#include "Верхний колонтитул.h"
#include <fstream>
#include <set>
#include <string>

using namespace std;


template <typename T>
set<vector<T>> CreateSets(const vector<T>& sets)
{
	set<vector<T>> result;
	for (int i = 0; i < sets.size(); i++)
	{
		vector<T> vect(sets.size());
		fill(vect.begin(), vect.end(), sets[i]);
		for (int j = 0; j < sets.size(); j++)
		{
			for (int k = 0; k < sets.size(); k++)
			{
				if (j == 0 && k == 0) result.insert(vect);

				vect[i] = sets[k];
				sort(vect.begin(), vect.end());
				result.insert(vect);

				vect[j] = sets[k];
				sort(vect.begin(), vect.end());
				result.insert(vect);
			}
		}
	}
	return result;
}


int main()
{
	vector<string> sets;
	ifstream in("tests.txt");
	if (in)
	{
		string line;
		while (getline(in, line))
		{
			sets = tiit::modify(line);
			cout << "Vhodnoe mnojestvo = {" << line << "}" << endl;
			for (const auto& set_ : CreateSets(sets))
			{
				tiit::PrintVector(set_);
				cout << endl;
			}
			cout << endl << endl;
		}
	}
	system("pause");
	return 0;
}


