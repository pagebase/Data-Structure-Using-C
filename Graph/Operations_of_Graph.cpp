#include <stdio.h>
#include <stdlib.h>
void displayVertex();
void insVertex();
void searchVertex();
void insEdge();

struct edge
{
    int p2;
    edge *right;
};

struct vertex
{
    vertex *next;
    int data;
    edge *adj;
} *start;

int main()
{
    int insVal;
    int choice;
    while (true)
    {
        printf("1. Insert vertex\n");        // insert vertex
        printf("2. Display Vertex\n");       // Display every vertex
        printf("3. Search vertex\n");        // Search particular vertex
        printf("4. Insert edge\n");          // Insert new edge
        printf("5. Find adjacent vertex\n"); // Display every adjacent vertex
        printf("6. Display entire graph\n"); // Display entire graph including vertex and edges
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("----------------------------------------------------------------------------------------------------\n");
        switch (choice)
        {
        case 1:
            insVertex();
            break;
        case 2:
            displayVertex();
            break;
        case 3:
            searchVertex();
            break;
        case 4:
            insEdge();
            break;
        case 7:
            exit(0);
        }
    }
    return 0;
}

void insVertex()
{
    int insVal;
    vertex *p;
    vertex *temp;
    printf("Enter insert value: ");
    scanf("%d", &insVal);
    p = (vertex *)malloc(sizeof(vertex));
    p->next = NULL;
    p->data = insVal;
    p->adj = NULL;
    if (start == NULL)
    {
        start = p;
    }
    else
    {
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = p;
        printf("vertex has been set successfuly!\n");
        printf("----------------------------------------------------------------------------------------------------\n");
    }
}

void displayVertex()
{
    vertex *temp;
    temp = start;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
    printf("----------------------------------------------------------------------------------------------------\n");
}

void searchVertex()
{
    int srcVal;
    vertex *temp;
    temp = start;
    printf("Enter search value: ");
    scanf("%d", &srcVal);
    while (temp != NULL)
    {
        if (temp->data == srcVal)
        {
            printf("Vertex found!\n");
            printf("----------------------------------------------------------------------------------------------------\n");
            break;
        }
        else
        {
            printf("Vertex doesn't exist\n");
            printf("----------------------------------------------------------------------------------------------------\n");
            break;
        }
    }
}

void insEdge()
{
    int srcVertex;
    int destVertex;
    vertex *p1 = start;
    vertex *p2 = start;
    edge *e;
    edge *temp;
    bool count1 = false;
    bool count2 = false;
    printf("Enter source: ");
    scanf("%d", &srcVertex);
    printf("Enter destination vertex: ");
    scanf("%d", &destVertex);
    while (p1 != NULL)
    {
        if (p1->data == srcVertex)
        {
            count1 = true;
            break;
        }
        p1 = p1->next;
    }
    while (p2 != NULL)
    {
        if (p2->data == destVertex)
        {
            count2 = true;
            break;
        }
        p2 = p2->next;
    }
    if (count1 && count2)
    {
        e = (edge *)malloc(sizeof(edge));
        e->p2 = destVertex;
        e->right = NULL;
        if (p1->adj == NULL)
        {
            p1->adj = e;
            printf("Successfully edge inserted\n");
            printf("----------------------------------------------------------------------------------------------------\n");
        }
        else
        {
            temp = p1->adj;
            while (temp->right != NULL)
            {
                temp = temp->right;
            }
            temp->right = e;
            printf("Successfully edge inserted\n");
            printf("----------------------------------------------------------------------------------------------------\n");
        }
    }
    else
    {
        printf("Invalid edge!\n");
        printf("----------------------------------------------------------------------------------------------------\n");
    }
}