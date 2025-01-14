#include<stdio.h>
int main(){
    char a;
    int m1,m2,m3;
    scanf("%c\n",&a);
    scanf("%d %d %d",&m1,&m2,&m3);
    int avg = (m1+m2+m3)/3;
    printf("%c\n",a);
    printf("%d",avg);
    return 0;
    
}