#include<stdio.h>

int main(){
    int tL,tH;
    scanf("%d %d",&tL,&tH);
    int bird,animal;
    animal=(tH-2*tL)/2;
    bird=tL-animal;
    printf("%d %d",bird,animal);
}