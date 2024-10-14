#include<stdio.h>
#include<stdlib.h>
#define max 5
struct ORD
{
    int item[max];
    int left,right;
}*p;
//Function declaration section
void create();
void insRight(int);
void insLeft(int);
int remove();
void display();
int main()
{
    int remVal,insVal,choice;
    p=(ORD*)malloc(sizeof(ORD));//Memory allocated for structure.
    do
    {
        printf("\n1. Create\n");
        printf("\n2. Insert Right\n");
        printf("\n3. Insert Left\n");
        printf("\n4. Remove\n");
        printf("\n5. Display\n");
        printf("\n6. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1://create()
                create();
                break;
            case 2:// insRight()
                printf("Enter Insert Value: ");
                scanf("%d",&insVal);
                insRight(insVal);
                break;
            case 3://insLeft()
                printf("Enter Insert Value: ");
                scanf("%d",&insVal);
                insLeft(insVal);
                break;
            case 4://remove
                remVal=remove();
                if(remVal!=0)
                {
                    printf("\nRemoved Value: %d",remVal);
                }
                break;
            case 5://display
                display();
                break;
            case 6://exit()
                free(p);
                exit(0);
                break;
            default:
                printf("Invalid input");
                break;        
        }
    } while (choice!=6);
}
//Definition section
void create()
{
    p->left=p->right=-1;
    printf("ORD created!");
}
void insRight(int insVal)
{
    if(p->right==max-1)
        printf("ORD overflow");
    else
    {
        ++p->right;
        p->item[p->right]=insVal;
    }
}
void insLeft(int insVal)
{
    int i;
    if(p->right==max-1)
        printf("ORD overflow");
    else
    {
        for(i=p->right+1;i>=p->left+2;i--)
            p->item[i]=p->item[i-1];
        p->item[p->left+1]=insVal;
        ++p->right;
    }
}
int remove()
{
    if(p->left==p->right)
    {
        printf("ORD underflow");
        return 0;
    }
    else
    {
        ++p->left;
        return(p->item[p->left]);
    }
}
void display()
{
    int i;
    for(i=p->left+1;i<=p->right;i++)
        printf("%d\t",p->item[i]);
}