#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int s1=0,s2=0;
    int i1[n],i2[n];
    for(int i=0;i<n;i++){
        scanf("%d %d",&i1[i],&i2[i]);
        s1+=i1[i];
        s2+=i2[i];
    }
    printf("%.2f\n%.2f",(float)s1/n,(float)(s2)/n);
}