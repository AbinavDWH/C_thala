// Edward has a Binary Search Tree (BST) and needs to find the k-th largest element in it. 


// Given the root of the BST and an integer k, help Edward determine the k-th largest element in the tree. If k exceeds the number of nodes in the BST, return an appropriate message.
// Input format :

// The first line of input consists of integer n, the number of nodes in the BST.

// The second line consists of the n elements, separated by space.

// The third line consists of the value of k.
// Output format :

// The output prints the kth largest element in the binary search tree.

// For invalid inputs, print "Invalid value of k".


// Refer to the sample output for formatting specifications.
// Code constraints :

// The given test cases fall under the following constraints:

// 1 ≤ n ≤ 100

// 1 ≤ BST elements ≤ 1000
// Sample test cases :
// Input 1 :

// 7
// 8 4 12 2 6 10 14
// 1

// Output 1 :

// 14

// Input 2 :

// 4
// 1 7 8 5
// 5

// Output 2 :

// Invalid value of k

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
        if(r->data>x) r->left=insert(r->left,x);
        
        else if(r->data<x) r->right=insert(r->right,x);
        return r;
    }
}
int j=0;

void idk(int arr[],NODE *r){
    if(r==NULL) return;
    idk(arr,r->left);
    arr[j++]=r->data;
    idk(arr,r->right);
}


int main(){
    int n,ele;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&ele);
        root=insert(root,ele);
    }
    int k,arr[n];
    scanf("%d",&k);
    if(k>n || k<=0){ printf("Invalid value of k"); return 0;}
    else{
        idk(arr,root);
        printf("%d",arr[n-k]);
    }
}