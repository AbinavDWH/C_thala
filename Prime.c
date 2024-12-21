#include "Prime.h"
int isPrime(int n){
    int c=0;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            c++
            ;break;
        }
    }
    if(c==0) return 1;
    else return 0;
}