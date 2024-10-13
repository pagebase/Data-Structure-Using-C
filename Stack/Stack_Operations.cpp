//Title: Stack creation using all operation
//Date: 24 Aug 2024
#include<stdio.h>
#include<conio.h>
#include<cstdlib>//This header file is for exit() function.
#include<process.h>
#define max 5
//create structure
struct stack
{
    int item[max];
    int top;
};
//Function declaration section
void create(stack*);
void isEmpty(stack*);
void isFull(stack*);
void push(stack*,int);
int pop(stack*);
void display(stack*);
//main function
int main()
{
    int choice,popVal,pushVal;
    stack q;//created object for structure
    stack *p;//created pointer for structure
    p=&q;
    //clrscr();
    do
    {
        printf("\n1. Create\n");
        printf("\n2. Push\n");
        printf("\n3. Pop\n");
        printf("\n4. isEmpty\n");
        printf("\n5. isFull\n");
        printf("\n6. Display\n");
        printf("\n7. Exit\n");
        printf("\nEnter your Choice: ");//Enter your choice to perform above operation
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                create(p);
                break;
            case 2:
                printf("\nEnter Push Value: ");
                scanf("%d",&pushVal);
                push(p,pushVal);
                break;
            case 3:
                popVal=pop(p);
                printf("\nPopped Value: %d",popVal);
                break;
            case 4:
                isEmpty(p);
                break;
            case 5:
                isFull(p);
                break;
            case 6:
                display(p);
                break;
            case 7:
                exit(0);
                break;
            default:
                printf("\nInvalid Keyword\n");
        }//switch close
    }while(choice!=7);
        getch();
        return 0;
}//main close
//Function definition section
//create function
void create(stack *p)
{
    p->top=-1;
    printf("\nStack has been created\n");
}
//push function
void push(stack *p,int pushVal)
{
    if(p->top==max-1)
        printf("\nStack is Full\n");
    else
    {
        ++p->top;
        p->item[p->top]=pushVal;
        printf("\nElement is pushed\n");
    }
}
//pop function
int pop(stack *p)
{
    if(p->top==-1)
    {
        printf("\nStack is Underflow\n");
        return 0;
    }
    else
    {
        return(p->item[p->top--]);
    }
}
//isEmpty function
void isEmpty(stack *p)
{
    if(p->top==-1)
        printf("\nStack is Empty\n");
    else
        printf("\nStack is Not Empty\n");
        
}
//isFull function
void isFull(stack *p)
{
    if(p->top==max-1)
        printf("\nStack is Full\n");
    else
        printf("\nStack is Not Full\n");
}
//Display function
void display(stack *p)
{
    int i;
    for(i=p->top;i>-1;i--)
        printf("Index[%d]:%d\n",i,p->item[i]);
}
