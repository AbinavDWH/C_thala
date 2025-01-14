#include<stdio.h>
int main (){
    int x=16;
    printf("+x = %d\n",(+x));
    printf("-x = %d\n",(-x));
    printf("x = %d\n",x);
    printf("++x = %d\n",(++x));
    printf("x = %d\n",x);
    printf("x++ = %d\n",(x++));
    printf("x = %d\n",x);
    printf("--x = %d\n",(--x));
    printf("x = %d\n",x);
    printf("x-- = %d\n",(x--));
    printf("x = %d",x);
    return 0;
}