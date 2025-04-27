// You are a software developer tasked with building a module for a scientific calculator application. The primary function of this module is to convert infix mathematical expressions, which are easier for users to read and write, into postfix notation (also known as Reverse Polish Notation). Postfix notation is more straightforward for the application to evaluate because it removes the need for parentheses and operator precedence rules.


// The scientific calculator needs to handle various mathematical expressions with different operators and ensure the conversion is correct. Your task is to implement this infix-to-postfix conversion algorithm using a stack-based approach.


// Example


// Input:

// a+b

// Output:

// ab+

// Explanation:

// The postfix representation of (a+b) is ab+.
// Input format :

// The input is a string, representing the infix expression.
// Output format :

// The output displays the postfix representation of the given infix expression.


// Refer to the sample output for formatting specifications.
// Code constraints :

// The maximum length of the string is 100.

// The expression will be well-formed and valid, meaning there will be no mismatched parentheses or invalid characters.
// Sample test cases :
// Input 1 :

// a+(b*e)

// Output 1 :

// abe*+

// Input 2 :

// (a+b)*(c^d+e)^(f+g)*h

// Output 2 :

// ab+cd^e+fg+^*h*

// Input 3 :

// a+b

// Output 3 :

// ab+

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));

    if (!stack)
        return NULL;

    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));

    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

char peek(struct Stack* stack) {
    return stack->array[stack->top];
}

char pop(struct Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';  
}

void push(struct Stack* stack, char op) {
    stack->array[++stack->top] = op;
}
// You are using GCC
int isOperand(char ch) {
    //type your code here
    return ((ch>='a' && ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9'));
}

int Prec(char ch) {
   //type your code here
   if(ch=='^'){
       return 3;
   }
   else if(ch=='*'||ch=='/')
   return 2;
   else if(ch=='+'||ch=='-')
   return 1;
   else 
   return 0;
}

void infixToPostfix(char* exp) {
    struct Stack* stack=createStack(100); 
    int l=strlen(exp);
    //type your code here
    for(int i=0;i<l;i++){
        int temp=exp[i];
        if(isOperand(temp)){
            printf("%c",temp);
        }else if(temp=='('){
            push(stack,temp);
        }else if(temp==')'){
            while(!isEmpty(stack)&&peek(stack)!='('){
                printf("%c",pop(stack));
            }
            if(!isEmpty(stack)&&peek(stack)=='(')
            pop(stack);
        }else{
            while(!isEmpty(stack)&&Prec(temp)<=Prec(peek(stack))){
                printf("%c",pop(stack));
            }
            push(stack,temp);
        }
        
    }
    while(!isEmpty(stack)){
        printf("%c",pop(stack));
    }
}
int main() {
    char exp[100];
    scanf("%s", exp);

    infixToPostfix(exp);
    return 0;
}