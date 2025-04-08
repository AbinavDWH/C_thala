#include<stdio.h>
#include<stdlib.h>

struct dll
{
    /* data */
    int data;
    struct dll *next,*pre;        
}*head=NULL,*tail=NULL;

typedef struct dll NODE;

void insert(int x){
    NODE *nn=(NODE *)malloc(sizeof(NODE));
    nn->data=x;
    nn->next=NULL;
    nn->pre=NULL;
    if(head==NULL&& tail==NULL)
    head=nn;
    else if(head!=NULL && tail==NULL){
        tail=nn;
        nn->pre=head;
        head->next=nn;
    }
    else{
        tail->next=nn;
        nn->pre=tail;
        tail=nn;
    }
}

void inssetbeg(int x){
    NODE *nn=(NODE *)malloc(sizeof(NODE));
    nn->data=x;
    nn->next=head;
    head->pre=nn;
    head=nn;
}

void inssetend(int x){
    NODE *nn=(NODE *)malloc(sizeof(NODE));
    nn->data=x;
    nn->pre=tail;
    tail->next=nn;
    tail=nn;
}

void insatmid(int n,int ele){
    NODE *p=head;
    for(int i=1;i<n-1;i++)
    p=p->next;
    NODE *nn=(NODE *)malloc(sizeof(NODE));
    nn->data=ele;
    nn->pre=p;
    nn->next=p->next;
    p->next->pre=nn;
    p->next=nn;
}

void delbeg(){
    NODE *temp=tail;
    tail=tail->pre;
    tail->next=NULL;
    free(temp);
}

void delatpos(int ele){
    NODE *p=head;
    while (p!=NULL && p->data!=ele)
    {
        /* code */
        p=p->next;
    }
    NODE *f;
    if(p!=NULL){
        if(p->pre==NULL){
            head=head->next;
            f=head->pre;
            head->pre=NULL;
        
        }
        else if(p->next==NULL){
          tail=p->pre;
          f=p;
          tail->next=NULL;
            
        }
        else{
            f=p;
            p->pre->next=p->next;
        }
        free(f);
    }
    else{
        printf("Element is not found");
    }
    
}

void dis(){
    NODE *temp=head;
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
        insert(x);
        }
        dis();
        inssetbeg(10);
        inssetend(20);
        printf("\n");
        insatmid(n,1);
        delbeg();
        dis();
        printf("\nThe element to be del");
        scanf("%d",&n);
        delatpos(n);
        dis();
}
