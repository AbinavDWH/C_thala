#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data,ex;
    struct node *next;
}*pol=NULL,*po2=NULL,*mul=NULL,*tol=NULL;

typedef struct node NODE;

void ins(NODE **head,int x,int ex){
    NODE *nn =(NODE *)malloc(sizeof(NODE));
    nn->data=x;
    nn->ex=ex;
    nn->next=NULL;
    if(*head==NULL){
        *head=nn;
    }
    else{
        NODE *temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=nn;
    }
}

void display(NODE *temp){
    while (temp!=NULL)
    {
        /* code */
        printf("%d %d\n",temp->data,temp->ex);
        temp=temp->next;
    }
    
}

void m(NODE *p1,NODE *p2){
    NODE *temp1=p1,*temp2=p2;
    while(temp1!=NULL){
        temp2=p2;
        while(temp2!=NULL){
            ins(&mul,(temp1->data*temp2->data)/2,temp1->ex+temp2->ex);
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
}

void add(NODE **temp){
    NODE *temp1=*temp,*temp2=*temp;
    for (int i=0;temp1!=NULL;i++)
    {   temp2=*temp;
       
        /* code */
        for (int j=0;j!=i &&temp2!=NULL;j++)
        {
            for(int k=0;k<j && temp2!=NULL;k++)
            temp2=temp2->next;
            /* code */
            if(temp1->ex==temp2->ex && temp1->data!=-69 && temp2->data!= -69){
                ins(&tol,temp1->data+temp2->data,temp1->ex);
                temp1->data=-69;
                temp2->data=-69;
            }
            temp2=temp2->next;
        }temp1=temp1->next;
        
    }
    temp1=*temp;
    while(temp1!=NULL && temp1->data!=-69)
    ins(&tol,temp1->data,temp1->ex);
    
}

int main(){
    int n,ele,ex;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
    scanf("%d %d",&ele,&ex);
    ins(&pol,ele,ex);
    }
    scanf("%d",&n);
    for(int i=0;i<n;i++){
    scanf("%d %d",&ele,&ex);
    ins(&po2,ele,ex);
    }
    printf("MUL\n");
    m(pol,po2);
    //display(pol);
    //display(po2);
    display(mul);
    add(&mul);
    printf("finally\n");
    display(tol);
}