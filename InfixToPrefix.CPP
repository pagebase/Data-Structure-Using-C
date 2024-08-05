//Title: Infix expression to Prefix expression
//Courtesy: Mr. Jibrail Bagwan
//Date: 5 Aug 2024

#include<stdio.h>
#include<string.h>
#include<conio.h>
#define  max  50
struct    stack
{
  int item[max];
  int  top;
};
void   create(stack*);
void   push(stack*,int);
int    pop(stack*);
void  main()
{
    clrscr();
    char  in[50],pre[50],ch;
    int   i=0,j=0;
    stack  *ops,*oprnd,a,b;
    ops=&a;
    oprnd=&b;
    create(ops);  //creates opstack
    create(oprnd);  //creates oprnd stack
    printf("\nEnter infix exp=");
    scanf("%s",&in);
    strrev(in);
    while(in[i]!='\0')
    {
       if(in[i]==')'||in[i]=='+'||in[i]=='-'||in[i]=='*'||in[i]=='/'||in[i]=='^'||in[i]=='$' || in[i]==='@' || in[i]=='#' || in[i]=='&')
       {
	   push(ops,in[i]);
       }
       else  if(in[i]=='(')
       {
	    while(ops->top!=-1)
	    {
		ch=pop(ops);
		if(ch!=')')
		{
		   push(oprnd,ch);
		}
	    }
       }
       else
       {
	    push(oprnd,in[i]);
       }
       i++;
    }

    if(ops->top!=-1)
    {
	while(ops->top!=-1)
	{
	     ch=pop(ops);
	     if(ch!=')')
	     {
		push(oprnd,ch);
	     }
	}
    }

    while(oprnd->top!=-1)
    {
       pre[j]=pop(oprnd);
       j++;
    }
    pre[j]='\0';
    printf("\nPrefixExp=%s",pre);
    getch();
}
void   create(stack   *p)
{
  p->top=-1;
}
void  push(stack *p,int x)
{
   if(p->top==max-1)
   {
      printf("\nStack overflow..");
   }
   else
   {
      ++p->top;
      p->item[p->top]=x;
   }
}

int   pop(stack   *p)
{
    if(p->top==-1)
    {
       printf("\nStack underflow..");
       return(0);
    }
    else
    {
       return(p->item[p->top--]);
    }
}
