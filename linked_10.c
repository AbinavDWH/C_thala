// You are using GCC
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next,*pre;
};

typedef struct node NODE;

void insend(NODE **head,x){
    NODE *nn=(NODE *)malloc(sizeof(NODE));
    nn->data=x;
    nn->next=NULL;nn->pre=NULL;
    if(*head==NULL){
        *head=nn;
    }
    else{
        NODE *temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=nn;
        nn->pre=temp;
    }
}

void insbeg(NODE **head,x){
    NODE *nn=(NODE *)malloc(sizeof(NODE));
    nn->data=x;
    nn->next=*head;nn->pre=NULL;
    *head->pre=nn;
    *head=nn;
}

void dis(NODE *temp){
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

void insbegpos(NODE **head,n,x){
    NODE *temp=*head;
    int flag=0
    while(temp!=NULL){
        if(temp->data==n){
        flag=1
        break;}
    }
    if(flag==0){
    printf("Value not found in the list");
    return ;
        
    }
    NODE *nn=(NODE *)malloc(sizeof(NODE));
    nn->data=x;
    nn->next=temp;
    nn->pre=temp->pre;
    temp->pre=nn;
}

void insendpos(NODE **head,n,x){
    NODE *temp=*head;
    int flag=0
    while(temp!=NULL){
        if(temp->data==n){
        flag=1
        break;}
    }
    if(flag==0){
    printf("Value not found in the list");
    return ;
        
    }
    NODE *nn=(NODE *)malloc(sizeof(NODE));
    nn->data=x;
    nn->next=temp->next;
    nn->pre=temp;
    temp->next=nn;
    
    
}

void delbeg(NODE **head){
    NODE *temp=*head;
    *head=*head->next;
    *head->pre=NULL;
    printf("The linked list after deletetion from the beginning is:")
    free(temp);
    
}

void delend(NODE **head){
    NODE *temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    
    NODE *tmp=temp;
    temp->pre->next=NULL;
    free(tmp);
}

void delbegpos(NODE **head,n,x){
    NODE *temp=*head;
    int flag=0;
    while(temp!=NULL){
        if(temp->data==n){
            flag=1;
            break;
        }
    }
    if(flag==0){
    printf("Value not found in the list");
    return ;
        
    }
    NODE *tmp=temp->pre->pre;
    temp->pre->pre->next=temp;
    temp->pre=temp->pre->pre;
    
}

int main(){
    int n,input,flag=0,modi;
    NODE *list=NULL;
    do{
        scanf("%d",input);
        switch(input){
            case 1:
            while(1){
                scanf("%d",n);
                if(n!=-1){
                insend(&list,n)
                    break;
                }
            }
            flag=1;
            printf("LINKED LIST CREATED\n");
            break;
            case 2:
            if(flag==1){
                dis(list);
            }
            else{
                printf("The list is empty\n");
            }
            break;
            case 3:
            if(flag==1){
                scanf("%d",&n);
                insbeg(&head,n);
                printf("The linked list after insertion at the beginning is:\n");
                
            }
            break;
            case 4:
            if(flag==1){
                scanf("%d",&n);
                insend(&head,n);
                printf("The linked list after insertion at the end is:\n");
            }
            break;
            case 5:
                scanf("%d %d",modi,n);
                insbegpos(&head,modi,n);
                dis(head);
                break;
            case 6:
                scanf("%d %d",modi,n);
                insbegpos(&head,modi,n);
                dis(head);
                break;
            case 7:
                delbeg(&head);
                dis(head);
                break;
            case 8:
                delend(&head);
                dis(head);
                break;
            case 9:
            
            
            
        }
    }while(input!=11);
}

