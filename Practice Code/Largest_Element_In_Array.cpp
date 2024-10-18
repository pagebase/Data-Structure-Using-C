#include<stdio.h>
int main()
{
    int arr[]={-1,0,1,2,3,4,5,6,7,8,9,10,10,100};
    int sizeOfArray=sizeof(arr)/sizeof(arr[0]);//sizeOfArray=13;
    int maxValue=arr[0];//Assuming 1st element is largest.
    for(int i=1;i<sizeOfArray;i++)
    {
        if(arr[i]>maxValue)
        {
            maxValue=arr[i];//Updating at every iteration.
        }
    }
    printf("Max Value: %d",maxValue);
    return 0;
}