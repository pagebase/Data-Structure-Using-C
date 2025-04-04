#include <stdio.h>
#include <conio.h>
#include <alloc.h>
#include <process.h>
struct node
{
	node *prev;
	int info;
	node *next;
} *list;
node *create();
void ins_beg(int);
void ins_end(int);
void ins_bet(int, int);
int rem_beg();
int rem_end();
int rem_bet(int);
void display();
void search(int);
void count();
void reverse();
void main()
{
	clrscr();
	int ch, n, z, af;
	do
	{
		printf("\n enter your choice");
		printf("\n1:insert beg\n2:insert end\n3:insert bet\n4:remove beg\n5:remove end\n6:remove bet\n7:display\n8:search\n9:count\n10:reverse\n11:exit");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("\n insert your value=");
			scanf("%d", &n);
			ins_beg(n);
			break;

		case 2:
			printf("\n insert your value=");
			scanf("%d", &n);
			ins_end(n);
			break;
		case 3:
			printf("\n after which node ?");
			scanf("%d", &af);
			printf("\n insert your value=");
			scanf("%d", &n);
			ins_bet(af, n);
			break;

		case 4:
			z = rem_beg();
			printf("\n rmoved node=%d", z);
			break;

		case 5:
			z = rem_end();
			printf("\n rmoved node=%d", z);
			break;
		case 6:
			printf("\n after which node ?");
			scanf("%d", &af);
			z = rem_bet(af);
			printf("\n removed node=%d", z);
			break;

		case 7:
			display();
			break;
		case 8:
			printf("\n search your node");
			scanf("%d", &n);
			search(n);
			break;
		case 9:
			count();
			break;
		case 10:
			reverse();
			break;
		case 11:
			exit(2);
		}
	} while (ch != 11);
	getch();
}

node *create()
{
	node *z;
	z = (node *)malloc(sizeof(node));
	return (z);
	printf("\n node is created");
}

void ins_beg(int x)
{
	node *p, *q;
	p = list;
	if (p == NULL)
	{
		p = create();
		p->prev = p;
		p->info = x;
		p->next = p;
		list = p;
	}
	else
	{
		while (p->next != list)
		{
			p = p->next;
		}
		q = create();
		q->prev = p;
		q->info = x;
		q->next = p->next;
		p->next->prev = q;
		p->next = q;
		list = q;
	}
	printf("\n node is inserted");
}

void ins_end(int x)
{
	node *p, *q;
	p = list;
	if (p == NULL)
	{
		p = create();
		p->prev = p;
		p->info = x;
		p->next = p;
		list = p;
	}
	else
	{
		while (p->next->next != list)
		{
			p = p->next;
		}
		q = create();
		q->prev = p;
		q->info = x;
		p->next->prev = q;
		q->next = p->next;
		p->next = q;
	}
	printf("\n insert your node");
}

void ins_bet(int af, int x)
{
	node *p, *q;
	p = list;
	if (p == NULL)
	{
		printf("\n node is empty");
	}
	else if (p->prev == p && p->next == p)
	{
		printf("\n insert between not possible");
	}
	else
	{
		while (p->next != list)
		{
			if (p->info == af)
			{

				q = create();
				q->prev = p;
				q->info = x;
				q->next = p->next;
				p->next->prev = q;
				p->next = q;
			}
			p = p->next;
		}
	}
	printf("\n inset your node");
}

int rem_beg()
{
	int z;
	node *p, *temp;
	p = list;
	if (p == NULL)
	{
		printf("\n linked list is empty");
	}
	else if (p->prev == p && p->next == p)
	{
		z = p->info;
		free(p);
		list = NULL;
		return (z);
	}
	else
	{
		while (p->next != list)
		{
			p = p->next;
		}
		temp = p->next;
		z = temp->info;
		p->next = temp->next;
		temp->next->prev = p;
		list = temp->next;
		free(temp);
		return (z);
	}
	printf("\n node is removed");
}

int rem_end()
{
	int z;
	node *p, *temp;
	p = list;
	if (p == NULL)
	{
		printf("\n linked list is empty");
	}
	else if (p->prev == p && p->next == p)
	{
		z = p->info;
		list = NULL;
		free(p);
		return (z);
	}
	else
	{
		while (p->next->next != list)
		{
			p = p->next;
		}
		temp = p->next;
		z = temp->info;
		p->next = temp->next;
		temp->next->prev = p;
		free(temp);
		return (z);
	}
	printf("\n node is removed");
}

int rem_bet(int af)
{
	int z;
	node *p, *temp;
	p = list;
	if (p == NULL)
	{
		printf("\n linked list is empty");
	}
	else if ((p->prev == list && p->next == p) || (p->prev == p->next && p->next->next == p))
	{
		printf("\n inset between not possible");
	}
	else
	{
		while (p->next != list)
		{
			if (p->info == af)
			{
				temp = p->next;
				z = temp->info;
				p->next = temp->next;
				temp->next->prev = p;
				free(temp);
				return (z);
			}
			p = p->next;
		}
	}
	printf("\n removed node");
}

void display()
{
	node *p;
	p = list;
	do
	{
		printf("\t %d", p->info);
		p = p->next;
	} while (p != list);
}

void search(int srch)
{
	int t = 0;
	node *p;
	p = list;
	do

	{
		if (p->info == srch)
		{
			t = 1;
			break;
		}
		p = p->next;
	} while (p != NULL);
	if (t == 1)
	{
		printf("\n node is found");
	}
	else
	{
		printf("\n node is not found");
	}
}

void count()
{
	int cnt = 0;
	node *p;
	p = list;
	if (p == NULL)
	{
		cnt = 0;
	}
	else
	{
		do
		{
			cnt++;
			p = p->next;
		} while (p != list);
	}
	printf("total node=%d", cnt);
}

void reverse()
{
	node *t1, *t2, *t3 = list;
	t1 = list;
	do
	{
		t2 = t1->next;
		t1->next = t3;
		t1->prev = t2;
		t3 = t1;
		t1 = t2;
	} while (t1 != list);
	list = t3;
	t1->next = t3;
}
