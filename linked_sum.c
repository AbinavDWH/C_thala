// You are using GCC
// You are using GCC
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data,ex;
    struct node *next;
}*head=NULL,*mod=NULL;

typedef struct node NODE;

void ins(NODE **hi,int x,int ex){
    NODE *temp=(NODE *)malloc(sizeof(NODE));
    temp->data=x;
    temp->ex=ex;
    temp->next=NULL;
    if(*hi==NULL){
        *hi=temp;
    }
    else{
        NODE *nn=*hi;
        while(nn->next!=NULL){
            nn=nn->next;
        }
        nn->next=temp;
    }
}

void dis(NODE *temp){
    while(temp!=NULL){
        printf(" %dx^%d ",temp->data,temp->ex);
        if(temp->next!=NULL)
        printf("+");
        temp=temp->next;
    }printf("\n");
}
/*
void add(){
    NODE *temp1=head,*temp2=NULL;
    while(temp1!=NULL){
        int sum=temp1->data;
        int ex=temp1->ex;
        temp2=temp1->next;
        NODE *tmp=temp1;
        while(temp2!=NULL){
            if(temp2->ex==ex){
                sum+=temp2->data;
                tmp->next=temp2->next;
                NODE *f=temp2;
                temp2=temp2->next;
                tmp=tmp->next;
                free(f);
            }
            else{
                temp2=temp2->next;
                tmp=tmp->next;
            }
            
        }ins(&mod,sum,ex);
        temp1=temp1->next;
    }
} */
void add(){
    NODE *temp1=head,*temp2=NULL;
    while(temp1!=NULL){
        int sum=temp1->data,ex=temp1->ex;
        
        temp2=temp1->next;
        NODE *change=temp1;
        while(temp2!=NULL){
            if(ex==temp2->ex){
                sum+=temp2->data;
                NODE *f=temp2;
                change->next=temp2->next;
                temp2=temp2->next;
                change=change->next;
                free(f);
            }
            else{
                change=change->next;
                temp2=temp2->next;
            }
        }ins(&mod,sum,ex);
        temp1=temp1->next;
    }    
}




int main(){
    int n,d,ex;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&d,&ex);
        ins(&head,d,ex);
    }
    printf("Original polynomial:");
    dis(head);
    printf("Simplified polynomial:");
    add();
    dis(mod);
}