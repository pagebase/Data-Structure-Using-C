#include<stdio.h>
#define SIZE 10
void doMyJob(int arr[], int, int);

int main()
{
    int arr[SIZE];
    int arraySize=SIZE;
    int index=0;
    doMyJob(arr, arraySize, index);
    return 0;
}

void doMyJob(int arr[], int arraySize, int index)
{
    if(index>arraySize-1)
    {
        printf("After: ");
        for(int i=0; i<arraySize; i++)
        {
            printf("%d\t",arr[i]);
        }
        return;
    }
    printf("Enter [%d]th value: ",index);
    scanf("%d",&arr[index]);
    doMyJob(arr, arraySize, index+1);
}