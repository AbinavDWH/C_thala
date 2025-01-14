#include<stdio.h>
int main(){
    int x=4,y;
    y=x++;
    printf("y = %d x = %d\n",y,x);
    y = ++x;
    printf("y = %d x = %d\n",y,x);
    y=x--;
    printf("y = %d x = %d\n",y,x);
    y = --x;
    printf("y = %d x = %d\n",y,x);
    return 0;
}