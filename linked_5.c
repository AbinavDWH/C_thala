// You are using GCC
#include<stdio.h>
#include<stdlib.h>

struct node{
    int ex,x;
    struct node *next;
}*head=NULL;

void ins(int EX,int X){
    struct node *new_node =(struct node *)malloc(sizeof(struct node));
    new_node->ex=EX;
    new_node->x=X;
    new_node->next=NULL;
    if(head==NULL){
        head=new_node;
    }
    else{
        struct node *temp=head;
        while(temp->next !=NULL)
        temp=temp->next;
        temp->next=new_node;
    }
}

void display(int n,int m){
   // int flag=0;
     struct node *temp=head;
    printf("Polynomial 1:");
    for(int i=0;i<n;i++){
        printf(" (%dx^%d) ",temp->x,temp->ex);
        
        if(i!=n-1){
            printf("+");
        }
        temp=temp->next;
    }
     printf("\nPolynomial 2:");
    for(int i=0;i<m;i++){
        printf(" (%dx^%d) ",temp->x,temp->ex);
        if(i!=m-1){
            printf("+");
        }
        temp=temp->next;
    }
    
}

void isequal(int n,int m){
    int flag=0;
    if(n!=m){
    
    flag =1;
    }
    else{
    struct node *temp1=head;
    struct node *temp2=head;
    for(int i=0;i<n;i++){
        temp2=temp2->next;
    }
    for (size_t i = 0; i < n; i++)
    {
        if(temp1->x!=temp2->x && temp1->ex==temp2->ex){
        
            flag= 1;
    }
    
} 
}if(flag==0) printf("eqaul");
else printf("not equal");}

int main(){
    int n,ex,x,m;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&x,&ex);
        ins(ex,x);
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d %d",&x,&ex);
        ins(ex,x);
    }
    display(n,m);
    isequal(n,m);
}