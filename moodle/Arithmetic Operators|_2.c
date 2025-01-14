#include <stdio.h>

int main() 
{
    char c1 = 'A', c2 = 'D';
    printf("c1 = %d\n", c1);
    printf("c1 + c2 = %d\n", (c1 + c2));
    printf("c1 + c2 + 5 = %d\n", (c1 + c2 + 5));
    printf("Result = %d", (c1 + c2 + '5'));
    return 0;
}