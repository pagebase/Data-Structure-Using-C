#include <stdio.h>
#include <stdlib.h>

int main()
{
    for (int i = 1; i < 1000000000; printf("%d\n", i++))
        ;
    return 0;
}