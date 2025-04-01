// You are using GCC
#include<stdio.h>
#include<stdlib.h>
 
struct node{
    int data;
    struct node *next;
}*head=NULL;

typedef struct node NODE;

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


void insertbeg(int x){
    NODE *nn=(NODE *)malloc(sizeof(NODE));
    nn->data=x;
    nn->next=head;
    head=nn;
}

void insertbegpos(int pos,int x){
    NODE *nn=(NODE *)malloc(sizeof(NODE));
    nn->data=x;
    nn->next=NULL;
    if(head->data==pos){
        nn->next=head;
        head=nn;
    }
    else{
        NODE *temp=head->next,*pre=head;
        while(temp!=NULL){
            if(temp->data==pos)
            break;
            pre=pre->next;
            temp=temp->next;
        }
        if(pre->next==NULL){
            printf("Value not found in the list\n");
        }
        else{
             pre->next=nn;
             nn->next=temp;
        }
    }
}

void insertafpos(int pos,int x){
    NODE *nn=(NODE *)malloc(sizeof(NODE));
    nn->data=x;
    nn->next=NULL;
    NODE *temp=head;
    while(temp->next!=NULL)
    temp=temp->next;
    if(temp->data==pos)
    temp->next=nn;
    else{
        temp=head;
        while(temp!=NULL){
            if(temp->data==pos)
            break;
            temp=temp->next;
        }if(temp!=NULL){
            nn->next=temp->next;
            temp->next=nn;
        }else return;
        }
    }
void delbeg(){
    NODE *temp=head;
    head=head->next;
    free(temp);
}

void delend(){
    NODE *temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    NODE *f=temp->next;
    temp->next=NULL;
    free(f);
}

void delbegpos(int pos){
    if (head == NULL || head->next == NULL) {
        printf("List is too short to delete before %d.\n", pos);
        return;
    }

    
    if (head->next->next->data == pos) {
        NODE* temp = head;
        head = head->next;
        free(temp);
        return;
    }

    NODE *prev = NULL, *current = head, *nextNode = head->next;

    
    while (nextNode != NULL && nextNode->data != pos) {
        prev = current;
        current = nextNode;
        nextNode = nextNode->next;
    }

    
    if (nextNode == NULL) {
        printf("Element %d not found or has no preceding node to delete.\n", pos);
        return;
    }

   
    prev->next = nextNode;
    free(current);
}

void delendpos(int x){
    if (head == NULL || head->next == NULL) {
        printf("List is too short to delete the next node.\n");
        return;
    }
    NODE* temp = head;

   
    while (temp != NULL && temp->data != x) {
        temp = temp->next;
    }

    
    if (temp == NULL || temp->next == NULL) {
        printf("No next node to delete for element %d.\n", x);
        return;
    }

    
    NODE* node_to_delete = temp->next;
    temp->next = node_to_delete->next;
    free(node_to_delete);
}




void display(){
    NODE *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    
    printf("\n");
}

int main(){
    int ele,n,flag=0;
    while(1){
        scanf("%d",&n);
        switch(n){
            case 1:
            while(1){
                scanf("%d",&ele);
                if(ele==-1)
                break;
                insert(ele);
            }printf("LINKED LIST CREATED\n");
            flag=1;
            break;
            case 2:
            if(flag){
                display();
            }
            else printf("The list is empty\n");
            break;
            case 3:
            if(flag){
                scanf("%d",&ele);
                insertbeg(ele);
                printf("The linked list after insertion at the beginning is:\n");
                display();
                
            }
            break;
            case 4:
            if(flag){
                scanf("%d",&ele);
                insert(ele);
                printf("The linked list after insertion at the end is:\n");
                display();
            }break;
            case 5:
            if(flag){
                int pele;
                scanf("%d",&pele);
                scanf("%d",&ele);
                insertbegpos(pele,ele);
                printf("The linked after list insertion before a value is:\n");
                display();
            }break;
            case 6:
            if(flag){
                int pele;
                scanf("%d",&pele);
                scanf("%d",&ele);
                insertafpos(pele,ele);
                printf("The linked after list insertion after a value is:\n");
                display();
            }break;
            case 7:
            if(flag){
                delbeg();
                printf("The linked list after deletion from the beginning is:\n");
                display();
            }
            break;
        
        case 8:
        if(flag){
            delend();
            printf("The linked list after deletion from the end is:\n");
            display();
        }
        break;
        case 9:
        if(flag){
            scanf("%d",&ele);
            delbegpos(ele);
            printf("The linked list after deletion before a value is:\n");
            display();
        }break;
        case 10:
        if(flag){
            scanf("%d",&ele);
            delendpos(ele);
            printf("The linked list after deletion after a value is:\n");
            display();
        }break;
        case 11: return 0;
        break;
        default:
        printf("Invaild option! Please try again");
    }}
    
}