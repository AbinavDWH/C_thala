// You are using GCC
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next,*pre;
}*head=NULL,*tail=NULL;

typedef struct node NODE;

void insert(int x){
    NODE *nn=(NODE *)malloc(sizeof(NODE));
    nn->data=x;
    nn->next=NULL;
    nn->pre=NULL;
    if(head==NULL && tail ==NULL){
        head=nn;
    }
    else if(tail==NULL && head !=NULL){
        tail=nn;
        head->next=nn;
        nn->pre=head;
    }
    else{
        tail->next=nn;
        nn->pre=tail;
        tail=nn;
    }
}

void display(){
    NODE *temp=head;
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
        insert(ele);
    }
    display();
}