#include<iostream>
#include<time.h>
using namespace std;

struct comp
{
	int Data;
	comp *next;
};

void push(comp **top, int D);
void print(comp *top);
int iTask(comp *top);
void sortOne(comp **top);
void sortTwo(comp *top);
void s_delete(comp **top);

int main()
{
	setlocale(LC_ALL, "Rus");
	int kod, n, in, sign;
	comp *top = NULL;
	srand(time(0));
	while (true)
	{
		cout << endl << "1.Создать\n2.Добавить\n3.Просмотреть\n4.Индивидуальное задание\n5.Сортировка первая\n6.Сортировка вторая\n7.EXIT - 0" << endl << endl;
		cin >> kod;
		cout << endl;
		switch (kod)
		{
		case 1:
			top = NULL;
			cout << "Введите количество элементов" << endl;
			cin >> n;
			cout << endl;
			for (int i = 0; i < n; i++)
			{
				in = rand() % 9 + 1;
				sign = rand() % 2 + 1;
				if (sign > 1) in *= -1;
				push(&top, in);
			}
			break;
		case 2:
			if (top == NULL)
			{
				cout << "Вы не создали стэк!" << endl;
				break;
			}
				cout << "Введите число, которое хотите добавить в стэк" << endl;
				n = 0;
				cin >> n;
				push(&top, n);
				break;
		case 3:
			print(top);
			break;
		case 4:
			if (top == NULL)
			{
				cout << "Вы не создали стэк!" << endl;
				break;
			}
			top->Data = iTask(top);
			break;
		case 5:
			if (top == NULL)
			{
				cout << "Вы не ввели элементы в стек!" << endl;
				break;
			}
			push(&top, 1);
			sortOne(&top);
			s_delete(&top);
			break;
		case 6:
			if (top == NULL)
			{
				cout << "Вы не ввели элементы в стек!" << endl;
				break;
			}
		    sortTwo(top);
			break;
		case 0:
			exit(1);
			break;
		}
	}
	system("pause");
	return 0;
}

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

void print(comp *top)
{
	comp *q = top;
	while (q)
	{
		cout << endl << q->Data << endl << endl;
		q = q->next;
	}
}

int iTask(comp *top)
{
	int amount = 0, i = 0;
	for (comp *temp = top; temp != NULL; temp = temp->next, i++)
	{
		amount += temp->Data;
	}
	return amount / i;
}

void sortOne(comp **top)
{
	comp *t = NULL, *t1, *r;
	if ((*top)->next->next == NULL) return;
	do {
		for (t1 = *top; t1->next->next != t; t1 = t1->next)
			if (t1->next->Data  >  t1->next->next->Data){
				r = t1->next->next;
				t1->next->next = r->next;
				r->next = t1->next;
				t1->next = r;
			}
		t = t1->next;
	} while ((*top)->next->next != t);
}

void sortTwo(comp *top)
{
	comp *t = NULL, *t1;
	int r;
	do {
		for (t1 = top; t1->next != t; t1 = t1->next)
			if (t1->Data > t1->next->Data)  {
				r = t1->Data;
				t1->Data = t1->next->Data;
				t1->next->Data = r;
			}
		t = t1;
	} while (top->next != t);
}

void s_delete(comp **top)
{
	comp *q = *top;
	*top = q->next;
	free(q);
}