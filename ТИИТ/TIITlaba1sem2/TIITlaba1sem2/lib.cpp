#include<iostream>
#include"lib.h"
#include<stdio.h>
using namespace std;

void push(comp **top, int D)
{
	comp *q;
	q = new comp();
	q->Data = D;
	if (top == NULL)
	{
		*top = q;
	}
	else
	{
		q->next = *top;
		*top = q;
	}
}

int pop(comp **top, int i)
{   
	comp *temp = *top;
	while (temp != 0)
	{
		if (temp->Data == i)
		{
			return(temp->Data);
			temp = temp->next;
		}
	}
}

void s_delete(comp **top, int N)
{
	comp *q = *top;
	comp *prev = NULL;
	while (q != NULL)
	{
		if (q->Data == N)
		{
			if (q == *top)
			{
				*top = q->next;
				free(q);
				q->Data = NULL;
				q->next = NULL;
			}
			else
			{
				prev->next = q->next;
				free(q);
				q->Data = NULL;
				q->next = NULL;
			}
		}
		prev = q;
		q = q->next;
	}
}

void print(comp *top)
{
	comp *q = top;
	while (q)
	{
		cout << q->Data << endl;
		q = q->next;
	}
}