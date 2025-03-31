#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node{
    int data,ex;
    struct node *next;
}*head=NULL;

void insert(int data,int ex){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->ex=ex;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
        }
        else{
            struct node *temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newnode;
}
}

void dispaly(){
    struct node *temp=head;
    while (temp!=NULL)
    {
        /* code */
        printf("%d ",temp->ex);
        temp=temp->next;
    }
    
}

int ans(int x){int sum=0;
    struct node *temp=head;
    while (temp!=NULL)
    {
        sum+=((int)pow(x,temp->ex))*temp->data;
        temp=temp->next;
    }
    return sum;
}

int main(){
    int n,ele,x;
    scanf("%d",&n);
    for(int i=0;i<=n;i++){
        scanf("%d",&ele);
        insert(ele,n-i);
    }
  //  dispaly();
    scanf("%d",&x);
    dispaly();
    int total=ans(x);
    printf("%d",total);
}