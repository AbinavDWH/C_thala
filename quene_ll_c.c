#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*front=NULL,*rear=NULL;

typedef struct node NODE;

void enqueue(int item){
    NODE *nn=(NODE *)malloc(sizeof(NODE));
    nn->data=item;
    nn->next=NULL;
    if(front==NULL){
        front=rear=nn;
        nn->next=front;
    }
    else{
        nn->next=front;
        rear->next=nn;
        rear=nn;
    }
}

void dequeue(){
    if(front==NULL) return;
    else if (rear==front)
    {
        /* code */
        free(front);
        front=rear=NULL;
    }
    
    else{
        NODE *temp=front;
        front=front->next;
        rear->next=front;
        free(temp);
    }
}

void disp(){
    NODE *temp=front;
    if(front==NULL) return;
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=front);
}

int main(){
    int n,ele;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&ele);
        enqueue(ele);
    }
    disp();
    
    printf("\n");
    dequeue();
    disp();
}