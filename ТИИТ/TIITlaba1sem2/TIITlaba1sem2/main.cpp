#include<iostream>
#include"lib.h"
#include<stdio.h>
using namespace std;

void main()
{
	comp *top = NULL;
	push(&top, 1);
	push(&top, 2);
	push(&top, 3);
	push(&top, 4);
	push(&top, 5);
	print(top);
	cout << endl;
	cout << pop(&top, 1) << endl;
	s_delete(&top, 4);
	print(top);
	cout << endl;
    cout << pop(&top, 2) << endl;
	system("pause");
}