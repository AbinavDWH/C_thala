// Raj is a software developer, and his team is building an application that processes user inputs in the form of strings containing brackets. One of the essential features of the application is to validate whether the input string meets specific criteria.


// During testing, Raj inputs the string "(([])){}". The application correctly returns "Valid string" because the input satisfies the criteria: every opening bracket (, [, and { has a corresponding closing bracket ), ], and }, arranged in the correct order.


// Next, Raj tests the application with the string "([)]". This time, the application correctly returns "Invalid string" because the opening bracket [ is incorrectly closed by the bracket ), which violates the validation rules.


// Finally, Raj enters the string "{[()]}". The application correctly identifies it as a "Valid string" since all opening brackets are matched with the corresponding closing brackets in the correct order.


// As a software developer, Raj's responsibility is to ensure that the application works reliably and produces accurate results for all input strings, following the validation rules. He accomplishes this by using a method for solving such problems.
// Input format :

// The input comprises a string representing a sequence of brackets that need to be validated.
// Output format :

// The output prints "Valid string" if the string is valid. Otherwise, it prints "Invalid string".


// Refer to the sample output for formatting specifications.
// Code constraints :

// The maximum length of the string is 100.
// Sample test cases :
// Input 1 :

// (([])){}

// Output 1 :

// Valid string

// Input 2 :

// ([)]

// Output 2 :

// Invalid string

// Input 3 :

// {[()]}

// Output 3 :

// Valid string

// You are using GCC
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char data;
    struct node *next;
}*top=NULL;

typedef struct node NODE;

void push(char ch){
    NODE *nn=(NODE *)malloc(sizeof(NODE));
    nn->data=ch;
    nn->next=top;
    top=nn;
}

void pop(){
    NODE *temp=top;
    top=top->next;
    free(temp);
    
}
    

int main(){
    char s[101];
    scanf("%s",s);
    size_t l=strlen(s);
    for(int i=0;i<l;i++){
        char temp=s[i];
        if(temp=='('||temp=='['||temp=='{'){
        push(temp);
            
        }
       else if(temp==')'||temp==']'||temp=='}'){
           if(top==NULL){
           printf("Invalid string");
           return 0;}
           if((temp==')'&&top->data=='(')||(temp==']'&&top->data=='[')||(temp=='}'&&top->data=='{'))
           pop();
           else{
               printf("Invalid string");
               return 0;
           }
       }
    }if(top==NULL)
    {
        printf("Valid string");
    }
    else
    printf("Invalid string");
}