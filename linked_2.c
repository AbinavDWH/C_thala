#include<stdio.h>
#include<stdlib.h>

struct node{
    float x;
    int ex;
    struct node *next;
};
struct node *head=NULL;

void ins(int EX,float X){
    struct node* new_node=(struct node *)malloc(sizeof(struct node));
    new_node->ex=EX;
    new_node->x=X;
    new_node->next=NULL;
    if(head==NULL){
        head=new_node;
        return;
    }
    struct node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;
    
}

int main(){
    int n,m;
    scanf("%d",&n);
    int ex;float x; 
    for(int i=0;i<n;i++){
        scanf("%f %d",&x,&ex);
        ins(ex,x);
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%f %d",&x,&ex);
        ins(ex,x);}
        int sum=0;
        struct node* temp=head;
        while (temp!=NULL)
        {
            /* code */
            sum+=temp->x;
            temp=temp->next;
        }
        
        printf("%d",sum);
        return 0;
}
