//Courtesy: Mr.Jibrail Bagwan
// Date: 23 Jul 2024
// Title: Stack creation
#include<stdio.h>
#include<process.h>
#include<conio.h>
#define  max   5
struct   stack
{
   int item[max],top;
};
void  create(stack*);
void  isempty(stack*);
void  isfull(stack*);
void  push(stack*,int);
int   pop(stack*);
void  display(stack*);
void  main()
{
  int ch,x,z;
  stack    *p;
  stack   q;
  p=&q;   //Init. of ptr
  clrscr();
  do
  {
  printf("\nEnter  your choice ");
  printf("\n1:Create\n2:Isempty\n3:Isfull\n4:Push\n5:POP\n6:Display\n7:Exit");
  scanf("%d",&ch);
  switch(ch)
  {
	case	1:
		create(p);   //call
		break;
	case 	2:
		isempty(p);  //call
		break;
	case 	3:
		isfull(p);  //call
		break;
	case	4:
		printf("\nEnter val to push= ");
		scanf("%d",&x);
		push(p,x);   //call
		break;
	case 	5:
		z=pop(p);  //call
		printf("\nPopped val=%d",z);
		break;
	case	6:
		display(p);   //call
		break;
	case 	7:
		exit(1);
	}
     }
     while(ch!=7);
	getch();
  }
  void    create(stack   *p)
  {
	p->top=-1;
	printf("\nStack is created..");
  }
  void   isempty(stack   *p)
  {
      if(p->top==-1)
      {
	printf("\nStack is EMPTY");
      }
      else
      {
	printf("\nStack is NOT empty");
      }
  }
  void   isfull(stack   *p)
  {
      if(p->top==max-1)
      {
	  printf("\nStack is FULL");
      }
      else
      {
	  printf("\nStack is NOT FULL");
      }
  }
  void   push(stack  *p,int  x)
  {
      if(p->top==max-1)
      {
	 printf("\nStack overflow..");
      }
      else
      {
	 ++p->top;
	 p->item[p->top]=x;
	 printf("\nElement is pushed..");
      }
  }
  int    pop(stack   *p)
  {
     if(p->top==-1)
     {
       printf("\nStack Underflow");
       return(0);
     }
     else
     {
	return(p->item[p->top--]);
     }
  }
  void  display(stack   *p)
  {
     int i;
     for(i=p->top;i>=0;i--)
     {
	printf("\n%d",p->item[i]);
     }
  }
