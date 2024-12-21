#include<stdio.h>

int isPrime(int n){
    int count=0;
    for(int i=2;i<=n/2;i++){
        if(n%i==0){
            count++;
            break;
        }
    }
    if(count ==0) return 1;
    else return 0;
}

int factor(int arr[],int n){
    int i=0;
    for(int j=1;j<=n;j++){
        if(n%j==0){
            arr[i]=j;
            i++;
        }
    }
    return i;
}

int isCoprime(int n1,int n2){
    int arr1[n1],arr2[n2],c=0;
    int or1=factor(arr1,n1);
    int or2=factor(arr2,n2);
    for(int i=0;i<or1;i++){
        for(int j=0;j<or2;j++){
            if(arr1[i]==arr2[j]) c++;
        }
    }
    if(c==1) return 1;
    else return 0;
}


int main(){
    int a;
    scanf("%d",&a);
    if(isPrime(a)){
        printf("%d",a-1);
    }
    else{
        int count=0;
        for(int i=1;i<a;i++){
            if(isCoprime(i,a)){
                count++;
            }
        }
        printf("%d",count);
    }
}