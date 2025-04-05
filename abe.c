#include<stdio.h>
#include<stdlib.h>

struct node{
    int data,ex;
    struct node *next;
}*poly1=NULL,*poly2=NULL;

typedef struct node NODE;

void ins(NODE **head,int x,int ex){
    NODE *nn=(NODE *)malloc(sizeof(NODE));
    nn->data=x;
    nn->ex=ex;
    nn->next=NULL;
    if(*head==NULL){
        *head=nn;
    }
    else{
        NODE *temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=nn;
    }
}

void display(NODE *temp,int x){
    printf("Polynomial %d:",x);
    while(temp!=NULL){
        printf(" (%dx^%d) ",temp->data,temp->ex);
        if(temp->next!=NULL)
        printf("+");
        temp=temp->next;
    }
    printf("\n");
}

void isequal(NODE *temp1,NODE *temp2,int x,int y){
    if(x!=y){
        printf("Polynomials are not Equal.");
    }
    else{
        int flag=0;
        {
                while(temp1!=NULL && temp2!=NULL){
                if(temp1->data==temp2->data && temp1->ex==temp2->ex)
                flag++;
                temp2=temp2->next;
                
            temp1=temp1->next;}
            
        }
        if(flag==y){
            printf("Polynomials are Equal.");
        }
        else{
            printf("Polynomials are not Equal.");
        }
    }
}

int main(){
    int m,n;
    int summa,ex;
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d %d",&summa,&ex);
        ins(&poly1,summa,ex);
    }
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&summa,&ex);
        ins(&poly2,summa,ex);
    }
    display(poly1,1);
    display(poly2,2);
    isequal(poly1,poly2,m,n);
}