#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
}*head=NULL;

typedef struct node NODE;

void ins(int x){
    NODE *nn=(NODE *)malloc(sizeof(NODE));
    nn->data=x;
    
    if(head==NULL){
    head=nn;
    nn->next=head;
    }
    else{
        NODE *temp=head;
        while(temp->next!=head)
        temp=temp->next;
        temp->next=nn;
        nn->next=head;
    }
}

NODE* find(int x){
    NODE *temp=head;
    do{
        if(temp->data==x)
        break;
        temp=temp->next;
    }while (temp!=head);
    return temp;
    
}

void insertbeg() {
    NODE *nn = (NODE *)malloc(sizeof(NODE));
    nn->data = 10;

    if (head == NULL) {
        nn->next = nn;  // Points to itself
        head = nn;
    } else {
        NODE *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        nn->next = head;
        temp->next = nn;
        head = nn;
    }
}

void dis(){
    NODE *temp=head;
    do
{
        printf("%d ",temp->data);
        temp=temp->next;
    }while (temp!=head);    
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        ins(x);
        }
        insertbeg();
        dis();

        printf("%x",find(10));
}