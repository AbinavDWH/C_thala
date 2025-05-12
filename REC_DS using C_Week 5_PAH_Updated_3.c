
// Aishu is participating in a coding challenge where she needs to reconstruct a Binary Search Tree (BST) from given preorder traversal data and then print the in-order traversal of the reconstructed BST. 


// Since Aishu is just learning about tree data structures, she needs your help to write a program that does this efficiently.
// Input format :

// The first line consists of an integer n, representing the number of nodes in the BST.

// The second line of input contains n integers separated by spaces, which represent the preorder traversal of the BST.
// Output format :

// The output displays n space-separated integers, representing the in-order traversal of the reconstructed BST.


// Refer to the sample output for the formatting specifications.
// Code constraints :

// The given test cases fall under the following constraints:

// 1 ≤ N ≤ 15

// 1 ≤ tree elements ≤ 100
// Sample test cases :
// Input 1 :

// 6
// 10 5 1 7 40 50

// Output 1 :

// 1 5 7 10 40 50 

// Input 2 :

// 8
// 20 12 14 35 25 30 46 66

// Output 2 :

// 12 14 20 25 30 35 46 66 

// You are using GCC
#include<stdio.h>
#include<stdlib.h>

struct node{
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
    else{
        if(r->data>x)
        r->left=insert(r->left,x);
        else if(r->data<x){
            r->right=insert(r->right,x);
        }
        return r;
    }
}

void display(NODE *r){
    if (r==NULL) return;
    display(r->left);
    printf("%d ",r->data);
    display(r->right);
}

int main(){
    int n,ele;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&ele);
        root=insert(root,ele);
    }
    display(root);
}