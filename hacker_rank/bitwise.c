#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) {
  //Write your code here.
  int an=0,o=0,e=0;int tmp;
  for(int i = 1; i <=n; i++) {
    for(int j = i + 0; j <= n; j++) {
        // Your code here
if(i!=j){

        tmp=i&j;
      //  printf("%d %d",tmp,j);
        if(an<tmp && k>tmp){
            an=tmp;
        }
        tmp=i|j;
        if(o<tmp && k>tmp)
        o=tmp;
        tmp=i^j;
        if(e<tmp && k>tmp)
        e=tmp;}
    }
  }
  printf("%d\n%d\n%d",an,o,e);
    
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}