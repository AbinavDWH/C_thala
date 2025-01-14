#include<stdio.h>
int main(){
    int a,b;
    float c,d;
    scanf("%d %d",&a,&b);
    scanf("%f %f",&c,&d);
    int e = a+b;
    int f = a-b;
    float x = c+d;
    float y =c-d;
    printf("%d %d\n",e,f);
    printf("%.1f %.1f",x,y);
    return 0;
}