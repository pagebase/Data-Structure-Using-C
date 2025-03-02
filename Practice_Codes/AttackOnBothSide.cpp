#include <stdio.h>
#define SIZE 10
int main()
{
    int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int firstIndex = 0;
    int lastIndex = SIZE - 1;
    // printf("Hello");
    while (firstIndex <lastIndex)
    {
        printf("%d\t", arr[firstIndex]);
        printf("%d\t", arr[lastIndex]);
        firstIndex++;
        lastIndex--;
    }
    return 0;
}