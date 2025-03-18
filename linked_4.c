#include<stdlib.h>
#include<stdio.h>

struct node
{
    /* data */
    char data;
    struct node *next;
}*head = NULL;

void insert(char x){
    struct node *new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=x;
    new_node->next=head;  //insert at begining
    head=new_node;
    
    
}
void display(){
    struct node *temp=head;
    while(temp!=NULL){
        printf("%c ",temp->data);
        temp=temp->next;    
    }   
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        char x;
        scanf(" %c",&x);
        insert(x);
    }
    display();
}
