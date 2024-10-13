//Title: Infix to Prefix expression using stack
//Date: 24 Aug 2024
#include<stdio.h>
#include<conio.h>
#include<string.h>
#define max 50
//structure section
struct stack
{
    int item[max];
    int top;
};
//function declaration section
void create(stack*);
void push(stack*,int);
int pop(stack*);
//main section
void main()
{
    char infixExp[max],prefixExp[max];
    char popVal;
    int i=0,j=0;
    stack st1,st2;//created two object to structure
    stack *opstack,*operand;//created two structure pointer to structure
    clrscr();
    opstack=&st1;
    operand=&st2;
    create(opstack);
    create(operand);
    printf("Enter Infix Expression: ");
    scanf("%s",&infixExp);
    strrev(infixExp);
    while(infixExp[i]!='\0')
    {
        if(infixExp[i]==')' || infixExp[i]=='+' || infixExp[i]=='-' || infixExp[i]=='*' || infixExp[i]=='/' || infixExp[i]=='$' || infixExp[i]=='^' || infixExp[i]=='&' || infixExp[i]=='%')
            push(opstack,infixExp[i]);
        else if(infixExp[i]=='(')
        {
            while(opstack->top!=-1)
            {
                popVal=pop(opstack);
                if(popVal!=')')
                    push(operand,popVal);
            }
        }
        else
        {
            push(operand,infixExp[i]);
        }
        i++;
    }
    if(opstack->top!=-1)
    {
        while(opstack->top!=-1)
        {
            popVal=pop(opstack);
            if(popVal!=')')
                push(operand,popVal);
        }
    }
    while(operand->top!=-1)
    {
        prefixExp[j]=pop(operand);
        j++;
    }
    prefixExp[j]='\0';
    printf("Prefix: %s",prefixExp);
    getch();
}
//Function definition section
void create(stack *p)
{
    p->top=-1;
}
void push(stack *p,int pushVal)
{
    if(p->top==max-1)
        printf("Stack is Full");
    else
    {
        ++p->top;
        p->item[p->top]=pushVal;
    }
}
int pop(stack *p)
{
    if(p->top==-1)
    {
        printf("Stack is Underflow");
        return 0;
    }
    else
        return(p->item[p->top--]);
}
