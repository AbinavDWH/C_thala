// Buvi is working on a project that requires implementing an array-stack data structure with an additional feature to find the minimum element.


// Buvi needs to implement a program that simulates a stack with the following functionalities:

//     Push: Adds an element onto the stack.
//     Pop: Removes the top element from the stack.
//     Find Minimum: Finds the minimum element in the stack.


// Buvi's implementation should efficiently handle these operations with a maximum stack size of 20.
// Input format :

// The first line of input consists of an integer N, representing the number of elements to push onto the stack.

// The second line consists of N space-separated integer values, representing the elements to be pushed onto the stack.
// Output format :

// The first line of output displays "Minimum element in the stack: " followed by the minimum element in the stack after pushing all elements.

// The second line displays "Popped element: " followed by the popped element.

// The third line displays "Minimum element in the stack after popping: " followed by the minimum element in the stack after popping one element.


// Refer to the sample output for the formatting specifications.
// Code constraints :

// 2 ≤ N ≤ 20

// 1 ≤ elements in the stack ≤ 100
// Sample test cases :
// Input 1 :

// 4
// 5 2 8 1

// Output 1 :

// Minimum element in the stack: 1
// Popped element: 1
// Minimum element in the stack after popping: 2

// Input 2 :

// 11
// 7 4 9 1 15 8 2 14 6 10 12

// Output 2 :

// Minimum element in the stack: 1
// Popped element: 12
// Minimum element in the stack after popping: 1

// You are using GCC
#include<stdio.h>
#include<stdlib.h>

struct stack{
    int data;
    struct stack *next;
}*top=NULL;

typedef struct stack NODE;

void push(int x){
    NODE *nn=(NODE *)malloc(sizeof(NODE));
    nn->data=x;
    nn->next=top;top=nn;
}

void pop(){
    if(top==NULL){
        return;
    }
    NODE *temp=top;
    top=top->next;
    printf("Popped element: %d\n",temp->data);
    free(temp);
}
int min(){
    NODE *temp=top;
    int s=top->data;
    while(temp!=NULL){
        if(s>temp->data){
            s=temp->data;
        }temp=temp->next;
    }
    
    return s;
}

int main(){
    int n,ele;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&ele);
        push(ele);
    }
    printf("Minimum element in the stack: %d\n",min());
    pop();
    printf("Minimum element in the stack after popping: %d",min());
}