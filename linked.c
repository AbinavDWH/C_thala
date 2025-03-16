#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};


int main(){
    struct node *head=(struct node*)malloc(sizeof(struct node));
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    head->next=new_node;
    new_node->data=20;
    new_node->next=NULL;
    struct node *temp;
    temp=head;    
    while (temp!=NULL)
    {
        /* code */
        printf("%d\n",temp->data);
        temp=temp->next;
    }
    
}