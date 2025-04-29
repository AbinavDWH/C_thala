// Imagine a bustling coffee shop, where customers are placing their orders for their favorite coffee drinks. The cafe owner Sheeren wants to efficiently manage the queue of coffee orders using a digital system. She needs a program to handle this queue of orders.


// You are tasked with creating a program that implements a queue for coffee orders. Each character in the queue represents a customer's coffee order, with 'L' indicating a latte, 'E' indicating an espresso, 'M' indicating a macchiato, 'O' indicating an iced coffee, and 'N' indicating a nabob. 


// Customers can place orders and enjoy their delicious coffee drinks.
// Input format :

// The input consists of integers corresponding to the operation that needs to be performed:

// Choice 1: Enqueue the coffee order into the queue. If the choice is 1, the following input is a space-separated character ('L', 'E', 'M', 'O', 'N').

// Choice 2: Dequeue a coffee order from the queue.

// Choice 3: Display the orders in the queue.

// Choice 4: Exit the program.
// Output format :

// The output displays messages according to the choice and the status of the queue:


// If the choice is 1:

//     Insert the given order into the queue and display "Order for [order] is enqueued." where [order] is the coffee order that is inserted.
//     If the queue is full, print "Queue is full. Cannot enqueue more orders."

// If the choice is 2:

//     Dequeue a character from the queue and display "Dequeued Order: " followed by the corresponding order that is dequeued.
//     If the queue is empty without any orders, print "No orders in the queue."

// If the choice is 3:

//     The output prints "Orders in the queue are: " followed by the space-separated orders present in the queue.
//     If there are no orders in the queue, print "Queue is empty. No orders available."

// If the choice is 4:

//     Exit the program and print "Exiting program"

// If any other choice is entered, the output prints "Invalid option."


// Refer to the sample output for the exact text and format.
// Code constraints :

// The given test cases fall under the following constraints:

// The maximum size of the coffee order queue = 5

// Customers can place the following orders: 'L', 'E', 'M', 'O', 'N'

// Choice: 1, 2, 3, or 4.
// Sample test cases :
// Input 1 :

// 1 L
// 1 E
// 1 M
// 1 O
// 1 N
// 1 O
// 3
// 2
// 3
// 4

// Output 1 :

// Order for L is enqueued.
// Order for E is enqueued.
// Order for M is enqueued.
// Order for O is enqueued.
// Order for N is enqueued.
// Queue is full. Cannot enqueue more orders.
// Orders in the queue are: L E M O N
// Dequeued Order: L
// Orders in the queue are: E M O N
// Exiting program

// Input 2 :

// 1 L
// 1 E
// 1 M
// 3
// 2
// 5
// 4

// Output 2 :

// Order for L is enqueued.
// Order for E is enqueued.
// Order for M is enqueued.
// Orders in the queue are: L E M
// Dequeued Order: L
// Invalid option.
// Exiting program

// Input 3 :

// 2
// 3
// 4

// Output 3 :

// No orders in the queue.
// Queue is empty. No orders available.
// Exiting program

// Input 4 :

// 1 L
// 1 M
// 3
// 2
// 2
// 3
// 2
// 4

// Output 4 :

// Order for L is enqueued.
// Order for M is enqueued.
// Orders in the queue are: L M
// Dequeued Order: L
// Dequeued Order: M
// Queue is empty. No orders available.
// No orders in the queue.
// Exiting program

// You are using GCC
#include<stdio.h>
#define MAX 5

int front=-1,rear=-1;

char arr[MAX];

int isem(){
    return (front==-1 && rear==-1); 
}

int isFull(){
    return (rear==MAX-1); 
}

void push(char ch){
    if(isem()){
        front++;
        arr[++rear]=ch;
        printf("Order for %c is enqueued.\n",ch);
    }
    else if(isFull()){
        printf("Queue is full. Cannot enqueue more orders.\n");
    }
    else{
        arr[++rear]=ch;
        printf("Order for %c is enqueued.\n",ch);
    }
}

void pop(){
    if(isem()){
        printf("No orders in the queue.\n");
    }
    else {
         printf("Dequeued Order: %c\n",arr[front]);
        if(front ==rear){
            
        
            front=rear=-1;
        }
        else {
            front++;
        }
    }
}

void display(){
    if(isem()){
        printf("Queue is empty. No orders available.\n");
    }
    else{
        printf("Orders in the queue are:" );
        for(int i=front;i<=rear;i++){
            printf("%c ",arr[i]);
        }printf("\n");
    }
}

int main(){
    int n;char ele;
    do{
        scanf("%d",&n);
        switch(n){
            case 1:
            scanf(" %c",&ele);
            push(ele);
            break;
            case 2:
            pop();
            break;
            case 3:
            display();
            break;
            case 4:
            printf("Exiting program\n");
            break;
            default:
            printf("Invalid option.\n");
            break;
        }
    }while(n!=4);
}