// You are using GCC
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    int ex;
    struct node* next,*pre;
}*pol1=NULL,*pol2=NULL,*result=NULL;

typedef struct node NODE;

NODE *ins(NODE *p,int x,int ex){
    NODE *temp=(NODE *)malloc(sizeof(NODE));
    temp->data=x;
    temp->ex=ex;
    temp->next=NULL;
    temp->pre=NULL;
    if(p==NULL){
        p=temp;
    }
    else{
        NODE *last=p;
        while(last->next!=NULL){
            last=last->next;
        }
        last->next=temp;
        temp->pre=last;
    }
    return p;
}

void in(int x,int ex){
    NODE *temp=(NODE *)malloc(sizeof(NODE));
    temp->data=x;
    temp->ex=ex;
    temp->next=NULL;
     temp->pre=NULL;
    if(result==NULL){
        result=temp;
    }
    else{
        NODE *last=result;
        while(last->next!=NULL){
            last=last->next;
        }
        last->next=temp;
        temp->pre=last;
    }
}


void pol_add(){
    NODE *p1=pol1,*p2=pol2;
    
    while(p1!=NULL || p2!=NULL){
        while(p1!=NULL && p2!=NULL){
            if(p1->ex==p2->ex){
                in(p1->data+p2->data,p1->ex);
                p1=p1->next;
                p2=p2->next;
            }
            else if(p1->ex>p2->ex){
                in(p1->data,p1->ex);
                p1=p1->next;
            }
            else{
                in(p2->data,p2->ex);
                p2=p2->next;
            }
        }
        if(pol1!=NULL){
            while(p1!=NULL){
                in(p1->data,p1->ex);
                p1=p1->next;
            }
        }
        if(pol2!=NULL){
            while(p2!=NULL){
                in(p2->data,p2->ex);
                p2=p2->next;
            }
        }
    }
}

void display(NODE *head){
    NODE *p=head;
    
    while(p->next!=NULL)
    p=p->next;
    
    while(p!=NULL){
        if(p->data){
        printf("%d",p->data);
        
            printf("x^%d",p->ex);
        }
        else printf("%d",0);
        if(p->pre!=NULL){
            printf(" + ");
        }
        p=p->pre;
    }printf("\n");
}


int main(){
    int x,ex;
    while(1){
        scanf("%d %d",&x,&ex);
        if(x==0&&ex==0){
            break;
        }pol1=ins(pol1,x,ex);
    }
     while(1){
        scanf("%d %d",&x,&ex);
        if(x==0&&ex==0){
            break;
        }pol2=ins(pol2,x,ex);
    }
    display(pol1);
    display(pol2);
    pol_add();
    display(result);
}
