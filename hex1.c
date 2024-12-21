
#include<stdio.h>
int main(){int i=0;
char s[1000];
while(1){
    int f=scanf(" %x",&s[i]);
if(f==0){
    s[i]='\0';
    break;
}i++;
}printf("%s",s);
}