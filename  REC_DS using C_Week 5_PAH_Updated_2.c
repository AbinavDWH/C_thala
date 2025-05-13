// Viha, a software developer, is working on a project to automate searching for a target value in a Binary Search Tree (BST). She needs to create a program that takes an integer target value as input and determines if that value is present in the BST or not.


// Write a program to assist Viha.
// Input format :

// The first line of input consists of integers separated by spaces, which represent the elements to be inserted into the BST. The input is terminated by entering -1.

// The second line consists of an integer target, which represents the target value to be searched in the BST.
// Output format :

// If the target value is found in the BST, print "[target] is found in the BST".

// Else, print "[target] is not found in the BST"


// Refer to the sample output for formatting specifications.
// Code constraints :

// In this scenario, the test cases fall under the following constraints:

// 1 ≤ elements ≤ 500

// 1 ≤ target ≤ 500
// Sample test cases :
// Input 1 :

// 5 3 7 1 4 6 8 -1
// 4

// Output 1 :

// 4 is found in the BST

// Input 2 :

// 45 65 85 91 -1
// 90

// Output 2 :

// 90 is not found in the BST

// You are using GCC
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left,*right;
}*root=NULL;

typedef struct node NODE;

NODE *insert(NODE *r,int x){
    if(r==NULL){
        NODE *nn=(NODE *)malloc(sizeof(NODE));
        nn->data=x;
        nn->left=nn->right=NULL;
        return nn;
    }
    else {
        if(r->data>x){
            r->left=insert(r->left,x);
        }
        else if(r->data<x){
            r->right=insert(r->right,x);
        }
        return r;
    }
    
}

int flag=0;

void find(NODE *r,int f){
    if (r==NULL) return;
    
    find(r->left,f);
    if(r->data==f){
    flag=1;
    return;
    }
    find(r->right,f);
}


int main(){
    int n;
    while(1){
        scanf("%d",&n);
        if(n==-1) break;
        root=insert(root,n);
    }
    scanf("%d",&n);
    find(root,n);
    if(flag==1){
        printf("%d is found in the BST",n);
    }
    else{
        printf("%d is not found in the BST",n);
    }
}
    
