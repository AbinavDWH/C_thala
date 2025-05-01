// The program should allow users to interact with the queue by enqueuing positive integers and subsequently dequeuing and displaying elements.
// Input format :

// The input consists of a series of integers, one per line. Enter positive integers into the queue.

// Enter -1 to terminate input.
// Output format :

// The output prints the space-separated dequeued elements.


// Refer to the sample output for the exact text and format.
// Code constraints :

// The given test cases fall under the following constraints:

// -1000 ≤ node values ≤ 1000
// Sample test cases :
// Input 1 :

// 1
// 2
// 3
// 4
// -1

// Output 1 :

// Dequeued elements: 1 2 3 4 

// Input 2 :

// 56
// 74
// 36
// 94
// 15
// 34
// -1

// Output 2 :

// Dequeued elements: 56 74 36 94 15 34 

// You are using GCC
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
}*front=NULL,*rear=NULL;

typedef struct node NODE;

void enq(int data){
    NODE *nn=(NODE *)malloc(sizeof(NODE));
    nn->data=data;
    nn->next=NULL;
    if(front==NULL && rear==NULL){
        front=rear=nn;
    }
    else{
        rear->next=nn;
        rear=nn;
    }
}

void display(){
    printf("Dequeued elements: ");
    NODE *temp=front;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main(){
    int ele;
    do{
        scanf("%d",&ele);
        if(ele==-1) break;
        enq(ele);
    }while(ele!=-1);
    display();
}