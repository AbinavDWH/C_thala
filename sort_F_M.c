#include<stdio.h>
int main(){
    int n;scanf("%d",&n);
    int arr[n],ai[n];
    for(int i=0;i<n;i++){
        scanf("%d %d",&ai[i],&arr[i]);
    }
    for(int i=0;i<n;i++){
        int temp;
        for(int j=0+i;j<n;j++){
            if(i!=j &&arr[i]<arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                 temp=ai[i];
                ai[i]=ai[j];
                ai[j]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
if(ai[i]==0)
    printf("%d ",arr[i]);}
    //printf("\n");
    for(int i=0;i<n;i++){
        if(ai[i] ==1)
        printf("%d ",arr[i]);
    }
    printf("\a");
}