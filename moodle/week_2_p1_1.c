#include<stdio.h>
int main(){
    int ft,in;
    scanf("%d %d",&ft,&in);
    float cm =(ft*12*2.54)+(in*2.54);
    printf("%.2f",cm);
}