// Title: Singly Linear Linked List
// Date: 30 Aug 2024
#include <stdio.h>
#include <stdlib.h>
struct node
{
	int info;
	node *next;
} *list;
// Function protypes
node *create();
void insBeg(int);
void insEnd(int);
void insBet(int, int); // After which node & what value respectively.
int remBeg();
int remEnd();
int remBet(int); // After which node value?
void display();
void search(int); // To check entered value exist in Node.
void count();
void reverse(); // Reverse node last as first and first as last.
// main function
int main()
{
	int choice, insVal, after, remVal, srcVal;
	do
	{
		printf("\n1.Insert Beginning\n");
		printf("\n2.Insert Ending\n");
		printf("\n3.Insert Between\n");
		printf("\n4.Remove Beginning\n");
		printf("\n5.Remove Ending\n");
		printf("\n6.Remove Between\n");
		printf("\n7.Display\n");
		printf("\n8.Exit\n");
		printf("\n9.search\n");
		printf("\n10.Count\n");
		printf("\n11.Reverse\n");
		printf("\n------------------------------\n");
		printf("\nEnter Your Choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("\nEnter Value to Insert: ");
			scanf("%d", &insVal);
			insBeg(insVal);
			break;
		case 2:
			printf("\nEnter Value to insert: ");
			scanf("%d", &insVal);
			insEnd(insVal);
			break;
		case 3:
			printf("\nAfter whice Node?");
			scanf("%d", &after);
			printf("\nEnter Value to insert: ");
			scanf("%d", &insVal);
			insBet(after, insVal);
			break;
		case 4:
			remVal = remBeg();
			printf("\nRemoved Value: %d", remVal);
			break;
		case 5:
			remVal = remEnd();
			printf("\nRemoved Value: %d", remVal);
			break;
		case 6:
			printf("\nAfter which Node?");
			scanf("%d", &after);
			remVal = remBet(after);
			printf("\nRemoved Value: %d", remVal);
			break;
		case 7:
			display();
			break;
		case 8:
			exit(1);
		case 9:
			printf("Enter Search Value: ");
			scanf("%d", &srcVal);
			search(srcVal);
			break;
		case 10:
			count();
			break;
		case 11:
			reverse();
			break;
		}
	} while (choice != 8);
	return 0;
} // main close
// create function
node *create()
{
	node *z;
	z = (struct node *)malloc(sizeof(struct node));
	return z;
}
// insert beginning function
void insBeg(int x)
{
	node *p, *q;
	p = list;
	if (p == NULL)
	{
		p = create();
		p->info = x;
		p->next = NULL;
		list = p;
	}
	else
	{
		q = create();
		q->info = x;
		q->next = p;
		list = q;
	}
	printf("\nNode is inserted\n");
}
// inset ending function
void insEnd(int x)
{
	node *p, *q;
	p = list;
	if (p == NULL)
	{
		p = create();
		p->info = x;
		p->next = NULL;
		list = p;
	}
	else
	{
		while (p->next != NULL)
		{
			p = p->next;
		}
		q = create();
		q->info = x;
		q->next = NULL;
		p->next = q;
	}
}
// insert between fuction
void insBet(int after, int x)
{
	node *p, *q;
	p = list;
	if (p == NULL || p->next == NULL)
	{
		printf("\nInsert between not possible\n");
	}
	else
	{
		while (p->next != NULL)
		{
			if (p->info == after)
			{
				q = create();
				q->info = x;
				q->next = p->next;
				p->next = q;
			}
			p = p->next;
		}
	}
}
// remove beginning
int remBeg()
{
	int z;
	node *p;
	p = list;
	if (p == NULL)
		printf("\nLinked List is empty\n");
	else if (p->next == NULL)
	{
		z = p->info;
		free(p);
		list = NULL;
		return z;
	}
	else
	{
		z = p->info;
		list = p->next;
		free(p);
		return z;
	}
}
// remove ending
int remEnd()
{
	int z;
	node *p, *temp;
	p = list;
	if (p == NULL)
		printf("\nLinked List is Empty\n");
	else if (p->next == NULL)
	{
		z = p->info;
		free(p);
		list = NULL;
		return z;
	}
	else
	{
		while (p->next->next != NULL)
			p = p->next;
		temp = p->next;
		z = temp->info;
		p->next = NULL;
		free(temp);
		return z;
	}
}
// remove between
int remBet(int after)
{
	int z;
	node *p, *temp;
	p = list;
	if (p == NULL)
		printf("\nLinked List is Empty\n");
	else if (p->next == NULL || p->next->next == NULL)
		printf("\nRemove Between Not Possible\n");
	else
	{
		while (p->next != NULL)
		{
			if (p->info == after)
			{
				temp = p->next;
				z = temp->info;
				p->next = temp->next;
				free(temp);
				return z;
			}
			p = p->next;
		}
	}
}
// display function
void display()
{
	node *p;
	p = list;
	if (p == NULL)
	{
		printf("\nLinked list is empty!\n");
	}
	else
	{
		while (p != NULL)
		{
			printf("%d\t", p->info);
			p = p->next;
		}
	}
}
// search function
void search(int srcVal)
{
	int t = 0;
	node *p;
	p = list;
	while (p != NULL)
	{
		if (p->info == srcVal)
		{
			t = 1;
			break;
		}
		p = p->next;
	}
	if (t == 1)
		printf("Node has been found");
	else
		printf("Node didn't found");
}
// count function
void count()
{
	int count = 0;
	node *p;
	p = list;
	while (p != NULL)
	{
		count++;
		p = p->next;
	}
	printf("Total Node Is: %d", count);
}
// Reverse function
void reverse()
{
	node *t1, *t2, *t3 = NULL;
	t1 = list;
	while (t1 != NULL)
	{
		t2 = t1->next;
		t1->next = t3;
		t3 = t1;
		t1 = t2;
	}
	list = t3;
}