//Title: Singly Circular Linked List
//Date: 14 Sep 2024 00:23(24Hours)
//Naming Convention: camelCase
#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<alloc.h>
//structure section
struct node
{
    int info;
    node *next;
}*list;
//Function pretotype
node* create();//Create new node
void insBeg(int);//Insert at beginning.(1)
void insBet(int,int);//Insert between.(2)
void insEnd(int);//Insert at Ending.(3)
int remBeg();//Remove beginning.(4)
int remBet(int);//Remove between.(5)
int remEnd();//Remove end Node.(6)
void display();//Display all info part from each node.(7)
void search(int);//Search for perticular Node.(8)
void count();//Count how many node exists in the linked list.(9)
void reverse();//Reverse the each node.(10)
//Main section
void main()
{
    list=NULL;//Used to stop random memory pointing.
    int insVal,after,remVal,choice,srcVal;
    clrscr();
    do
    {
        printf("\n1.Insert at Beginning\n");
        printf("\n2.Insert at Between\n");
        printf("\n3.Insert at Ending\n");
        printf("\n4.Remove Beginning\n");
        printf("\n5.Remove Between\n");
        printf("\n6.Remove End\n");
        printf("\n7.Display\n");
        printf("\n8.Search\n");
        printf("\n9.Count\n");
        printf("\n10.Reverse\n");
        printf("\n11.Exit\n");
        printf("\nEnter Your Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1://insBeg
                printf("Enter Insert Value: ");
                scanf("%d",&insVal);
                insBeg(insVal);
                break;
            case 2://insBet
                printf("After which Node?: ");
                scanf("%d",&after);
                printf("Enter Insert Value: ");;
                scanf("%d",&insVal);
                insBet(after,insVal);
                break;
            case 3://insEnd
                printf("Enter Insert Value: ");
                scanf("%d",&insVal);
                insEnd(insVal);
                break;
            case 4://remBeg
                remVal=remBeg();
                printf("Removed Value: %d",remVal);
                break;
            case 5://remBet
                printf("After which Node?: ");
                scanf("%d",&after);
                remVal=remBet(after);
                printf("Removed Value: %d",remVal);
                break;
            case 6://remEnd
                remVal=remEnd();
                printf("Removed Value: %d",remVal);
                break;
            case 7://display
                display();
                break;
            case 8://search
                printf("Enter Search Value: ");
                scanf("%d",&srcVal);
                search(srcVal);
                break;
            case 9://count
                count();
                break;
            case 10://reverse
                reverse();
                break;
            case 11://exit
                exit(0);

        }//switch close.

    }while(choice!=11);
    getch();
}
//Function definition section
node* create()
{
    node *p;
    p=(node*)malloc(sizeof(node));
    return p;
}
void insBeg(int insVal)
{
    node *p,*q;
    p=list;
    if(p==NULL)
    {
        p=create();
        p->info=insVal;
        p->next=p;
        list=p;
    }
    else
    {
        while(p->next!=list)
            p=p->next;
        q=create();
        q->info=insVal;
        q->next=p->next;
        p->next=q;
        list=q;
    }
}
void insBet(int after,int insVal)
{
    node *p,*q;
    p=list;
    if(p==NULL || p->next==p)
        printf("Insert between Not Possible!");
    else
    {
        while(p->next!=list)
        {
            if(p->info==after)
            {
                q=create();
                q->info=insVal;
                q->next=p->next;
                p->next=q;
            }
            p=p->next;
        }
    }
}
void insEnd(int insVal)
{
    node *p,*q;
    p=list;
    if(p==NULL)
    {
        p=create();
        p->info=insVal;
        p->next=p;
        list=p;
    }
    else
    {
        while(p->next!=list)
        {
            p=p->next;
        }
        q=create();
        q->info=insVal;
        q->next=p->next;
        p->next=q;
    }
}
int remBeg()
{
    node *p,*temp;
    int remVal;
    p=list;
    if(p==NULL)
    {
        printf("Remove Begin Not Possible");
    }
    else if(p->next==p)
    {
        remVal=p->info;
        list=NULL;
        free(p);
        return remVal;
    }
    else
    {
        while(p->next!=list)
            p=p->next;//Stay at last Node.
        temp=p->next;
        remVal=temp->info;
        p->next=temp->next;
        list=temp->next;
        free(temp);
        return remVal;
    }
}
int remBet(int after)
{
    node *p,*temp;
    int remVal;
    p=list;
    if(p==NULL || (p->next==p) || (p->next->next==list))
    {
        printf("Remove Between Not Possible");
    }
    else
    {
        while(p->next!=list)
        {
            if(p->info==after)
            {
                temp=p->next;
                remVal=temp->info;
                p->next=temp->next;
                free(temp);
                return remVal;
            }
            p=p->next;
        }
    }
}
int remEnd()
{
    node *p,*temp;
    int remVal;
    p=list;
    if(p==NULL)
    {
        printf("Linked List is Empty like my Mind");
    }
    else if(p->next==p)
    {
        remVal=p->info;
        list=NULL;
        return remVal;
    }
    else
    {
        while(p->next->next!=list)
            p=p->next;
        temp=p->next;
        remVal=temp->info;
        p->next=temp->next;//Another approach-> p->next=list;
        free(temp);
        return remVal;
    }
}
void display()
{
    node *p;
    p=list;
    if(p==NULL)
        printf("Linked list is Empty like my Mind");
    else
    {
        do
        {
            printf("%d\t",p->info);
            p=p->next;
        } while (p!=list);
        
    }
}
void search(int srcVal)
{
    node *p;
    int t=0;
    p=list;
    do
    {
        if(p->info==srcVal)
        {
            t=1;
            break;
        }
        p=p->next;
    } while (p!=list);
    
    if(t==1)
        printf("Node found at %d address",&p);
    else
        printf("Node Not foundddddd!");
}
void count()
{
    node *p;
    int counter=0;
    p=list;
    if(p==NULL)
        counter=0;
    else
    {
        do
        {
            counter++;
            p=p->next;
        } while (p!=list);
    }
    printf("Total Node Is: %d",counter);
}
void reverse()
{
    node *t1,*t2,*t3=NULL;
    t1=list;
    do
    {
        t2=t1->next;
        t1->next=t3;
        t3=t1;
        t1=t2;
    } while(t1!=list);
    list=t3;
    t1->next=t3;
}
