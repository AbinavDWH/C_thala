#include<stdio.h>
#include<string.h>
int main(){
    char *a="-1234567.90";
    printf("%d",-*a-'0');
}