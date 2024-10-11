//Title: Input Restriction Deque(IRD).
//Date: 10th Oct 2024.
//Naming convention: camel case
#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<alloc.h>
#define max 5
//structure section
struct ird
{
    int item[max];
    int left,right;
}*q;
//Function declaration section
void create();
void insert(int);
int remLeft();
int remRight();
void display();
//main function
void main()
{
    clrscr();
    q=(ird*)malloc(sizeof(ird));//Memory allocated for structure IRD.
    int choice,remVal,insVal;
    do
    {
        printf("\n1. Create\n");
        printf("\n2. Insert\n");
        printf("\n3. Remove Left\n");
        printf("\n4. Remove Right\n");
        printf("\n5. Display\n");
        printf("\n6. Exit\n");
        printf("\nEnter Your Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1://create
                create();
                break;
            case 2://Insert
                printf("\nEnter Insert Value: ");
                scanf("%d",&insVal);
                insert(insVal);
                break;
            case 3://Remove left
                remVal=remLeft();
                printf("\nRemoved Value: %d",remVal);
                break;
            case 4://Remove right
                remVal=remRight();
                printf("\nRemoved Value: %d",remVal);
                break;
            case 5://display
                display();
                break;
            case 6://exit
                exit(0);
                break;
        }
    } while (choice!=6);
    getch();    
}
//Function definition section
void create()
{
    q->left=q->right=-1;
    printf("\nIRD Created!\n");
}
void insert(int insVal)
{
    if(q->right==max-1)
        printf("\nIRD Overflow!\n");
    else
    {
        ++q->right;
        q->item[q->right]=insVal;
    }
}
int remLeft()
{
    int remVal;
    if(q->left==q->right)
    {
        printf("\nIRD Underflow!\n");
        return 0;
    }
    else
    {
        ++q->left;
        return(q->item[q->left]);
    }
}
int remRight()
{
    if(q->left==q->right)
    {
        printf("\nIRD Overflow!\n");
        return 0;
    }
    else
    {
        return(q->item[q->right--]);
    }
}
void display()
{
    int i;
    for(i=q->left+1;i<=q->right;i++)
        printf("%d\t",q->item[i]);
}