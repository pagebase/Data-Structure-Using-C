#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    int info;
    struct node *right;
} *root;

void ins();
void inorder(struct node *);
void delLeaf();
void del_one();
void delTwo();

struct node *create()
{
    return (struct node *)malloc(sizeof(struct node));
}

int main()
{
    int choice;

    while (1)
    {
        printf("1. Insert\n");
        printf("2. Inorder\n");
        printf("3. Delete\n    1. Delete leaf node\n    2. Delete node with one child\n    3. Delete node with two children\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            ins();
            break;
        case 2:
            inorder(root);
            break;
        case 3:
        {
            int delChoice;
            printf("1. Delete leaf node\n2. Delete node with one child\n3. Delete node with two children\n");
            printf("Enter delete choice: ");
            scanf("%d", &delChoice);

            switch (delChoice)
            {
            case 1:
                delLeaf();
                break;
            case 2:
                del_one();
                break;
            case 3:
                delTwo();
                break;
            default:
                printf("Invalid delete choice.\n");
            }
            break;
        }
        case 4:
            exit(0);
        default:
            printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

void ins()
{
    int insVal;
    struct node *newNode, *temp;

    newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter insert value: ");
    scanf("%d", &insVal);

    newNode->left = NULL;
    newNode->info = insVal;
    newNode->right = NULL;

    if (root == NULL)
    {
        root = newNode;
    }
    else
    {
        temp = root;
        while (1)
        {
            if (newNode->info < temp->info)
            {
                if (temp->left == NULL)
                {
                    temp->left = newNode;
                    break;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else if (newNode->info > temp->info)
            {
                if (temp->right == NULL)
                {
                    temp->right = newNode;
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
            else
            {
                printf("Duplicate values not allowed.\n");
                free(newNode);
                return;
            }
        }
    }
}

void inorder(struct node *p)
{
    if (p != NULL)
    {
        inorder(p->left);
        printf("%d\t", p->info);
        inorder(p->right);
    }
}