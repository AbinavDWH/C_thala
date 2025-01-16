#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    char a[1000];
    scanf("%s",a);
    for(int i=0;i<10;i++){
        int c=0;
        for(int j=0;j<strlen(a);j++){
            if(i==(a[j])-'0'&&isdigit(a[j])){
                c++;
            }
           
        }printf("%d ",c);
    }
    return 0;
}
