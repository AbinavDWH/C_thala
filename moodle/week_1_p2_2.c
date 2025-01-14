#include<stdio.h>
int main(){
    int i;long l;char a;float f;double d;
    scanf("%d %ld %c %f %lf",&i,&l,&a,&f,&d);
    printf("%d\n%ld\n%c\n%.3f\n%.9lf",i,l,a,f,d);
    return 0;
}