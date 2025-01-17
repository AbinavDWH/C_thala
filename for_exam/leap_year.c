#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    if(n%100==0&&n%400==0)
    printf("leap year");
    else if(n%4==0 && n%100==0&&n%400!=0){
        printf("not a leap year");
    }
    else if(n%4==0 && n%100!=0)
    printf("leap year");
}