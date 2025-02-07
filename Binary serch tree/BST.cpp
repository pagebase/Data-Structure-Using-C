#include<stdio.h>
// #include<alloc.h>
// #include<conio.h>
// #include<process.h>
#include<stdlib.h>
struct    node
{
 node  *left;
 int   info;
 node   *right;
}*root;
node*   create();
int     count_leaf(node*);
void	insert(int);
int     count_total(node*);
void    preorder(node*);
void    search(int);
void    inorder(node*);
void    postorder(node*);
int   main()
{
    int   ch,n,a;
    //  clrscr();
do
{
     printf("\nEnter your choice ");
     printf("\n1:Insert\n2:Preorder\n3:Inorder\n4:Postorder\n5:Count Leaf\n6:Count Total\n7:Search \n8:Exit ");
scanf("%d",&ch);
switch(ch)
{
     case   1:
	printf("\nEnter val to insert:  ");
	scanf("%d",&n);
	insert(n);
	break;
     case     2:
		preorder(root);
		break;
	case    3:
		inorder(root);
		break;
	case	4:
		postorder(root);
		break;
	case    5:
		a=count_leaf(root);
		printf("\nTotal Leaf=%d",a);
		break;
	case    6:
		a=count_total(root);
		printf("\nTotal Node count=%d",a);
		break;
	case	7:
		printf("\nEnter val to search=");
		scanf("%d",&a);
		search(a);
		break;
	case     8:
		exit(1);
    }
}while(ch!=8);
// getch();
return 0;
}

node*    create()
{
    node  *z;
    z=(node*)malloc(sizeof(node));
    return(z);
}

void    search(int   srch)
{
    int   f=0;
    node    *p;
    p=root;

 while(p!=NULL)
 {
    if(srch==p->info)
    {
       f=1;
       break;
    }
    else   if(srch<p->info)
    {
	p=p->left;
    }
    else   if(srch>p->info)
    {
	p=p->right;
    }
 }

 if(f==1)
    printf("\nNode is FOund ");
 else
    printf("\nNOde is NOT found");
}
int    count_total(node   *p)
{
   if(p==NULL)
   {
      return(0);
   }
   else   if(p->left==NULL&&p->right==NULL)
   {
        return(1);
    }
    else
    {
          return(count_total(p->left)+count_total(p->right)+1);        
    }
}
int     count_leaf(node   *p)
{
    if(p==NULL)
    {
	return(0);
    }
    else   if(p->left==NULL&&p->right==NULL)
    {
       printf("\t%d",p->info);
       return(1);
    }
    else
    {
       return(count_leaf(p->left)+count_leaf(p->right));
    }
}
void    insert(int   x)
{
   node   *p,*temp;
   p=create();
   p->left=NULL;
   p->info=x;
   p->right=NULL;
if(root==NULL)
{
    root=p;
    printf("\nNode is inserted..");
}
else
{
    temp=root;

  while(temp!=NULL)
{
    if(p->info<temp->info)
    {
           if(temp->left==NULL)
	   {
                 temp->left=p;
	  	 printf("\nNode is inserted..."); 
		 break;
	   }
           else
           {
                temp=temp->left;
           }
     } 
   else  if(p->info>temp->info)
    {
           if(temp->right==NULL)
	   {
                 temp->right=p;
	  	 printf("\nNode is inserted..."); 
		 break;
	   }
           else
           {
                temp=temp->right;
           }
     } 
   }
}
}

void    preorder(node   *p)
{
 	if(p!=NULL)
        {    
            printf("\t%d",p->info);
	    preorder(p->left);
            preorder(p->right);
        }
}

void    inorder(node   *p)
{
 	if(p!=NULL)
        {    
            inorder(p->left);
	    printf("\t%d",p->info); 	
            inorder(p->right);
        }
}


void    postorder(node   *p)
{
 	if(p!=NULL)
        {    
            postorder(p->left);
            postorder(p->right);
	    printf("\t%d",p->info);
        }
}