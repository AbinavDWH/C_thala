// Sharon is developing a programming challenge for a coding competition. The challenge revolves around implementing a character-based stack data structure using an array.


// Sharon's project involves a stack that can perform the following operations:

//     Push a Character: Users can push a character onto the stack.
//     Pop a Character: Users can pop a character from the stack, removing and displaying the top character.
//     Display Stack: Users can view the current elements in the stack.
//     Exit: Users can exit the stack operations application.


// Write a program to help Sharon to implement a program that performs the given operations.
// Input format :

// The input consists of integers corresponding to the operation that needs to be performed:

// Choice 1: Push the character onto the stack. If the choice is 1, the following input is a space-separated character, representing the character to be pushed onto the stack.

// Choice 2: Pop the character from the stack.

// Choice 3: Display the characters in the stack.

// Choice 4: Exit the program.
// Output format :

// The output displays messages according to the choice and the status of the stack:

//     If the choice is 1, push the given character to the stack and display the pushed character having the prefix "Pushed: ".
//     If the choice is 2, undo the character from the stack and display the character that is popped having the prefix "Popped: ".
//     If the choice is 2, and if the stack is empty without any characters, print "Stack is empty. Nothing to pop."
//     If the choice is 3, print the elements in the stack having the prefix "Stack elements: ".
//     If the choice is 3, and there are no characters in the stack, print "Stack is empty."
//     If the choice is 4, exit the program.
//     If any other choice is entered, print "Invalid choice"


// Refer to the sample output for formatting specifications.
// Code constraints :

// The given test cases fall under the following specifications:

// The maximum size of the stack is 100.

// Choice: 1, 2, 3, or 4
// Sample test cases :
// Input 1 :

// 2
// 4

// Output 1 :

// Stack is empty. Nothing to pop.

// Input 2 :

// 1 A
// 1 B
// 2
// 3
// 4

// Output 2 :

// Pushed: A
// Pushed: B
// Popped: B
// Stack elements: A 

// Input 3 :

// 9
// 4

// Output 3 :

// Invalid choice

// Input 4 :

// 1 A
// 2
// 3
// 4

// Output 4 :

// Pushed: A
// Popped: A
// Stack is empty.

// Input 5 :

// 1 X
// 1 Y
// 1 Z
// 3
// 2
// 2
// 2
// 2
// 4

// Output 5 :

// Pushed: X
// Pushed: Y
// Pushed: Z
// Stack elements: Z Y X 
// Popped: Z
// Popped: Y
// Popped: X
// Stack is empty. Nothing to pop.
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

char items[MAX_SIZE];
int top = -1;

void initialize() {
    top = -1;
}
bool isFull() {
    return top == MAX_SIZE - 1;
}

bool isEmpty() {
    return top == -1;
}
// You are using GCC

void push(char value) {
    //Type your code here
    if(isFull()){
        printf("Stack overflow\n");
    }
    else{
        items[++top]=value;
        printf("Pushed: %c\n",value);
    }
}

char pop() {
    //Type your code here
    if(isEmpty()){
        printf("Stack is empty.Nothing to pop.\n");
        return '\0';
    }else{
        printf("Popped: %c\n",items[top--]);
        return '\0';
    }
}
void display() {
    //Type your code here
    if(isEmpty()){
        printf("Stack is empty.\n");
    }else{
        printf("Stack elements: ");
        int temp=top;
        while(temp!=-1){
            printf("%c",items[temp--]);
        }printf("\n");
    }
}

int main() {
    initialize();
    int choice;
    char value;

    while (true) {
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                scanf(" %c", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}