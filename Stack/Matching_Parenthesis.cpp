#include <stdlib.h>
#include <stdio.h>

#define MAX 100
struct stack
{
    int item[MAX];
    int top;
};

void create(stack *);
void push(stack *, int);
int pop(stack *);

int main()
{
    int i = 0, temp = 0;
    char in[50], ch;
    stack *p, q;
    p = &q;
    create(p);
    printf("Enter an expression: ");
    gets(in);
    while (in[i] != '\0')
    {
        if (in[i] == '(' || in[i] == '[' || in[i] == '{')
        {
            push(p, in[i]);
        }
        else if (in[i] == ')' || in[i] == '}' || in[i] == ']')
        {
            ch = pop(p);
            if ((ch == '(') != (in[i] == ')') || (ch == '[') != (in[i] == ']') || (ch == '{') != (in[i] == '}'))
            {
                temp = 1;
                break;
            }
        }
        i++;
    }

    if (p->top != -1 || temp == 1)
    {
        printf("\nInvalid Expression!");
    }
    else
    {
        printf("\nValid Expression!");
    }

    return 0;
}

void create(stack *p)
{
    p->top = -1;
    // printf("\nStack is created\n");
}

void push(stack *p, int n)
{
    if (p->top == MAX - 1)
    {
        printf("\nStack overflow...");
    }
    else
    {
        ++p->top;
        p->item[p->top] = n;
    }
}

int pop(stack *p)
{
    if (p->top == -1)
    {
        printf("\nstack underflow...");
    }
    else
    {
        return (p->item[p->top--]);
    }
}