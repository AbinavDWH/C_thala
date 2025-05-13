// Emily is studying binary search trees (BST). She wants to write a program that inserts characters into a BST and then finds and prints the minimum and maximum values.


// Guide her with the program.
// Input format :

// The first line of input consists of an integer N, representing the number of values to be inserted into the BST.

// The second line consists of N space-separated characters.
// Output format :

// The first line of output prints "Minimum value: " followed by the minimum value of the given inputs.

// The second line prints "Maximum value: " followed by the maximum value of the given inputs.


// Refer to the sample outputs for formatting specifications.
// Code constraints :

// The given test cases fall under the following specifications:

// 1 ≤ N ≤ 20

// The input values will be upper-case characters.
// Sample test cases :
// Input 1 :

// 5
// Z E W T Y

// Output 1 :

// Minimum value: E
// Maximum value: Z

// Input 2 :

// 7
// S P O R T Y U

// Output 2 :

// Minimum value: O
// Maximum value: Y

// You are using GCC
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left,*right;
}*root=NULL;


typedef struct node NODE;

NODE *insert(NODE *r,char x)
{
    if(r==NULL){
        NODE *nn=(NODE *)malloc(sizeof(NODE));
        nn->data=x;
        nn->left=nn->right=NULL;
        return nn;
    }
    else{
        if(r->data>x) r->left=insert(r->left,x);
        else if(r->data<x) r->right=insert(r->right,x);
        return r;
    }
}


void min(){
    NODE *temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    printf("Minimum value: %c\n",temp->data);
}

void max(){
    NODE *temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    printf("Maximum value: %c",temp->data);
}

int main(){
    int n;
    scanf("%d",&n);
    char ele;
    for(int i=0;i<n;i++){
        scanf(" %c",&ele);
        root=insert(root,ele);
    }
    min();
    max();
}