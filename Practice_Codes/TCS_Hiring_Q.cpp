#include<stdio.h>
#include<stdlib.h>
void go(int arr[],int );

int main()
{
    int arraySize;
    printf("Enter array size: ");
    scanf("%d",&arraySize);
    int *arr=(int*)malloc(arraySize*sizeof(int));// Array has been created.

    for(int i=0; i<arraySize; i++)
    {
        printf("Insert [%d]th element: ",i);
        scanf("%d",&arr[i]);
    }
    go(arr, arraySize);
    return 0;
}
void go(int arr[], int size)
{
    int sum1=0;
    int sum2=0;
    int j=0;
    int temp=0;
    int sizeMinusOne=size-1;
    if(size % 2==0)
    {
        for(int i=0; i<size/2; i++)
        {
            sum1+=arr[i];
        }

        for(int i=size/2; i<size; i++)
        {
            sum2+=arr[i];
        }

        if(sum1<sum2)
        {
            while(j<sizeMinusOne)
            {
                temp=arr[j];
                arr[j]=arr[sizeMinusOne];
                arr[sizeMinusOne]=temp;
                j++;
                sizeMinusOne--;
            }
            for(int i=0; i<size; printf("%d\t",arr[i++]));
        }
        else
        {
            for(int i=0; i<size; printf("%d\t",arr[i++]));
        }
    }
    else if(size%2!=0)
    {
        int set1=(size/2)-1;
        for(int i=0; i<=set1; i++)
        {
            sum1+=arr[i];
        }

        for(int i=(set1+1); i<size; i++)
        {
            sum2+=arr[i];
        }
        if(sum1<sum2)
        {
            while(j<sizeMinusOne)
            {
                temp=arr[j];
                arr[j]=arr[sizeMinusOne];
                arr[sizeMinusOne]=temp;
                j++;
                sizeMinusOne--;
            }

            for(int i=0; i<size; printf("%d\t",arr[i++]));
        }
        else
        {
            for(int i=0; i<size; printf("%d\t",arr[i++]));
        }
    }
}