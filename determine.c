#include<stdio.h>
int main(){
    int arr[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    int det=0;
    for(int i=0;i<3;i++){
        det+=(arr[0][(i+2)%3]*(arr[1][i]*arr[2][(i+1)%3]-arr[1][(i+1)%3]*arr[2][i]));
    }
    printf("%d",det);
}