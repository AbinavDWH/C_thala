#include<stdio.h>
#include<stdlib.h>

struct quene_ll
{
    /* data */
    int data;
    struct quene_ll *next;
}*front=NULL,*rear=NULL;

typedef struct quene_ll NODE;

void enquen(int data){
    NODE *new_node=(NODE*)malloc(sizeof(NODE));
    new_node->data=data;
    new_node->next=NULL;
    if(front==NULL && rear==NULL){
        front=rear=new_node;
    }
    else{
        rear->next=new_node;
        rear=new_node;
    }

}

void dequen(){
    NODE *temp=front;
    if(front==NULL){
        printf("underflowing1");
    }
    else{
        if(front->next==NULL){
            front=rear=NULL;
        }
        else{
            front=front->next;
            free(temp);
        }
    }
}

void dis(){
    if(front==NULL){
        printf("Umderflowing");
    }
    NODE *temp=front;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
        }
}

int main(){
    int n,ele;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&ele);
        enquen(ele);
    }
    dis();
    do{
        printf("deq");
        scanf("%d",&n);
        dequen();
        dis();
        printf("\n");
    }while (n!=-1);
        
}

