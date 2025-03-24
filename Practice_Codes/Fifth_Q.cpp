#include <stdio.h>
#include <stdlib.h>

struct node
{
    node *left;
    int info;
    node *right;
} *root;

void ins();
void inorder(node *);
void del(int);
void delOne(node *, node *);
void delTwo(node *);
void delLeaf(node *);

int main()
{
    int choice;
    int choice1;
    int delValue;
    while (true)
    {
        printf("1. Insert\n");
        printf("2. Inorder\n");
        printf("3. Delete\n");
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
            printf("Enter delete value: ");
            scanf("%d", &delValue);
            del(delValue);
            break;
        case 4:
            exit(0);
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
    newNode = create();
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

// Delete functions
void delLeaf(node *p, node *c)
{
    if (p->left == c)
    {
        p->left = NULL;
    }
    else if (p->right == c)
    {
        p->right = NULL;
    }
    free(c);
    printf("Node successfully deleted\n");
}

void delOne(node *p, node *c)
{
    if (c == p->left)
    {
        if (c->left != NULL)
        {
            p->left = c->left;
        }
        else
        {
            p->left = c->right;
        }
    }
    else if (c == p->right)
    {
        if (c->right != NULL)
        {
            p->right = c->right;
        }
        else
        {
            p->right = c->left;
        }
    }
    free(c);
    printf("Node successfully deleted\n");
}

void delTwo(node *c)
{
    node *lft, *p = NULL;
    lft = c->left;
    while (lft->right != NULL)
    {
        p = lft;
        lft = lft->right;
    }

    c->info = lft->info;
    if (p == NULL)
    {
        p = c;
    }

    if (lft->left == NULL && lft->right == NULL)
    {
        delLeaf(p, lft);
    }
    else
    {
        delOne(p, lft);
    }
}

void del(int delValue)
{
    int found = 0;
    node *p;
    node *c;
    p = root;
    c = root;
    while (c != NULL)
    {
        if (c->info == delValue)
        {
            found = 1;
            break;
        }
        else if (delValue < c->info)
        {
            p = c;
            c = c->left;
        }
        else if (delValue > c->info)
        {
            p = c;
            c = c->right;
        }
    }
    if (found)
    {
        if (c->left == NULL && c->right == NULL)
        {
            delLeaf(p, c);
        }
        else if (c->left != NULL && c->right != NULL)
        {
            delTwo(c);
        }
        else
        {
            delOne(p, c);
        }
    }
    else
    {
        printf("Not Not Found!\n");
    }
}
