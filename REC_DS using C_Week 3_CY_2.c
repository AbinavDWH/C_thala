// Suppose you are building a calculator application that allows users to enter mathematical expressions in infix notation. One of the key features of your calculator is the ability to convert the entered expression to postfix notation using a Stack data structure. 


// Write a function to convert infix notation to postfix notation using a Stack.
// Input format :

// The input consists of a string, an infix expression that includes only digits(0-9), and operators(+, -, *, /).
// Output format :

// The output displays the equivalent postfix expression of the given infix expression.


// Refer to the sample output for formatting specifications.
// Code constraints :

// The infix expression will contain only valid arithmetic operators (+, -, *, /), numbers, and parentheses.

// The infix expression will have a maximum length of 30 characters.

// The numbers in the infix expression will be non-negative integers.
// Sample test cases :
// Input 1 :

// 1+2*3/4-5

// Output 1 :

// 123*4/+5-

// Input 2 :

// 5+6-4*8/2

// Output 2 :

// 56+48*2/-

// You are using GCC
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
    char data;
    struct node *next;
}*top=NULL;

typedef struct node NODE;

void push(char x){
    NODE *nn=(NODE *)malloc(sizeof(NODE));
    nn->data=x;
    nn->next=top;
    top=nn;
}
int isemp(){
    if(top==NULL)
    return 1;
    else 
    return 0;
}
int pop(){
    NODE *temp=top;
    top=top->next;
    int t=temp->data;free(temp);
    return t;
}

int operand(char ch){
    return(ch>='0'&&ch<='9');
}
int prec(char ch){
    if(ch=='^')
    return 3;
    else if(ch=='*'||ch=='/')
    return 2;
    else if(ch=='+'||ch=='-')
    return 1;
    else 
    return 0;
}

void infix2post(char *num){
    int l=strlen(num);
    for(int i=0;i<l;i++){
        char temp=num[i];
        if(operand(temp))
        printf("%c",temp);
        else if(temp=='('){
            push(temp);
        }
        else if(temp==')'){
            
            while(!isemp()&&top->data!='('){
                printf("%c",pop());
            }
            if(!isemp()&&top->data=='(')
            pop();
        }
        else{
            while(!isemp()&&prec(temp)<=prec(top->data)){
                printf("%c",pop());
            }
            push(temp);
        }
    }
    while(!isemp()){
        printf("%c",pop());
    }
}

int main(){
    char s[30];
    scanf("%s",s);
    infix2post(s);
}