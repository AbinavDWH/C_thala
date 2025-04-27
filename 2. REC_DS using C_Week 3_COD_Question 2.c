
// Sanjeev is in charge of managing a library's book storage, and he wants to create a program that simplifies this task. His goal is to implement a program that simulates a stack using an array.


// Help him in writing a program that provides the following functionality:

//     Add Book ID to the Stack (Push): You can add a book ID to the top of the book stack. 
//     Remove Book ID from the Stack (Pop): You can remove the top book ID from the stack and display its details. If the stack is empty, you cannot remove any more book IDs.
//     Display Books ID in the Stack (Display): You can view the books ID currently on the stack.
//     Exit the Library: You can choose to exit the program.

// Input format :

// The input consists of integers corresponding to the operation that needs to be performed:

// Choice 1: Push the book onto the stack. If the choice is 1, the following input is a space-separated integer, representing the ID of the book to be pushed onto the stack.

// Choice 2: Pop the book ID from the stack.

// Choice 3: Display the book ID in the stack.

// Choice 4: Exit the program.
// Output format :

// The output displays messages according to the choice and the status of the stack:

//     If the choice is 1, push the given book ID to the stack and display the corresponding message.
//     If the choice is 2, pop the book ID from the stack and display the corresponding message.
//     If the choice is 2, and if the stack is empty without any book ID, print "Stack Underflow"
//     If the choice is 3, print the book IDs in the stack.
//     If the choice is 3, and there are book IDs in the stack, print "Stack is empty"
//     If the choice is 4, exit the program and display the corresponding message.
//     If any other choice is entered, print "Invalid choice"


// Refer to the sample output for the exact text and format.
// Code constraints :

// The maximum size of the stack is defined as 100.

// Choice: 1, 2, 3, or 4
// Sample test cases :
// Input 1 :

// 1 19
// 1 28
// 2
// 3
// 2
// 4

// Output 1 :

// Book ID 19 is pushed onto the stack
// Book ID 28 is pushed onto the stack
// Book ID 28 is popped from the stack
// Book ID in the stack: 19 
// Book ID 19 is popped from the stack
// Exiting the program

// Input 2 :

// 9
// 4

// Output 2 :

// Invalid choice
// Exiting the program

// Input 3 :

// 1 7
// 1 50
// 2
// 2
// 3
// 4

// Output 3 :

// Book ID 7 is pushed onto the stack
// Book ID 50 is pushed onto the stack
// Book ID 50 is popped from the stack
// Book ID 7 is popped from the stack
// Stack is empty
// Exiting the program

// Input 4 :

// 1 25
// 2
// 2
// 3
// 4

// Output 4 :

// Book ID 25 is pushed onto the stack
// Book ID 25 is popped from the stack
// Stack Underflow
// Stack is empty
// Exiting the program

// You are using GCC
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
}*top=NULL;
typedef struct node NODE;

void push(int x){
    NODE *nn=(NODE *)malloc(sizeof(NODE));
    nn->data=x;
    nn->next=NULL;
    if(top==NULL)
    top=nn;
    else{
        nn->next=top;
        top=nn;
        
    }
}

void pop(){
    if(top==NULL){
    printf("Stack Underflow\n");
    return;
        
    }
    else{
        NODE *temp=top;
        printf("Book ID %d is popped from the stack\n",top->data);
        top=top->next;
        free(temp);
    }
}

void display(){
    if(top==NULL){
    printf("Stack is empty\n");
    return;
    }
    else{
        NODE *temp=top;
        printf("Book ID in the stack: ");
        while(temp!=NULL){
           printf("%d ",temp->data);
            temp=temp->next;
        }printf("\n");
    }
}

int main(){
    int n,ele;
   do{
       scanf("%d",&n);
       switch(n){
           case 1:
           scanf("%d",&ele);
           push(ele);
           printf("Book ID %d is pushed onto the stack\n",ele);
           break;
           case 2:
           pop();
           break;
           case 3:
           display();
           break;
           case 4:
           printf("Exiting the program\n");
           break;
           default:
           printf("Invalid choice\n");
       }
   }while(n!=4);
}