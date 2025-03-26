#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
}*head=NULL,*tail=NULL;


void insert(int x){
    struct node *nn=(struct  node *)malloc(sizeof(struct node));
    nn->data=x;
    nn->next=NULL;
    if(head==NULL)
    head=nn;
    else{
        struct node *temp=head;
        while (temp->next!=NULL)
        {
            /* code */
            temp=temp->next;
        }
        temp->next=nn;
        
        
    }
}

void display_List(){
    tail=head;
    while(tail!=NULL){
        printf("%d ",tail->data);
        tail=tail->next;
    }
}

void deleteNode(int x){
    int i=0;
    tail=head;
    while (tail!=NULL)
    {
        /* code */
        tail=tail->next;
        i++;
    }
    tail=head;
    if(i<x){
        printf("neo la paru");
    }
    
    else if(x==1){
        head=head->next;
        display_List();
        free(tail);
    }
    else if(x==i){
        while(tail->next->next!=NULL){
            tail=tail->next;
        }
        tail->next=NULL;
        display_List();
    }
    else{
        for(int j=0;j<x-2;j++){
            tail=tail->next;
        }
        tail->next=tail->next->next;
        display_List();
    }
    
}
int main(){
    int n_ele,ele,pos;
    scanf("%d",&n_ele);
    for(int i=0;i<n_ele;i++){
        scanf("%d",&ele);
        insert(ele);
    }
    scanf("%d",&pos);
    deleteNode(pos);
}
 