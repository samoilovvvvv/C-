#ifndef lib_h
#define lib_h
#include<iostream>
#include<stdio.h>
using namespace std;

struct comp
{
	int Data;
	comp *next;
};

void push(comp **top, int D);
int pop(comp **top, int i);
void s_delete(comp **top, int N);
void print(comp *top);
#endif