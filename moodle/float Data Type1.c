#include <stdio.h>

int main() 
{
    float num1 = 5.34, num2 = 125.789f, result;
    printf("Given float values are num1 = %f, num2 = %f\n", num1, num2);
    result = num2 / num1;
    printf("The result after dividing in float format = %f\n",result );
    printf("The result after dividing in exponential format = %e\n",result );
    return 0;
}