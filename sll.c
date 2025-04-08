#include<stdio.h>
#include<stdlib.h>


struct sll
{
    /* data */
    int data;
    struct sll *next;
}*head=NULL;

typedef struct  sll NODE;
 
void insert(int x){
    NODE *nn=(NODE *)malloc(sizeof(NODE));
    nn->data=x;
    nn->next=NULL;
    if(head==NULL){
        head=nn;
    }
    else{
        NODE *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
            }
            temp->next=nn;
    }
}

int pos(int p,int n){
    if(p>n) return -1;
    NODE *temp=head;
    for(int i=1;i<p;i++){
        temp=temp->next;
    }
    return temp->data;
}

int posbf(int p,int n){
    if(p>n || p==1) return -1;
    
    NODE *temp=head->next,*pre=head;
    for(int i=2;i<p;i++){
        pre=temp;
        temp=temp->next;
    }
    return pre->data;
}

int posaf(int p,int n){
    if(p>n || p==n) return -1;
    
    NODE *temp=head->next,*pre=head;
    for(int i=1;i<p;i++){
        pre=temp;
        temp=temp->next;
    }
    return temp->data;
}

void del(){
    NODE *temp=head;
    while (temp->next->next!=NULL)
    {
        /* code */
        temp=temp->next;
    }
    NODE *f=temp->next;
    temp->next=NULL;
    free(f);
    
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
    scanf("%d ",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&ele);
        insert(ele);
    }
    display();
    int p;
    scanf("%d",&p);
    printf("%d ",pos(p,n));
    printf("%d ",posbf(p,n));
    printf("%d ",posaf(p,n));
    del();
    printf("\n");
    display();
}