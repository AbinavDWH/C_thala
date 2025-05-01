
// Guide Harish in developing a simple queue system for a customer service center. The customer service center can handle up to 25 customers at a time. The queue needs to support basic operations such as adding a customer to the queue, serving a customer (removing them from the queue), and displaying the current queue of customers.


// Use an array for implementation.
// Input format :

// The first line of the input consists of an integer N, the number of customers arriving at the service center.

// The second line consists of N space-separated integers, representing the customer IDs in the order they arrive.
// Output format :

// After serving the first customer in the queue, display the remaining customers in the queue.

// If a dequeue operation is attempted on an empty queue, display "Underflow".

// If the queue is empty, display "Queue is empty".


// Refer to the sample output for formatting specifications.
// Code constraints :

// The given test cases fall under the following constraints:

// 0 ≤ size of queue ≤ 25.
// Sample test cases :
// Input 1 :

// 5
// 101 102 103 104 105

// Output 1 :

// 102 103 104 105 

// Input 2 :

// 0
// 0

// Output 2 :

// Underflow
// Queue is empty

// Expected Time Complexity : O(N)
// Expected Space Complexity : O(N) 

// You are using GCC
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
}*front=NULL,*rear=NULL;

typedef struct node NODE;

void enq(int x){
    NODE *nn=(NODE *)malloc(sizeof(NODE));
    nn->data=x;
    nn->next=NULL;
    if(rear==NULL && front==NULL){
        rear=front=nn;
    }
    else{
        rear->next=nn;
        rear=nn;
    }
}

void deq(){
    if(front==NULL){
        printf("Underflow\n");
    }
    else{NODE *temp=front;
        if(front==rear){
            front=rear=NULL;
        }
        else{
            front=front->next;
        }
        free(temp);
    }
}


void display(){
    if(front==NULL){
        printf("Queue is empty");
        return;
    }
    NODE *temp=front;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int main(){
    int n,ele;
    scanf("%d",&n);
    for( int i=0;i<n;i++){
        scanf("%d",&ele);
        enq(ele);
    }
    deq();
    display();
}