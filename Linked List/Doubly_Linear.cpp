//Title: Doubly Linear Linked List
//Date: 9 Sep 2024
#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<alloc.h>
//structure section. It is Global section.
struct node
{
    node *previous;
    int info;
    node *next;
}*list;
//function prototype.
node* create();//create node.
void insBeg(int);//Insert at beginning.
void insEnd(int);//Insert at ending.
void insBet(int,int);//Insert at particular place or in between.
int remBeg();//Remove beginning.
int remEnd();//Remove ending node.
int remBet(int);//Remove node from in between.
void reverse();//Reverse the Node.
void display();//Display data from each node.
void search(int);//Search particular Node.
void count();//Coount how many Node exists.
//Main section
void main()
{
    int choice,insVal,after,remVal,searchVal;
    clrscr();
    do
    {
	    printf("\n1. Insert at Beginning\n");
	    printf("\n2. Insert at Ending\n");
	    printf("\n3. Insert Between\n");
	    printf("\n4. Remove Beginning\n");
	    printf("\n5. Remove ending\n");
	    printf("\n6. Remove Between\n");
	    printf("\n7. Reverse Nodes\n");
	    printf("\n8. Display\n");
	    printf("\n9. Search\n");
	    printf("\n10. Count\n");
	    printf("\n11: Exit\n");
	    printf("Enter Your Choice: ");
	    scanf("%d",&choice);
	    switch(choice)
	        {
	            case 1:
		            printf("Enter Insert Value: ");
		            scanf("%d",&insVal);
		            insBeg(insVal);
		            break;
	            case 2:
		            printf("Enter Insert Value: ");
		            scanf("%d",&insVal);
		            insEnd(insVal);
		            break;
	            case 3:
		            printf("Aftre which node?: ");
		            scanf("%d",&after);
		            printf("Enter Insert Value: ");
		            scanf("%d",&insVal);
		            insBet(after,insVal);
		            break;
	            case 4:
		            remVal=remBeg();
		            printf("Removed Value is: %d",remVal);
		            break;
	            case 5:
		            remVal=remEnd();
		            printf("Removed Value is: %d",remVal);
		            break;
	            case 6:
		            printf("After which Node?: ");
		            scanf("%d",&insVal);
		        	remVal=remBet(insVal);
		            printf("Removed Value is: %d",remVal);
		            break;
	            case 7:
		            reverse();
		            break;
	            case 8:
	            	display();
                    break;
                case 9:
                    printf("Enter Search Value: ");
                    scanf("%d",&searchVal);
		            search(searchVal);
                    break;
                case 10:
                    count();
                    break;
                case 11:
                    exit(10);
        }
    }while(choice!=11);
    getch();
}//Main function end
//Function definition section
//create function
node* create()
{
    node *p;
    p=(node*)malloc(sizeof(node));
    return p;
}
//Insert beginning function
void insBeg(int insVal)
{
    node *p,*q;
    p=list;
    if(p==NULL)
    {
	    p=create();
	    p->previous=NULL;
	    p->info=insVal;
	    p->next=NULL;
	    list=p;
    }
    else
    {
	    q=create();
         q->previous=NULL;
         q->info=insVal;
         q->next=p;
         p->previous=q;
         list=q;
    }
}
void insBet(int after,int insVal)
{
    node *p,*q;
    p=list;
    if(p==NULL || (p->previous && p->next==NULL))
        printf("Insert between is Not possible");
    else
    {
        while(p->next!=NULL)
        {
            if(p->info==after)
            {
                q=create();
                q->previous=p;
                q->info=insVal;
                q->next=p->next;
                p->next->previous=q;
                p->next=q;
            }
            p=p->next;
        }
    }
}
//Insert at ending
void insEnd(int insVal)
{
    node *p,*q;
    p=list;
    if(p==NULL)
    {
        p=create();
        p->previous=NULL;
        p->info=insVal;
        p->next=NULL;
        list=p;
    }
    else
    {
        while(p->next!=NULL)
            p=p->next;
        q=create();
        q->previous=p;
        q->info=insVal;
        q->next=NULL;
        p->next=q;
    }
}
//Remove from Beginning
int remBeg()
{
    node *p;
    int remVal;
    p=list;
    if(p==NULL)
        printf("LL is Empty");
    else if(p->previous==NULL && p->next==NULL)
    {
        remVal=p->info;
        list=NULL;
        free(p);
        return remVal;
    }
    else
    {
        remVal=p->info;
        p->next->previous=NULL;
        list=p->next;
        free(p);
        return remVal;
    }
}
//Remove between
int remBet(int after)
{
    int remVal;
    node *p,*temp;
    p=list;
    if(p==NULL)
        printf("LL is Empty");
    else if(p->previous==NULL && p->next==NULL || (p->previous==NULL && p->next->next==NULL))
        printf("Remove between not possible");
    else
    {
        while(p->next!=NULL)
        {
            if(p->info==after)
            {
                temp=p->next;
                remVal=temp->info;
                temp->next->previous=p;
                p->next=temp->next;
                free(temp);
                return remVal;
            }
        }
    }
}
//Remove ending
int remEnd()
{
    int remVal;
    node *p,*temp;
    p=list;
    if(p==NULL)
        printf("LL is Empty");
    else if(p->previous==NULL && p->next==NULL)
    {
        remVal=p->info;
        free(p);
        list=NULL;
        return remVal;
    }
    else
    {
        while(p->next->next!=NULL)
        {
            p=p->next;
        }
        temp=p->next;
        remVal=temp->info;
        p->next=NULL;
        free(temp);
        return remVal;
    }
}
//Search function
void search(int searchVal)
{
    int found=0;
    node *p;
    p=list;
    while(p!=NULL)
    {
        if(p->info==searchVal)
        {
            found=1;
            break;
        }
        p=p->next;
        if(found==1)
            printf("Node found");
        else
            printf("Node not found");
    }
}
//Count function
void count()
{
    int count=0;
    node *p;
    p=list;
    while(p!=NULL)
    {
        count++;
        p=p->next;
    }
    printf("Total Node is: %d",count);
}
//Display function
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
//Reverse Node
void reverse()
{
    node *t1,*t2,*t3=NULL;
    t1=list;
    while(t1!=NULL)
    {
        t2=t1->next;
        t1->next=t3;
        t1->previous=t2;
        t3=t1;
	t1=t2;
    }
    list=t3;
}