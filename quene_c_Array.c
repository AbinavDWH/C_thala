#include<stdio.h>

#define MAX 5

int arr[MAX];
int front=-1;
int rear=-1;

void ins(int x){
    if(rear==(front-1)%MAX){
        printf("over flow\n");
    }
    else{
        if(front==-1){
            arr[++front]=x;
            rear++;
        }
        else{
            arr[(++rear)%MAX]=x;
            rear=rear%MAX;
        }

    }
}

void deq(){
    if(front==-1){
        printf("under flow");
    }
    else{
        printf("%d\n",arr[front]);
        
        if(front==rear){
            front=rear=-1;
        }
        else front=(front+1)%MAX;
    }
}

void dis(){
    int i = front;
    while (1) {
        printf("%d ", arr[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
}

int main(){
    int n,ele;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&ele);
        ins(ele);
    }

    do{
        scanf("%d",&n);
        deq();
        dis();
        printf("\n");
    }while (n!=-1);
    
    
}