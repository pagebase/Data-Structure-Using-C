#include <stdio.h>
#include <alloc.h>
#include <conio.h>
#include <process.h>
struct node
{
    node *left;
    int info;
    node *right;
} *root;
node *create();
void insert(int);
void inorder(node *);
void del_leaf(node *, node *);
void del_one(node *, node *);
void del_two(node *);
void del(int);

void main()
{
    int ch, n, a;
    clrscr();
    do
    {
        printf("\nEnter your choice ");
        printf("\n1:Insert\n2:Inorder\n3:Delete\n4:Exit ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter val to insert:  ");
            scanf("%d", &n);
            insert(n);
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            printf("Enter val to delete=");
            scanf("%d", &n);
            del(n);
            break;
        case 4:
            exit(1);
        }
    } while (ch != 4);
    getch();
}

node *create()
{
    node *z;
    z = (node *)malloc(sizeof(node));
    return (z);
}

void insert(int x)
{
    node *p, *temp;
    p = create();
    p->left = NULL;
    p->info = x;
    p->right = NULL;
    if (root == NULL)
    {
        root = p;
        printf("\nNode is inserted..");
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
                    printf("\nNode is inserted...");
                    break;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else if (p->info > temp->info)
            {
                if (temp->right == NULL)
                {
                    temp->right = p;
                    printf("\nNode is inserted...");
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

void inorder(node *p)
{
    if (p != NULL)
    {
        inorder(p->left);
        printf("\t%d", p->info);
        inorder(p->right);
    }
}

void del_leaf(node *p, node *c)
{
    if (c == p->left)
    {
        p->left = NULL;
    }
    else if (c == p->right)
    {
        p->right = NULL;
    }
    free(c);
    printf("\n Node is deleted...");
}
void del_one(node *p, node *c)
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
    printf("\nNOde is deleted..");
}

void del_two(node *c)
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
        del_leaf(p, lft);
    }
    else
    {
        del_one(p, lft);
    }
}

void del(int x)
{
    int f = 0;
    node *c, *p;
    p = c = root;

    while (c != NULL)
    {
        if (x == c->info)
        {
            f = 1;
            break;
        }
        else if (x < c->info)
        {
            p = c;
            c = c->left;
        }
        else if (x > c->info)
        {
            p = c;
            c = c->right;
        }
    }

    if (f == 1)
    {
        if (c->left == NULL && c->right == NULL)
        {
            del_leaf(p, c);
        }
        else if (c->left != NULL && c->right != NULL)
        {
            del_two(c);
        }
        else
        {
            del_one(p, c);
        }
    }
    else
    {
        printf("\nNode is NOT found ");
    }
}
