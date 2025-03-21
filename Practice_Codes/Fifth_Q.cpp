#include <stdio.h>
#include <stdlib.h>
void ins();
void inorder(node *);

struct node
{
    node *left;
    int info;
    node *right;
} *root;

int main()
{
    while (true)
    {
        print("1.Insert\n");
        print("2. Inorder\n");
        print("3. Delete\n    1. Delete leaf node\n");
        print("4. Exit\n");
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
            switch (3)
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
            }
        case 4:
            exit(5);
        }
    }
    return 0;
}
node *create()
{
    node *p = (node *)malloc(sizeof(node));
    return p;
}
void ins()
{
    int insVal;
    node *newNode;
    node *temp;
    printf("Enter insert value: ");
    scanf("%d", &insVal);
    newNode->left = NULL;
    newNode->info = insVal;
    neNode->right = NULL;
    if (root == NULL)
    {
        root = newNode;
    }
    else
    {
        temp = root;
        while (temp != NULL)
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
            }
        }
    }
}

void inorder(node *p)
{
    if (p != NULL)
    {
        inorder(p->left);
        printf("%d\t", p->info);
        inorder(p->right);
    }
}