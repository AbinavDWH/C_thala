// You are using GCC
#include<stdio.h>
#include<stdlib.h>

struct node {
    int x,ex;
    struct node *next;
}*head=NULL,*head1=NULL;

typedef struct node NODE;

void ins(int x,int ex){
    NODE *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->x=x;
    new_node->ex=x;
    new_node->next =head;
    
    head=new_node;
   
}
void ins_new(int x,int ex){
    NODE *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->x=x;
    new_node->ex=ex;
    new_node->next =NULL;
    if(head1!=NULL)
    head1=new_node;
    
    else{
        NODE *temp=head1;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
    }
    
    
}

void pol_add(){
    NODE *temp1=head,*temp2=head;
   while(temp1!=NULL || temp2!=NULL){
       if(temp1!=NULL && temp2!=NULL){
           if(temp1->ex==temp2->ex){
               int x=temp1->x+temp2->x;
               ins_new(x,temp1->ex);
           }
           else if(temp1->ex>temp2->ex){
               ins(temp1->x,temp1->ex);
               temp1=temp1->next;
           }
           else if(temp1->ex<temp2->ex){
               ins(temp2->x,temp2->ex);
               temp2=temp2->next;
           }
       }else if(temp1!=NULL){
           ins_new(temp1->x,temp1->ex);
           temp1=temp1->next;
       }
       else{
           ins_new(temp2->x,temp2->ex);
           temp2=temp2->next;
       }
   }
    
}

void display(){
    NODE *temp=head1;
    while(temp!=NULL){
        printf("%dx^%d",temp->x,temp->ex);
        if(temp->next !=NULL){
            printf(" + ");
        }
    }
}

void display_old(){
    NODE *temp=head;
    do{
        printf("%dx^%d",temp->x,temp->ex);
        if(temp->next->x>temp->x){
            printf(" + ");
        }
        temp=temp->next;
    }while(temp->ex>temp->next->ex || temp==NULL);
    printf("\n");
    do{
        printf("%dx^%d",temp->x,temp->ex);
        if(temp->next->x>temp->x){
            printf(" + ");
        }
        temp=temp->next;
    }while(temp->ex>temp->next->ex || temp==NULL);
}

int main(){
    int ex,x;
    
    while(1){
        scanf("%d %d",&x,&ex);
        if(x==0 && ex==0) break;
        ins(x,ex);
}
    
    while(1){
        scanf("%d %d",&x,&ex);
        if(x==0 && ex==0) break;
        ins(x,ex);
}
    display_old();
    pol_add();
    display();
    
}