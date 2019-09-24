#include <iostream>
using namespace std;

struct queue
{
	int info;
	queue* next;
	queue* prev;
};

void init(queue**, queue**, int);
queue* add_beg(queue*, int);
queue* add_end(queue*, int);
void view_beg(queue*);
void view_end(queue*);
int iTask1(queue*);
int iTask2(queue*);

int main()
{
	setlocale(LC_ALL, "Rus");
	queue* begin = NULL;
	queue* end = NULL;
	int opt;
	int opt_view = 1;
	while (true)
	{
		if (opt_view == 1)
		{
			view_beg(begin);
		}
		else if (opt_view == 0)
		{
			view_end(end);
		}
		cout << endl << "1.Создать список" << endl <<
			"2.Добавить элементы в список" << endl <<
			"3.Индивидуальное задание" << endl <<
			"4.Изменить способ просмотра. Сейчас ";
		if (opt_view == 1)
		{
			cout << "с начала" << endl;
		}
		else
		{
			cout << "с конца" << endl;
		}
		cout << "5.Выход" << endl << endl;
		cin >> opt;
		cout << endl;
		switch (opt)
		{
		case 1:
			begin = NULL;
			end = NULL;
			init(&begin, &end, rand());
			break;
		case 2:
			if (begin == NULL && end == NULL)
			{
				cout << "Вы не создали список" << endl <<  endl;
				break;
			}
			int size;
			int kod;
			cout << "Введите количество элементов" << endl;
			cin >> size;
			cout << "1.Добавить с начала\n2.Добавить с конца" << endl;
			cout << endl;
			cin >> kod;
			switch (kod)
			{
			case 1:
				for (int i = 0; i < size; i++)
				{
					begin = add_beg(begin, rand());
				}
				break;
			case 2:
				for (int i = 0; i < size; i++)
				{
					end = add_end(end, rand());
				}
				break;
			}
			break;
		case 3:
			if (begin == NULL && end == NULL)
			{
				cout << "Вы не создали список" << endl << endl;
				break;
			}
			cout << "1.Заменить первый элемент\n2.Заменить последний элемент" << endl;
			kod = 0;
			cin >> kod;
			switch (kod)
			{
			case 1:
				begin->info = iTask1(begin);
				break;
			case 2:
				end->info = iTask2(end);
				break;
			}
			break;
		case 4:
			if (begin == end)
			{
				cout << "Добавьте еще элементы в список" << endl << endl;
				break;
			}
			if (opt_view == 1)
			{
				opt_view = 0;
			}
			else
			{
				opt_view = 1;
			}
			break;
		case 5:
			exit(1);
			break;
		}
	}
	system("pause");
	return 0;
}

void init(queue** b, queue** e, int in)
{
	queue *t = new queue;
	t->info = in;
	t->next = NULL;
	if (*b == NULL)
	{
		*b = *e = t;
	}
}

queue* add_beg(queue* v, int in)
{
	queue *t = new queue;
	t->info = in;
	t->next = v;
	t->prev = NULL;
	v->prev = t;
	return t;
}

queue* add_end(queue* v, int in)
{
	queue *t = new queue;
	t->info = in;
	t->next = NULL;
	t->prev = v;
	v->next = t;
	return t;
}

void view_beg(queue* p)
{
	queue* t = p;
	while (t != NULL)
	{
		cout << t->info << endl;
		t = t->next;
	}
}

void view_end(queue* p)
{
	queue* t = p;
	while (t != NULL)
	{
		cout << t->info << endl;
		t = t->prev;
	}
}

int iTask1(queue* a)
{
	int amount = 0, i = 0;
	for (queue *temp = a; temp != NULL; temp = temp->next, i++)
	{
		amount += temp->info;
	}
	return amount / i;
}

int iTask2(queue* a)
{
	int amount = 0, i = 0;
	for (queue *temp = a; temp != NULL; temp = temp->prev, i++)
	{
		amount += temp->info;
	}
	return amount / i;
}