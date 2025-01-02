#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n,tmp=0;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            // if(i<j){
            //     tmp=n-i;
            // }
            // else tmp=n;
           if(i==n-1||i==0 || j==0||j==n-1) printf("%d ",tmp);
            else printf("  ");
    }printf("\n");
    }
    
    
  
  	

    
}