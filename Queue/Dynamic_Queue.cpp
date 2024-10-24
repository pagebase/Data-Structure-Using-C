#include <stdio.h>
#include <conio.h>
#include <alloc.h>
#include <process.h>

struct node
{
    int info;
    node *next;
}*list;

node* create();
void isempty();
void insert(int);
int remove();
void display();
void main()
{
    int ch,x,z;
    clrscr();
    do
    {
		printf("\n Enter Your Choice=\n");
		printf("\n1:IsEmpty\n");
        printf("\n2:Insert\n");
        printf("\n3:Remove\n");
        printf("\n4:Display\n");
		printf("\n5:Exit\n");
        scanf("%d",&ch);
        switch (ch)
        {   
            case 1:
                isempty();
                break;
        
            case 2:
                printf("\nEnter Insert Val:->\n");
                scanf("%d",&x);
                insert(x);
                break;
                
            case 3:
                z=remove();
                printf("\nRemoved Val:->=%d\n",z);
                break;
                
            case 4:
                display();
                break;
                
            case 5:
                exit(1);             
        }
    } while (ch!=5);
    getch();
}

node* create()
{
	node *z;
	z=(node*)malloc(sizeof(node));
	return(z);
}

void isempty()
{
	node *p;
	p=list;
	if(p==NULL)
	{
		printf("Queue is Empty\n");
	}
	else
	{
		printf("Queue is Not Empty\n");
	}
}

void insert(int x)
{
    node *p,*q;
    p=list;
    if(p==NULL)
    {
        p=create();
        p->info=x;
        p->next=NULL;
        list=p;
    }
    else
    {
        while(p->next!=NULL)
        {
            p=p->next;
        }
        q=create();
        q->info=x;
        q->next=NULL;
        p->next=q;
    }
    printf("Element is Inserted\n");
}

int remove()
{
	int z;
	node *p;
	p=list;
	if (p==NULL)
	{
		printf("\n Queue Underflow");
        return(0);
	}
	else if(p->next==NULL)
	{
		z=p->info;
		free(p);
		list=NULL;
		return(z);
	}
	else
	{
		z=p->info;
		list=p->next;
		free(p);
		return(z);
	}
}

void display()
{
	node *p;
	p=list;
	while(p!=NULL)
	{
		printf("\t%d",p->info);
		p=p->next;
	}
}
