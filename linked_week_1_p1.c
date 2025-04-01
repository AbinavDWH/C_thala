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
    nn->next=NULL;
    if(head->data==pos){
        nn->next=head;
        head=nn;
    }
    else{
        NODE *temp=head,*pre=NULL;
        while(temp!=NULL){
            if(temp->data==pos)
            pre=temp;
            temp=temp->next;
        }
        if(pre==NULL){
            printf(" ");
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
    if(head->data==pos){
        return;
    }
    else{
        NODE *temp=head->next->next->next,*pre=head;
        if(head->next->next->data==pos){
            head=head->next->next;
            return;
        }
        while(temp!=NULL){
            if(temp->data==pos){
                break;
            }
            temp=temp->next;
            pre=pre->next;
        }
        if(temp==NULL)
        return;
        pre->next=temp;
    }
}

void delendpos(int pos){
    NODE *temp=head;
    while(temp->next!=NULL){temp=temp->next;
    }
    if(temp->data==pos)
    return;
    else{
        temp=head;
        while(temp->next->next!=NULL){
            if(temp->data==pos){
                break;
            }
            temp=temp->next;
        }if(temp->next->next==NULL)
        return;
        temp->next=temp->next->next;
    }
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
        }break;
        case 11: return 0;
        break;
        default:
        printf("Invaild option! Please try again");
    }}
    
}