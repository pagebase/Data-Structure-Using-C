#include <stdio.h>
#include <stdlib.h>

void moveValueToRightSide(int arr[], int *arraySize, int firstIndex, int lastIndex);
void getInputByUser(int arr[], int *arraySize, int firstIndex, int lastIndex);

int main()
{
    int num;
    printf("Enter array size: ");
    scanf("%d", &num);

    int firstIndex = 0;
    int lastIndex = num - 1;  // Index should be num-1 to fit the last element
    int arraySize = num;

    int *arr = (int *)malloc((num * 2) * sizeof(int)); // Allocate double the memory initially
    if (!arr) {  // Check if malloc was successful
        printf("Memory allocation failed.\n");
        return -1;
    }

    printf("firstIndex: %d\n", firstIndex);
    printf("lastIndex: %d\n", lastIndex);
    printf("Array size: %d\n", arraySize);

    getInputByUser(arr, &arraySize, firstIndex, lastIndex);

    // Free the allocated memory
    free(arr);

    return 0;
}

void getInputByUser(int arr[], int *arraySize, int firstIndex, int lastIndex)
{
    for (int i = 0; i < *arraySize; i++)
    {
        printf("Enter [%d]th value: ", i);
        scanf("%d", &arr[i]);
        moveValueToRightSide(arr, arraySize, firstIndex, lastIndex);
        
        // Update array size if you are shifting elements
        arr[*arraySize] = arr[i] * arr[i];  // Store the square of the number at the next position
        (*arraySize)++;  // Increase array size
    }
}

void moveValueToRightSide(int arr[], int *arraySize, int firstIndex, int lastIndex)
{
    // Shift values right from the end
    for (int i = *arraySize - 1; i > lastIndex; i--)
    {
        arr[i] = arr[i - 1];
    }

    // Print the array contents
    for (int i = 0; i < *arraySize; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}