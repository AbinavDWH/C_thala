
// Arun is working on a Binary Search Tree (BST) data structure. His goal is to implement a program that reads a series of integers and inserts them into a BST. Once the integers are inserted, he needs to add a given integer value to each node in the tree and find the maximum value in the BST.


// Your task is to help Arun implement this program.
// Input format :

// The first line of input consists of an integer N, representing the number of elements to be inserted into the BST.

// The second line consists of N space-separated integers, each representing an element to be inserted into the BST.

// The third line consists of an integer add, representing the value to be added to each node in the BST.
// Output format :

// The output prints the maximum value in the BST after adding the add value.


// Refer to the sample output for formatting specifications.
// Code constraints :

// The test cases will fall under the following constraints:

// 1 ≤ N ≤ 15

// 1 ≤ elements ≤ 1000

// 1 ≤ add ≤ 200
// Sample test cases :
// Input 1 :

// 5
// 10 5 15 20 25
// 5

// Output 1 :

// 30

// Input 2 :

// 8
// 12 32 65 47 81 73 19 65
// 9

// Output 2 :

// 90

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
        NODE *nn=(NODE *)malloc(sizeof( NODE));
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

void findmax(int k){
    NODE *temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    printf("%d",temp->data+k);
}

int main(){
    int n,ele;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&ele);
        root=insert(root,ele);
    }
    scanf("%d",&n);
    findmax(n);
}