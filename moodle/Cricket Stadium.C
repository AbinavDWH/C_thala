#include<stdio.h>
int main(){
    int l,b;
    scanf("%d\n%d",&l,&b);
    int rope = 2*(l+b);
    int area = l*b;
    printf("%d\n%d",rope,area);
}