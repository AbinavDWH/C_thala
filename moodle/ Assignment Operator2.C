#include<stdio.h>
int main(){
    int x =2,y=18,z=12;
    x += y;
    printf("x = %d\n",x);
    y*=2;
    printf("y = %d\n",y);
    z/=5;
    printf("z = %d\n",z);
    x%=7;
    printf("x = %d",x);
    return 0;
}