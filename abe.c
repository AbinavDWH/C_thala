#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    /* data */
    int data;
    struct node *next;
}Node;

Node *head=NULL;

void createlinked(){
    int value;
    while(1){
        scanf("%d",&value);
        if(value==-1) break;
        Node *newnode=(Node*)malloc(sizeof(Node));
        newnode->data=value;
        newnode->next=NULL;
        if(head==NULL){
            head=newnode;
        }else{
            Node *lastnode=head;
            while (lastnode->next!=NULL)
            {
                lastnode=lastnode->next;
            }
            lastnode->next=newnode;
            
        }
    }printf("LINKED LIST CREATED\n");
}

void printlinked(){
    if(head==NULL){
        printf("The list is empty\n");
        return;
    }
    
    Node *temp=head;

    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
        }printf("\n");
}

void insbeg(int value){
    Node *newnode=(Node*)malloc(sizeof(Node));
    newnode->data=value;
    newnode->next=head;
    head=newnode;
    printf("The linked list after insertion at the beginning is:\n");
    printlinked();
}

void insend(int value){
    Node *newnode=(Node*)malloc(sizeof(Node));
    newnode->data=value;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
        }else{
            Node *lastnode=head;
            while (lastnode->next!=NULL)
            {
                lastnode=lastnode->next;
                }
                lastnode->next=newnode;
                }
                printf("The linked list after insertion at the end is:\n");
                printlinked();
}

void insbegval(int value,int val){
    if(head ==NULL || head->data == value){
        printf("Value not found in the list\n");
        return;
        }
        Node *newnode=(Node*)malloc(sizeof(Node));
        newnode->data=val;

        Node *temp=head;
        while (temp->next !=NULL && temp->next->data !=value)
        {
            temp=temp->next;
        }

        if(temp->next ==NULL){
            printf("Value not found in the list\n");
            printf("The linked list after insertion before a value is:\n");
            printlinked();
        }else{
            newnode->next=temp->next;
            temp->next=newnode;
            printf("The linked list after insertion before a value is:\n");
            printlinked();
        }
    }

void insafval(int value,int newvalue){
    Node *temp=head;
    while(temp!=NULL && temp->data!=value){
        temp=temp->next;
    }

    if(temp==NULL){
        printf("Value not found in the list\n");
        printf("The linked list after insertion after a value is:\n");
        printlinked();
    }
    else{
        Node *newnode=(Node*)malloc(sizeof(Node));
        newnode->data=newvalue;
        newnode->next=temp->next;
        temp->next=newnode;
        printf("The linked list after insertion after a value is:\n");
        printlinked();
        
    }
}    


void delbeg(){
    if(head==NULL){
        printf("The list is empty\n");
        return;
    }
    Node *temp=head;
    head=head->next;
    free(temp);
    printf("The linked list after deletion from the beginning is:\n");
    printlinked();
}

void delend(){
    if(head==NULL){
        printf("The list is empty\n");
        return;
        }
        if(head->next==NULL){
            free(head);
            head=NULL;
        }else{
            Node *temp=head;
            while(temp->next->next!=NULL){
                temp=temp->next;
                }
                free(temp->next);
                temp->next=NULL;
        }printf("The linked list after deletion from the end is:\n");
        printlinked();
}

void delval(int value){
    if( head ==NULL|| head->data==value || head->next==NULL)
    {
        printf("Value not found in the list\n");
        return;
        }

        Node *temp=head;
        Node *pre=NULL;
        Node* preprev=NULL;
        while (temp->next!=NULL && temp->next->data!=value)
        {
            preprev=pre;
            pre=temp;
            temp=temp->next;
        }

        if(temp->next==NULL){
            printf("Value not found in the list\n");
        }else{
            if(preprev==NULL){
                head=temp;
            }else{
                preprev->next=temp;
            }
            free(pre);
            printf("The linked list after deletion before a value is:\n");
            printlinked();
        }
}

void delafval(int value){
    Node *temp=head;
    while(temp!=NULL&& temp->data!=value){
        temp=temp->next;
    }

    if(temp==NULL || temp->next==NULL){
        printf("Value not found in the list\n");
    }else{
        Node *todel=temp->next;
        temp->next=todel->next;
        free(todel);
        printf("The linked list after deletion after a value is:\n");
        printlinked();
    }
}

int main(){
    int choice,value,newval;
    while (1)
    {
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
        createlinked();
        break;
        case 2:
        printlinked();
        break;
        case 3:
        scanf("%d",&value);
        insbeg(value);
        break;
        case 4:
        scanf("%d",&value);
        insend(value);
        break;
        case 5:
        scanf("%d %d",&value,&newval);
        insbegval(value,newval);
        break;
        case 6:
        scanf("%d %d",&value,&newval);
        insafval(value,newval);
        break;
        case 7:
            delbeg();
            break;
        case 8:
        delend();
        break;
        case 9:
        scanf("%d",&value);
        delval(value);
        break;
        case 10:
        scanf("%d",&value);
        delafval(value);
        break;
        case 11:
        return 0;
        default:
        printf("Invalid option! Please try again.\n");
            break;
        }    
    }
    
}
        