#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<process.h>
struct node
{
    int info;
    node *next;
}*list;
//Function protypes
node* create();
void insBeg(int);
void insEnd(int);
void insBet(int, int);
int remBeg();
int remEnd();
int remBet(int);
void display();
//main function
void main()
{
    int choice, insVal, af, z;
    clrscr();
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
        printf("\nEnter Your Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter Value to Insert: ");
                scanf("%d",&insVal);
                insBeg(insVal);
                break;
            case 2:
                printf("\nEnter Value to insert: ");
                scanf("%d",&insVal);
                insEnd(insVal);
                break;
            case 3:
                printf("\nAfter whice Node?");
                scanf("%d",&af);
                printf("\nEnter Value to insert: ");
                scanf("%d",&insVal);
                insBet(af,insVal);
                break;
            case 4:
                printf("\nAfter which Node?");
                scanf("%d",&af);
		        z=remBet(af);
                printf("\nRemoved Value: %d",z);
                break;
            case 5:
		        z=remEnd();
                printf("\nRemoved Value: %d",z);
                break;
            case 6:
                printf("\nAfter which Node?");
                scanf("%d",&af);
                z=remBet(af);
                printf("\nRemoved Value: %d",z);
                break;
            case 7:
                display();
                break;
            case 8:
                exit(5);
        }
    }while(choice!=8);
    getch();
}//main close
//create function
node* create()
{
    node *z;
    z=(struct node*)malloc(sizeof(struct node));
    return z;
}
//insert beginning function
void insBeg(int x)
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
        q=create();
        q->info=x;
        q->next=p;
        list=q;
    }
    printf("\nNode is inserted\n");
}
//inset ending function
void insEnd(int x)
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
}
//insert between fuction
void insBet(int after, int x)
{
    node *p,*q;
    p=list;
    if(p==NULL)
    {
        printf("\nInsert between not possible\n");
    }
    else
    {
        while(p->next!=NULL)
        {
            if(p->info==after)
            {
                q=create();
                q->info=x;
                q->next=p->next;
                p->next=q;
            }
        }
    }
}
//remove beginning
int remBeg()
{
    int z;
    node *p;
    p=list;
    if(p==NULL)
	printf("\nLinked List is empty\n");
    else if(p->next==NULL)
    {
	z=p->info;
	free(p);
	list=NULL;
	return z;
    }
    else
    {
	z=p->info;
	list=p->next;
	free(p);
	return z;
    }
}
//remove ending
int remEnd()
{
    int z;
    node *p, *temp;
    p=list;
    if(p==NULL)
	printf("\nLinked List is Empty\n");
    else if(p->next==NULL)
    {
	z=p->info;
	free(p);
	list=NULL;
	return z;
    }
    else
    {
	while(p->next->next!=NULL)
	    p=p->next;
	temp=p->next;
	z=temp->info;
	p->next=NULL;
	return z;
    }
}
//remove between
int remBet(int after)
{
    int z;
    node *p,*temp;
    p=list;
    if(p==NULL)
	printf("\nLinked List is Empty\n");
    else if(p->next==NULL || p->next->next==NULL)
	printf("\nRemove Between Not Possible\n");
    else
    {
	while(p->next!=NULL)
	{
	    if(p->info==after)
	    {
		temp=p->next;
		z=temp->info;
		p->next=temp->next;
		free(temp);
		return z;
	    }
	}
    }
}
//display function
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