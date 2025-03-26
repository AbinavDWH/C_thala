// You are using GCC
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next,*pre;
};

typedef struct node NODE;

void insend(NODE **head,int x){
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

void insbeg(NODE **head,int x){
    NODE *nn=(NODE *)malloc(sizeof(NODE));
    nn->data=x;
    nn->next=*head;nn->pre=NULL;
    (*head)->pre=nn;
    *head=nn;
}

void dis(NODE *temp){
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

void insbegpos(NODE **head,int n,int x){
    NODE *temp=*head;
    int flag=0;
    while(temp!=NULL){
        if(temp->data==n){
        flag=1;
        break;}
        temp=temp->next;
    }
    if(flag==0){
    printf("Value not found in the list");
    return ;
        
    }
    NODE *nn=(NODE *)malloc(sizeof(NODE));
    nn->data=x;
    nn->next=temp;
    nn->pre=temp->pre;
    if (temp->pre != NULL)
    temp->pre->next = nn;
else
    *head = nn;  // Update head if inserting at the beginning
temp->pre = nn;
}

void insendpos(NODE **head,int n,int x){
    NODE *temp=*head;
    int flag=0;
    while(temp!=NULL){
        if(temp->data==n){
        flag=1;
        break;}
        temp=temp->next;
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
    NODE *temp=*head,*summa=*head;
    temp=temp->next;
    temp->pre=NULL;
    printf("The linked list after deletetion from the beginning is:");
    free(summa);
    
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

void delbegpos(NODE **head,int n){
    NODE *temp=*head;
    int flag=0;
    while(temp!=NULL){
        if(temp->data==n){
            flag=1;
            break;
        }
        temp=temp->next;
    }
    if(flag==0){
    printf("Value not found in the list");
    return ;
        
    }
    NODE *tmp=temp->pre;
    temp->pre->pre->next=temp;
    temp->pre=temp->pre->pre;
    free(tmp);
}

void delafpos(NODE **head,int x){
    NODE *temp=*head;int f=0;
    while(temp!=NULL && temp->next!=NULL){
        if(temp->data==x){
            f=1;
            break;
        }
        temp=temp->next;
    }
    if(f==0){
        printf("%d\n",temp->data);
        return ;
    }
    NODE *tmp=temp->next;
    temp->next=temp->next->next;
    temp->next->next->pre=temp;
    free(tmp);
}



int main(){
    int n,input,flag=0,modi;
    NODE *list=NULL;
    do{
        scanf("%d",&input);
        if(input==11){
break;
        }
        switch(input){
            case 1:
            while(1){
                scanf("%d",&n);
                if(n!=-1){
                insend(&list,n);
                    
                }
                else
                break;
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
                insbeg(&list,n);
                printf("The linked list after insertion at the beginning is:\n");
                dis(list);
            }
            break;
            case 4:
            if(flag==1){
                scanf("%d",&n);
                insend(&list,n);
                printf("The linked list after insertion at the end is:\n");
                dis(list);
            }
            break;
            case 5:
                scanf("%d %d",&modi,&n);
                insbegpos(&list,modi,n);
                dis(list);
                break;
            case 6:
                scanf("%d %d",&modi,&n);
                insendpos(&list,modi,n);
                dis(list);
                break;
            case 7:
                delbeg(&list);
                dis(list);
                break;
            case 8:
                delend(&list);
                dis(list);
                break;
            case 9:
                scanf("%d",&n);
                delbegpos(&list,n);
                dis(list);
                break;
            case 10:
                    scanf("%d",&n);
                    delafpos(&list,n);
                    dis(list);
                    break;
            default:
            printf("lll");
            
        }
    }while(input!=11);
}

