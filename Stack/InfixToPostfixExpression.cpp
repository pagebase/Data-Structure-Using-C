//Title: Infix to Postfix using stack
//Date: 24 Aug 2024
#include<stdio.h>
#include<conio.h>
#define max 50
struct stack
{
    int item[max];
    int top;
};
//function declaration section
void create(stack*);
void push(stack*,int);
int pop(stack*);
//main function
void main()
{
    char infixExp[max],postfixExp[max];
    int i=0,j=0,popVal;
    stack q;
    stack *p;
    p=&q;
    clrscr();
    create(p);
    printf("Enter Prefix Expression: ");
    scanf("%s",&infixExp);
    while(infixExp[i]!='\0')
    {
        //Run this block of code when reading character is opening parenthesis or operator.
        if(infixExp[i]=='('|| infixExp[i]=='+'||infixExp[i]=='-'||infixExp[i]=='*'||infixExp[i]=='/'||infixExp[i]=='!'||infixExp[i]=='@'||infixExp[i]=='$'||infixExp[i]=='%'||infixExp[i]=='^'||infixExp[i]=='&')
        {
            push(p,infixExp[i]);
        }
        else if(infixExp[i]==')')//If reading character is closing parenthesis then repeatedly perform pop opearation on stack till corresponding opening parenthesis encountered.
        {
            while(p->item[p->top]!='(')
            {
                popVal=pop(p);
                if(popVal!='(')
                {
                    postfixExp[j]=popVal;
                    j++;
                }
            }
            pop(p);
        }
        else//Run this block of code when reading character is operand.
        {
            postfixExp[j]=infixExp[i];
            j++;
        }
        i++;       
    }//All character has been read & while loop has end here.
    if(p->top!=-1)
    {
        while(p->top!=-1)
        {
            popVal=pop(p);
            if(popVal!='(')
            {
                postfixExp[j]=popVal;
                j++;
            }
        }
    }
    postfixExp[j]='\0';
    printf("Postfix Expression is: %s",postfixExp);
    getch();
}
//function definition section
//create function
void create(stack *p)
{
    p->top=-1;
}
//push function
void push(stack *p,int pushVal)
{
    if(p->top==max-1)
        printf("Stack is Overflow");
    else
    {
        ++p->top;
        p->item[p->top]=pushVal;
    }
}
//pop function
int pop(stack *p)
{
    if(p->top==-1)
    {
        printf("Stack is Underflow");
        return 0;
    }
    else
    {
        return(p->item[p->top--]);
    }
}
