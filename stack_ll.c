#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*top=NULL;

typedef struct node NODE;

void push(int x){
    NODE *nn=(NODE *)malloc(sizeof(NODE));
    nn->data=x;
    nn->next=top;
    top=nn;
    
    
}

void pop(){
    NODE *temp=top;
    top=top->next;
    free(temp);
}

void peek(){
    if(top==NULL) return;
    printf("%d",top->data);
}

void display(){
    NODE *temp=top;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next; 
    }
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        push(x);
    }
    pop();
    display();
}