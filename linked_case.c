#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*head=NULL;

typedef struct node NODE;
//case 1 and case 3
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
//case 3

void insertbeg(int x){
    NODE *nn=(NODE *)malloc(sizeof(NODE));
    nn->data=x;
    nn->next=head;
    head=nn;
}
//case 5
void insertbegpos(int pos ,int x){
    NODE *nn=(NODE *)malloc(sizeof(NODE));
    nn->data=x;
    nn->next=NULL;
    if(head->data==pos){
        nn->next=head;
        head=nn;
    }
    else{
        NODE *temp=head,*pre=NULL;
        while (temp!=NULL)
        {
            if(temp->data==pos)
            pre=temp;
            temp=temp->next;
        }
        if(pre==NULL)
        printf("element does not exist");
        else{
            pre->next=nn;
            nn->next=temp;

        }
    }
}

//case 6

void insertafpos(int pos ,int x){
    NODE *nn=(NODE *)malloc(sizeof(NODE));
    nn->data=x;
    nn->next=NULL;
    NODE *temp=head;
    while (temp->next!=NULL)
    temp=temp->next;
    if(temp->data==pos){
        temp->next=nn;
    }
    else{
        temp=head;
        while (temp!=NULL){
            if(temp->data==pos)
            break;
           temp= temp->next;
        }
        if(temp!=NULL){
        nn->next=temp->next;
        temp->next=nn;}
        else return;
    }

}


//case 7
void delbeg(){
    NODE *temp=head;
    head=head->next;
    free(temp);
}
//case 8

void delend(){
    NODE *temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    NODE *f=temp->next;
    temp->next=NULL;
    free(f);
}

//case 9
void delbegpos(int pos){
    if(head->data==pos){
        printf("illa");
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
        switch (n){
            case 1:
            while (1)
            {
            scanf("%d",&ele);
            if(ele==-1)
            break;
            insert(ele);
        }
        flag=1;
        break;
        case 2:
            if(flag){
                display();
            }
            break;
        case 3:
        if(flag){
            scanf("%d",&ele);
            insertbeg(ele);
            display();
    }   break;
        case 4:
        if(flag){
            scanf("%d",&ele);
            insert(ele);
            display();
            
        }
        break;
        case 5:
        if(flag){
            int pele;
            scanf("%d",&pele);
            scanf("%d",&ele);
            insertbegpos(pele,ele);

        }break;
        case 6:
        if(flag){
            int pele;
            scanf("%d",&pele);
            scanf("%d",&ele);
            insertafpos(pele,ele);
            display();
        }break;
        case 7:
        if(flag){
            delbeg();
            display();
        }break;
        case 8:
        if(flag){
            delend();
            display();
        }
        break;
    }
}
}