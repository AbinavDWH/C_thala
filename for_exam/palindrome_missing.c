#include<stdio.h>
#include<string.h>
int main(){
    char a[1000];
    
    scanf("%s",a);
    int l=strlen(a);
    char b[l];
    for(int i=0;i<l;i++){
  //      char tmp=a[i];
        b[i]=a[l-i-1];
        
    }b[l]='\0';
    for(int i=0;i<l;i++){
        if(a[i]!=b[i]){
            printf("%c",a[i]);
            break;
        }
    }
}