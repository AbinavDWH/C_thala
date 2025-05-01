// Amar is working on a project where he needs to implement a special type of queue that allows selective dequeuing based on a given multiple. He wants to efficiently manage a queue of integers such that only elements not divisible by a given multiple are retained in the queue after a selective dequeue operation.


// Implement a program to assist Amar in managing his selective queue. 


// Example


// Input:

// 5

// 10 2 30 4 50

// 5

// Output:

// Original Queue: 10 2 30 4 50 

// Queue after selective dequeue: 2 4 

// Explanation:

// After selective dequeue with a multiple of 5, the elements that are multiples of 5 should be removed. Therefore, only 10, 30, and 50 should be removed from the queue. The updated Queue is 2 4.
// Input format :

// The first line contains an integer n, representing the number of elements initially present in the queue.

// The second line contains n space-separated integers, representing the elements of the queue.

// The third line contains an integer multiple, representing the divisor for selective dequeue operation.
// Output format :

// The first line of output prints "Original Queue: " followed by the space-separated elements in the queue before the dequeue operation.

// The second line prints "Queue after selective dequeue: " followed by the remaining space-separated elements in the queue, after deleting elements that are the multiples of the specified number.


// Refer to the sample output for the formatting specifications.
// Code constraints :

// In this scenario, the test cases fall under the following constraints:

// 1 ≤ n ≤ 50

// 1 ≤ elements in the queue ≤ 100

// 1 ≤ multiple ≤ 10
// Sample test cases :
// Input 1 :

// 5
// 10 2 30 4 50
// 5

// Output 1 :

// Original Queue: 10 2 30 4 50 
// Queue after selective dequeue: 2 4 

// Input 2 :

// 7
// 2 3 7 14 21 28 35
// 3

// Output 2 :

// Original Queue: 2 3 7 14 21 28 35 
// Queue after selective dequeue: 2 7 14 28 35 

// You are using GCC
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*front=NULL,*rear=NULL;

typedef struct node NODE;

void enq(int data){
    NODE *nn=(NODE *)malloc(sizeof(NODE));
    nn->data=data;
    nn->next=NULL;
    if(rear == NULL &&front==NULL)
    rear=front=nn;
    else{
        rear->next=nn;
        rear=nn;
    }
}

void deq(int x){
    NODE *temp=front;
    
    while(front!=NULL && front->data%x==0){
        temp=front;
        front=front->next;
        free(temp);
    }
    
    NODE *pre=front;
    temp=front->next;
    while(temp!=NULL){
        if(temp->data%x==0){
            pre->next=temp->next;
            free(temp);
            temp=pre->next;
        }
        else{
            temp=temp->next;
            pre=pre->next;
        }
    }
    rear=front;
    if(rear!=NULL){
        while(rear->next!=NULL){
            rear=rear->next;
        }
    }
}

void display(){
    NODE *temp=front;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }printf("\n");
}

int main(){
    int n,ele;
    scanf("%d",&n);
    for (int i =0;i<n;i++){
        scanf("%d",&ele);
        enq(ele);
    }printf("Original Queue: ");
    display();
    printf("Queue after selective dequeue: ");
    scanf("%d",&ele);
    deq(ele);
    display();
}