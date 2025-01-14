#include<stdio.h>
int main(){
    int w,x,y;
    scanf("%d\n%d\n%d",&w,&x,&y);
    int profit =((w*x)-(w*y))-100;
    printf("%d",profit);
    return 0;
}