#include<stdio.h>

#define MAX 100

int arr[MAX];
int front = -1;
int rear = -1;

void eq(int x,int f) {
    if(front ==-1){
        arr[++front]=x;
        rear++;
    }
    else if(rear==MAX-1){
        printf("overflow");
    }
    else{
        arr[++rear]=x;
    }
}

void deq() {
    if(front==-1 || front>rear){
        printf("underflow");
    }
    else{
        printf("%d",arr[front++]);
        if (front>rear)
        {
            front=rear=-1;
        }
        
    }
}

void dis(){
    
    for(int i=front;i<=rear;i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    int n,ele;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&ele);
        eq(ele,n);
    }
    dis();printf("\n");
    deq();printf("\n");
    dis();
}