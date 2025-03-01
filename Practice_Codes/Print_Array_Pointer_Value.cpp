#include <stdio.h>
#include <stdlib.h>
void moveValueToRightSide(int arr[], int arraySize, int firstIndex, int lastIndex);
void getInputByUser(int arr[], int arraySize, int firstIndex, int lastIndex);

int main()
{
    int num;
    printf("Enter array arraySize: ");
    scanf("%d", &num);

    int firstIndex = 0;
    int lastIndex = num;
    int arraySize = num;

    int *arr = (int *)malloc((num * 2) * sizeof(int)); // |  1|  2|  3|  4|  5|  6|  7|  8|  9| 10|
    printf("firstIndex: %d\n", firstIndex);
    printf("lastIndex: %d\n", lastIndex);
    printf("Array arraySize: %d\n", arraySize);
    getInputByUser(arr, arraySize, firstIndex, lastIndex);
    return 0;
}

void getInputByUser(int arr[], int arraySize, int firstIndex, int lastIndex)
{
    for (int i = 0; i < arraySize-1; i++)
    {
        printf("Enter [%d]th value: ", i);
        scanf("%d", &arr[i]);
        moveValueToRightSide(arr, arraySize, firstIndex, lastIndex);
        arr[i + 1] = arr[i] * arr[i];
    }
}

void moveValueToRightSide(int arr[], int arraySize, int firstIndex, int lastIndex)
{
    for (int i = lastIndex; i >= firstIndex + 2; i--)
    {
        arr[lastIndex] = arr[lastIndex - 1];
    }
    lastIndex++;
    firstIndex++;
    for(int i=0; i<arraySize*2; i++)
    {
        printf("%d\t",arr[i]);
    }
}