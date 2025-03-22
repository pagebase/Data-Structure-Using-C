#include <stdio.h>
#include <stdlib.h>
int min;
int max;
struct node
{
    node *left;
    int info;
    node *right;
} *root;

node *create();
void ins(int);
void findMin(node *);
void findMax(node *);
void displayEven(node *);
void displayOdd(node *);

int main()
{
    int choice;
    int insVal;
    while (true)
    {
        printf("1. insert\n");
        printf("2. Find max\n");
        printf("3. Find min\n");
        printf("4. Display even\n");
        printf("5. Display odd\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter ins val: ");
            scanf("%d", &insVal);
            ins(insVal);
            break;
        case 2:
            findMax(root);
            printf("Max value is: %d\n", max);
            break;
        case 3:
            findMin(root);
            printf("Min value is: %d\n", min);
            break;
        case 4:
            displayEven(root);
            break;
        case 5:
            displayOdd(root);
            break;
        case 6:
            exit(6);
        }
    }
    return 0;
}

node *create()
{
    node *p = (node *)malloc(sizeof(node));
    return p;
}

void ins(int insVal)
{
    node *p;
    node *temp;
    p = create();
    p->left = NULL;
    p->info = insVal;
    p->right = NULL;
    if (root == NULL)
    {
        root = p;
    }
    else
    {
        temp = root;
        while (temp != NULL)
        {
            if (p->info < temp->info)
            {
                if (temp->left == NULL)
                {
                    temp->left = p;
                    break;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else
            {
                if (temp->right == NULL)
                {
                    temp->right = p;
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }
}

void findMax(node *p)
{
    if (p != NULL)
    {
        if (p->info > max)
        {
            max = p->info;
        }
        findMax(p->left);
        findMax(p->right);
    }
}

void findMin(node *p)
{
    if (p != NULL)
    {
        findMin(p->left);
        if (p->info < min)
        {
            min = p->info;
        }
        findMin(p->right);
    }
}

void displayEven(node *p)
{
    if (p != NULL)
    {
        if (p->info % 2 == 0)
        {
            printf("%d\t", p->info);
        }
        displayEven(p->left);
        displayEven(p->right);
    }
}
void displayOdd(node *p)
{
    if (p != NULL)
    {
        if (p->info % 2 != 0)
        {
            printf("%d\t", p->info);
        }
        displayOdd(p->left);
        displayOdd(p->right);
    }
}