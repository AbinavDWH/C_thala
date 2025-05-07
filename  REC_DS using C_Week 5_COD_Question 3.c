// You are required to implement basic operations on a Binary Search Tree (BST), like insertion and searching.


// Insertion: Given a list of integers, construct a Binary Search Tree by repeatedly inserting each integer into the tree according to the rules of a BST.

// Searching: Given an integer, search for its presence in the constructed Binary Search Tree. Print whether the integer is found or not.


// Write a program to calculate this efficiently.
// Input format :

// The first line of input consists of an integer n, representing the number of nodes in the binary search tree.

// The second line consists of the values of the nodes, separated by space as integers.

// The third line consists of an integer representing, the value that is to be searched.
// Output format :

// The output prints, "Value <value> is found in the tree." if the given value is present, otherwise it prints: "Value <value> is not found in the tree."


// Refer to the sample output for formatting specifications.
// Code constraints :

// The given test cases fall under the following specifications:

// 1 ≤ n ≤ 104

// −10 ≤ node value ≤ 103

// 1 ≤ key ≤ 104
// Sample test cases :
// Input 1 :

// 7
// 8 3 10 1 6 14 23
// 6

// Output 1 :

// Value 6 is found in the tree.

// Input 2 :

// 4
// 8 3 10 15
// 9

// Output 2 :

// Value 9 is not found in the tree.

// You are using GCC
#include<stdio.h>
#include<stdlib.h>

int flag=0;

struct node {
int data;
struct node *left,*right;
}*root=NULL;

typedef struct node NODE;

NODE* ins(NODE *i,int value){
    if(i==NULL){
        NODE *nn=(NODE *)malloc(sizeof(NODE));
        nn->data=value;
        nn->left=nn->right=NULL;
        return nn;
    }
    else{
        if(i->data>value){
            i->left=ins(i->left,value);
        }
        else if(i->data<value){
            i->right=ins(i->right,value);
        }
        return i;
    }
}

void display(NODE *n,int s){
    if(n==NULL)
    return;
    display(n->left,s);
    if(n->data==s)
    flag=1;
    display(n->right,s);
}

int main(){
    int n,ele;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&ele);
        root=ins(root,ele);
    }
    scanf("%d",&n);
    display(root,n);
    if(flag==0){
        printf("Value %d is not found in the tree.",n);
    }
    else
     printf("Value %d is found in the tree.",n);
}