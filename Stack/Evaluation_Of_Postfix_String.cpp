#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define max 100

struct stack
{
    int item[max], top;
    /* data */
};

void create(stack *);
void push(stack *, int);
int pop(stack *);

int main()
{
    int i = 0, value, opr_1, opr_2, z;
    char post[50];
    stack *p, q;
    p = &q;
    create(p);
    printf("\nEnter any Postfix Exp:");
    scanf("%s", &post);

    while (post[i] != '\0')
    {
        if (post[i] == '+' || post[i] == '/' || post[i] == '*' || post[i] == '-' || post[i] == '$')
        {
            opr_2 = pop(p);
            opr_1 = pop(p);
            switch (post[i])
            {
            case '+':
                value = opr_1 + opr_2;
                push(p, value);
                break;
            case '-':
                value = opr_1 - opr_2;
                push(p, value);
                break;
            case '*':
                value = opr_1 * opr_2;
                push(p, value);
                break;
            case '/':
                value = opr_1 / opr_2;
                push(p, value);
                break;
            case '$':
                value = pow(opr_1, opr_2);
                push(p, value);
                break;
            }
        }
        else
        {
            push(p, post[i] - 48);
        }
        i++;
    }

    z = pop(p);
    printf("\nValue of given Postfix Exp:%d", z);
    return 0;
}

void create(stack *p)
{
    p->top = -1;
}

void push(stack *p, int n)
{
    if (p->top == max - 1)
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