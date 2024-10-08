//Title: Linear Queue
//Date: 7th Oct 2024
//Naming convention: camelCase
#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<alloc.h>
#define max 5
//structure section
struct queue
{
    int item[max];
    int rear,front;
}*q;
//Functon declaration section
void create();
void isEmpty();
void isFull();
void insert(int);
int remove();
void display();
//Main section
void main()
{
    int choice,insVal,remVal;
  //  q=(queue*)malloc(sizeof(queue));
    clrscr();
    do
    {
	printf("\n1. Create\n");
	printf("\n2. Is Empty?\n");
	printf("\n3. Is Full\n");
	printf("\n4. Insert\n");
	printf("\n5. Remove\n");
	printf("\n6. Display\n");
	printf("\n7. Exit\n");
	printf("Enter Your Choice: ");
	scanf("%d",&choice);
	switch(choice)
	{
	    case 1://create
		create();
		break;
	    case 2://isEmpty
		isEmpty();
		break;
	    case 3://isFull
		isFull();
		break;
	    case 4://insert
		printf("Enter Insert Value: ");
		scanf("%d",&insVal);
		insert(insVal);
		break;
	    case 5://remove
		remVal=remove();
		printf("Removed Value: %d",remVal);
		break;
	    case 6://display
		display();
		break;
	    case 7://exit
		exit(0);
		break;
	}
    } while (choice!=7);
    getch();
}
//Function declaration section
void create()
{

    q=(queue*)malloc(sizeof(queue));
    q->front=q->rear=-1;
    printf("Queue has been created!");
}
void isEmpty()
{
    if(q->front==q->rear)
        printf("Queue is Empty!");
    else
        printf("Queue is not Empty!");
}
void isFull()
{
    if(q->rear==max-1)
        printf("Queue is Full!");
    else
        printf("Queue is not Full!");
}
void insert(int insVal)
{
    if(q->rear==max-1)
        printf("Queue overflow!");
    else
    {
        ++q->rear;
        q->item[q->rear]=insVal;
    }
}
int remove()
{
    if(q->front==q->rear)
        printf("Queue overflow!");
    else
    {
        ++q->front;
        return(q->item[q->front]);
    }
}
void display()
{
    int i;
    for(i=q->front+1;i<=q->rear;i++)
        printf("%d\t",q->item[i]);
}
