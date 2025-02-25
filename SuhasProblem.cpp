#include<stdio.h>
#include<stdlib.h>

void doMyJob(int arr[], int);

int main()
{
    int arraySize;
    printf("Enter array size: ");
    scanf("%d",&arraySize);
    int *arr=(int*)malloc(arraySize*sizeof(int));// Array has been created.

    //Enter elements by user.
    for(int i=0; i<arraySize; i++)
    {
        printf("Insert [%d]th element: ",i);
        scanf("%d",&arr[i]);
    }
    // printf("arraySize value: %d",arraySize);
    // while(j<6)
    // {
    //     printf("%d\t",arr[j]);
    //     j++;
    // }
    for(int j=0; j<arraySize; j++)
    {
        printf("%d\t",arr[j]);
    }

    doMyJob(arr, arraySize);
    free(arr);
    return 0;
}
void doMyJob(int arr[], int arraySize)
{
    int sum1=0;
    int sum2=0;
    int i=0;
    int j=0;
    int temp=0;
    int arraySizeCopy=arraySize;
    int arraySize_1=arraySize-1;

    // If array size id even.
    if(arraySize%2==0)
    {
        // Sum 1st half portion
        for(i=0; i<arraySizeCopy/2; i++)
        {
            sum1+=arr[i];
        }

        // Sum 2nd half portion.
        for(; i<arraySizeCopy; i++)
        {
            sum2+=arr[i];
        }

        // This will swap array value if 1st half portion is smaller than 2nd half portion.
        if(sum1<sum2)
        {
            while(j<arraySize_1)
            {
                temp=arr[j];
                arr[j]=arr[arraySize_1];
                arr[arraySize_1]=temp;
                j++;
                arraySizeCopy--;
            }
            
            // Print swapped array values.
            for(int k=0; k<arraySizeCopy; k++)
            {
                printf("%d\t",arr[k]);
            }
        }
    }
    else if(arraySize%2!=0)
    {
        int halfArray=arraySize/2;

        // Sum 1st half array portion.
        for(i=0; i<arraySize/2; i++)
        {
            sum1+=arr[i];
        }

        // Sum 2nd half array portion.
        for( i=halfArray; i<arraySize; i++)
        {
            sum2+=arr[i];
        }
        if(sum1<sum2)
        {
            while(j<arraySize_1)
            {
                temp=arr[j];
                arr[j]=arr[arraySize_1];
                arr[arraySize_1]=temp;
                j++;
                arraySizeCopy--;
            }
        }
    }
}