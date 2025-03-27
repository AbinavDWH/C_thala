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
            ins(&mul,(temp1->data*temp2->data),temp1->ex+temp2->ex);
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
}



void add(NODE **temp){
    NODE *temp1=*temp,*temp2=NULL;
    while (temp1!=NULL)
    {
        
        int sum=temp1->data;
        int ex=temp1->ex;
        temp2=temp1->next;
        NODE *chage=temp1;
        while(temp2!=NULL){
            if(temp2->ex==ex){
                
                sum+=temp2->data;
                chage->next=temp2->next;
                NODE *temp3=temp2;
                temp2=temp2->next;
                free(temp3);
                chage=chage->next;
    }
        else    
        temp2=temp2->next;
           
        }ins(&tol,sum,ex);
        temp1=temp1->next;
    }
}


void compare(const void *a,const void *b){
    const NODE* const *node1=(const NODE**)a;
    const NODE* const *node2=(const NODE**)b;
    return (*node1)->ex - (*node2)->ex;
}


void sort(NODE **temp){
    NODE *h=*temp;
 int i=0;
 while (h!=NULL)
 {
    /* code */
    i++;
    h=h->next;
 }
h=*temp;
 NODE **array=(NODE **)malloc(i*sizeof(NODE *));
 for(int j=0;j<i;j++){
    array[j]=h;
    h=h->next;
 }

 qsort(array,i,sizeof(NODE *),compare);
 
    *temp=array[0];
    for(int j=0;j<i-1;j++){
        array[j]->next=array[j+1];
    }
    array[i-1]->next=NULL;
    free(array);

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
    //sort(&mul);
    add(&mul);
    printf("finally\n");
    display(tol);
}