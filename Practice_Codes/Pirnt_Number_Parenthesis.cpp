#include<stdio.h>

int main()
{
    int n;
    printf("Enter number: ");
    scanf("%d",&n);
    for(int i=1; i<=n; printf("(",i++));
    for(int i=1; i<=n; printf(")",i++));
    return 0;
}