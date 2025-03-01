#include <stdio.h>

// void moveValueToRightSideByOne(int arr[], int);
void storeValueInArrayThroughRecursioin(int arr[], int, int);

int main()
{
    int arr[5];
    int arraySize = 5;
    int index = 0;
    printf("Before: ");
    for (int i = 0; i < arraySize; i++)
    {
        printf("Before: %d\t", arr[i]);
    }
    printf("\n");
    storeValueInArrayThroughRecursioin(arr, arraySize, index);
    return 0;
}

void storeValueInArrayThroughRecursioin(int arr[], int arraySize, int index)
{
    if (index == arraySize)
    {
        printf("After: ");
        for (int i = 0; i < arraySize; i++)
        {
            printf("%d\t", arr[i]);
        }
        return;
    }
    else
    {
        arr[index] = index + 1; //  1 2 3 4 5
        storeValueInArrayThroughRecursioin(arr, arraySize, index + 1);
    }
}