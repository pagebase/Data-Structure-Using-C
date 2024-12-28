#include <stdio.h>
#include <stdlib.h>

#define max 5

struct Queue
{
    int item[max], priority[max];
    int front, rear;
    /* data */
};

void create(Queue *);
void insert(Queue *, int, int);
int remove(Queue *);
void display(Queue *);

int main()
{
    int choice, ins_Element, rem_Element, ins_Priority;
    Queue *q, p;
    q = &p;
    do
    {
        printf("\n\nEnter your choice:");
        printf("\n1:Create \n2:Insert \n3:Remove \n4:Display \n5:Exit\t\t");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create(q);
            break;
        case 2:
            printf("\n\tEnter value to insert:");
            scanf("%d", &ins_Element);
            printf("\n\tEnter priority:");
            scanf("%d", &ins_Priority);
            insert(q, ins_Element, ins_Priority);
            break;
        case 3:
            rem_Element = remove(q);
            printf("\nRemoved value:%d", rem_Element);
            break;
        case 4:
            display(q);
            break;
        case 5:
            exit(121);
        }
    } while (choice != 5);
    return 0;
}

void create(Queue *q)
{
    q->front = q->rear = -1;
    printf("\n\tPriority Queue is created!");
}

void insert(Queue *q, int ins_Element, int ins_Priority)
{
    if (q->rear == max - 1)
    {
        printf("\n\tPriority Queue Overflows...");
    }
    else
    {
        q->rear++;
        q->item[q->rear] = ins_Element;
        q->priority[q->rear] = ins_Priority;
    }
}

int remove(Queue *q)
{
    int m, pos = 0, z, i, j,y;
    if (q->front == q->rear)
    {
        printf("\n\tPriority Queue Underflows...");
        return 0;
    }
    else
    {
        m = q->priority[0];
        for (i = q->front + 1; i <= q->rear; i++)
        {
            if (m < q->priority[i])
            {
                m = q->priority[i];
                pos = i;
            }
        }
        // y = q->priority[pos];
        z = q->item[pos];
        for (j = pos; j <= q->rear; j++)
        {
            q->item[j] = q->item[j + 1];
            q->priority[j] = q->priority[j + 1];
        }
        --q->rear;
        return (z);
    }
}


void display(Queue *q)
{
    printf("\n\tElements are:");
    for (int i = q->front + 1; i <= q->rear; i++)
    {
        printf("\t%d", q->item[i]);
    }
    printf("\n\tPriorities are:");
    for (int i = q->front + 1; i <= q->rear; i++)
    {
        printf("\t%d", q->priority[i]);
    }
}