#include <stdio.h>
#include <process.h>
#include <conio.h>
#include <alloc.h>
struct node
{
   int info;
   node *next;
   F
} *list;
node *create();
void isempty();
void push(int);
int pop();
void display();

void main()
{
   int z;
   int ch, x;
   clrscr();
   do
   {
      printf("\nEnter your choice=");
      printf("\n1:Isempty\n2:Push\n3:Pop\n4:Display\n5:Exit  ");
      scanf("%d", &ch);
      switch (ch)
      {
      case 1:
         isempty();
         break;
      case 2:
         printf("\nEnter any ele=");
         scanf("%d", &x);
         push(x); // call
         break;
      case 3:
         z = pop();
         printf("\nPopped Val=%d", z);
         break;
      case 4:
         display();
         break;
      case 5:
         exit(1);
      }
   } while (ch != 5);
   getch();
}
node *create()
{
   node *z;
   z = new node;
   return (z);
}
void isempty()
{
   if (list == NULL)
      printf("\nStack is Empty..");
   else
      printf("\nStack is NOT empty..");
}
void push(int x)
{
   node *p, *q;
   p = list;
   if (p == NULL)
   {
      p = create();
      p->info = x;
      p->next = NULL;
      list = p;
   }
   else
   {
      q = create();
      q->info = x;
      q->next = p;
      list = q;
   }
   printf("\nElement is Pushed...");
}

int pop()
{
   int z;
   node *p;
   p = list;
   if (p == NULL)
   {
      printf("\nStack underflows..");
      return (0);
   }
   else if (p->next == NULL)
   {
      z = p->info;
      delete p;
      list = NULL;
      return (z);
   }
   else
   {
      z = p->info;
      list = p->next;
      delete p;
      return (z);
   }
}
void display()
{
   node *p;
   p = list;
   while (p != NULL)
   {
      printf("\n%d", p->info);
      p = p->next;
   }
}
