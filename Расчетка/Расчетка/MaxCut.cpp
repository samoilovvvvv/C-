#include<set>
#include<tuple>
#include<vector>
#include<fstream>
#include<conio.h>
#include<iostream>

using namespace std;

int main()
{
	fstream fin("in5.txt");			
	ofstream fout("out.txt");			
	vector<pair<pair<int, int>, int>> graph;	//������ �������������
	vector<int> value_versh;					//������, ���������� �� ��� ������ �������
	set<int> versh_raz;							//��������� ������, ���������� � ���������� ������a
	int sum_value = 0;							
	int N;										
	fin >> N;									
	int size = N;
	while (size) {
		int first_v;							
		int second_v;							
		int value;								
		fin >> first_v;
		fin >> second_v;
		fin >> value;
		graph.push_back(pair<pair<int, int>, int>(pair<int, int>(first_v, second_v), value));	
		size--;
	}
	value_versh.push_back(0);														
	for (int i = 1, value = 0;; i++, value = 0) {									
		for (int j = 0; j < graph.size(); j++) {
			if (graph[j].first.first == i || graph[j].first.second == i)			
				value += graph[j].second;											
		}
		if (value == 0)	break;															
		value_versh.push_back(value);												
	}
	do {
		int max = 0;
		for (int i = 1; i < value_versh.size(); i++) {
			if (value_versh[i] > value_versh[max]) max = i;								
		}
		if (value_versh[max] > 0) {													
			sum_value += value_versh[max];											
			value_versh[max] = 0;                                                   
			versh_raz.insert(max);													
			for (int i = 0; i < graph.size(); i++) {								
				if (graph[i].first.first == max) {																
					value_versh[graph[i].first.second] -= graph[i].second * 2;		//���� ��� ��������, ������ ��� ������ ����� ������ � ������
				}																	//������ ���, ����� ���������, ������� �� ��������� ������� ������� � ���������
				if (graph[i].first.second == max) {
					value_versh[graph[i].first.first] -= graph[i].second * 2;
				}																	
			}

		}
		else break;
	} while (1);
	fout << sum_value << endl;														
	for (int a : versh_raz)
	{
		for (int i = 0; i < graph.size(); i++)										
		{
			if (graph[i].first.first == a && versh_raz.find(graph[i].first.second) == versh_raz.end())				
				fout << graph[i].first.first << ' ' << graph[i].first.second << ' ' << graph[i].second << endl;		
			if (graph[i].first.second == a && versh_raz.find(graph[i].first.first) == versh_raz.end())				
				fout << graph[i].first.first << ' ' << graph[i].first.second << ' ' << graph[i].second << endl;		
		}
	}
	cout << " Press any key... " << endl;
	_getch();
	return 0;
}