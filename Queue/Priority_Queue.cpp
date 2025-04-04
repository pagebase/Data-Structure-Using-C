#include <stdio.h>
#include <conio.h>
#include <process.h>
#define max 5

struct queue
{
    int item[max], prio[max];
    int front, rear;
};

void create(queue *);
void insert(queue *, int, int);
int remove(queue *);
void display(queue *);
void main()
{
    int ch, pr, x, z;
    queue *q, p;
    q = &p;
    do
    {
        printf("\nEnter Your Choice:->\n");
        printf("\n1:Create\n");
        printf("\n2:Insert\n");
        printf("\n3:Remove\n");
        printf("\n4:Display\n");
        printf("\n5:Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create(q);
            break;

        case 2:
            printf("\nEnter Insert Val:->\n");
            scanf("%d", &x);
            printf("\nEnter Priority Val:->\n");
            scanf("%d", &pr);
            insert(q, x, pr);
            break;

        case 3:
            z = remove(q);
            printf("\nRemoved Val:->%d\n", z);
            break;

        case 4:
            display(q);
            break;

        case 5:
            exit(1);
        }
    } while (ch != 5);
    getch();
}

void create(queue *q)
{
    q->front = q->rear = -1;
    printf("\nPriority Queue Is Created....\n");
}

void insert(queue *q, int x, int pr)
{
    if (q->rear == max - 1)
    {
        printf("\nPriority Queue Overflow....\n");
    }
    else
    {
        ++q->rear;
        q->item[q->rear] = x;
        q->prio[q->rear] = pr;
    }
    printf("\nElement Is Inserted....\n");
}

int remove(queue *q)
{
    int k, pos = 0, i, j;
    if (q->rear == q->front)
    {
        printf("\nPriority Queue underflow....\n");
        return (0);
    }
    else
    {
        k = q->prio[0];
        for (q->front + 1; i <= q->rear; i++)
        {
            if (k < q->prio[i])
            {
                k = q->prio[i];
                pos = i;
            }
        }
        j = q->item[pos];
        for (i = pos; i <= q->rear; i++)
        {
            q->item[i] = q->item[i + 1];
            q->prio[i] = q->prio[i + 1];
        }
        --q->rear;
        return (j);
    }
}

void display(queue *q)
{
    int i;
    printf("\nElements Are:->\n");
    for (i = q->front + 1; i <= q->rear; i++)
    {
        printf("\t%d", q->item[i]);
    }

    printf("\nPriorities Are:->\n");
    for (i = q->front + 1; i <= q->rear; i++)
    {
        printf("\t%d", q->prio[i]);
    }
}
