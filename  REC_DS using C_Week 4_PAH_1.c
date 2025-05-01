// you  are tasked with developing a simple ticket management system for a customer support department. In this system, customers submit support tickets, which are processed in a First-In-First-Out (FIFO) order. The system needs to handle the following operations:


// Ticket Submission (Enqueue Operation): New tickets are submitted by customers. Each ticket is assigned a unique identifier (represented by an integer). When a new ticket arrives, it should be added to the end of the queue.


// Ticket Processing (Dequeue Operation): The support team processes tickets in the order they are received. The ticket at the front of the queue is processed first. After processing, the ticket is removed from the queue.


// Display Ticket Queue: The system should be able to display the current state of the ticket queue, showing the sequence of ticket identifiers from front to rear.
// Input format :

// The first input line contains an integer n, the number of tickets submitted by customers.

// The second line consists of a single integer, representing the unique identifier of each submitted ticket, separated by a space.
// Output format :

// The first line displays the "Queue: " followed by the ticket identifiers in the queue after all tickets have been submitted.

// The second line displays the "Queue After Dequeue: " followed by the ticket identifiers in the queue after processing (removing) the ticket at the front.


// Refer to the sample output for the exact text and format.
// Code constraints :

// In this scenario, the test cases fall under the following constraints:

// 2 ≤ N ≤ 20

// 0 ≤ elements ≤ 100
// Sample test cases :
// Input 1 :

// 6
// 14 52 63 95 68 49

// Output 1 :

// Queue: 14 52 63 95 68 49 
// Queue After Dequeue: 52 63 95 68 49 

// Input 2 :

// 3
// 21 65 98

// Output 2 :

// Queue: 21 65 98 
// Queue After Dequeue: 65 98 


// You are using GCC
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
}*front=NULL,*rear=NULL;

typedef struct node NODE;

void enq(int x){
    NODE* nn=(NODE *)malloc(sizeof(NODE));
    nn->data=x;
    nn->next=NULL;
    if(front==NULL&&rear==NULL){
        rear=front=nn;
    }
    else{
        rear->next=nn;
        rear=nn;
    }
}

void deq(){
    NODE *temp;
    if(front==rear){
    temp=front;
    free(temp);
    }
    else if(front==NULL){
        return;
    }else{
        front=front->next;
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
    for(int i=0;i<n;i++){
        scanf("%d",&ele);
        enq(ele);
    }printf("Queue: ");
    display();
    printf("Queue After Dequeue: ");
    deq();
    display();
    
}