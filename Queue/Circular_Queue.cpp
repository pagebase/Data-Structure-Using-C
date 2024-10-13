//Title: Circular Queue
//Date: 7th Oct 2024
//Naming convention: camel case.
#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<alloc.h>
#define max 5
//structure section
struct queue
{
    int item[max];
    int front,rear;
}*q;
//function declaration section
void create();
void isEmpty();
void isFull();
void insert(int);
int remove();
void display();
//main section
void main()
{
    int remVal,choice,insVal;
    q=(queue*)malloc(sizeof(queue));
    clrscr();
    do
    {
        printf("\n1. Create\n");
        printf("\n2. isEmpty?\n");
        printf("\n3. isFull?\n");
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
            case 2://isEmpty?
                isEmpty();
                break;
            case 3://isFull?
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
                free(q);//Freed memory.
                exit(0);
                break;
        }
    } while (choice!=7);
    getch();
    
}
//Function definition section
void create()
{
    q->front=q->rear=-1;
    printf("Queue has been created!");
}
void isEmpty()
{
    if(q->front==-1)
        printf("Circular Queue is Empty!");
    else
        printf("Circular Queue is Not Empty!");
}
void isFull()
{
    if((q->front==0 && q->rear==max-1) || (q->front==q->rear+1))
        printf("Queue is Full!");
    else
        printf("Circular queue is not Full!");
}
int remove()
{
    int remVal;
    if(q->front==-1)
        printf("Queue is underflow!");
    else
    {
        remVal=q->item[q->front];
        if(q->front==q->rear)
            q->front=q->rear=-1;
        else
            q->front=(q->front+1)%max;
        return remVal;
    }
}
void display()
{
    int i;
    if(q->front>-1)
    {
        for(i=q->front;i!=q->rear;i=(i+1)%max)
            printf("%d\t",q->item[i]);
        printf("%d\t",q->item[q->rear]);
    }
}
void insert(int insVal)
{
    if((q->front==0 && q->rear==max-1) || (q->front==q->rear+1))
        printf("Queue overflow!");
    else
    {
        if(q->front==-1)
            q->front=q->rear=0;
        else
            q->rear=(q->rear+1)%max;
        q->item[q->rear]=insVal;
    }
}
