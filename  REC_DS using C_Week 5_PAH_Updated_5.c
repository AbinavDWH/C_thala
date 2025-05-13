// Joseph, a computer science student, is interested in understanding binary search trees (BST) and their node arrangements. He wants to create a program to explore BSTs by inserting elements into a tree and displaying the nodes using post-order traversal of the tree.


// Write a program to help Joseph implement the program.
// Input format :

// The first line of input consists of an integer N, representing the number of elements to insert into the BST.

// The second line consists of N space-separated integers data, which is the data to be inserted into the BST.
// Output format :

// The output prints N space-separated integer values after the post-order traversal.


// Refer to the sample output for formatting specifications.
// Code constraints :

// The given test cases will fall under the following constraints:

// 1 ≤ N ≤ 20

// 1 ≤ data ≤ 1000
// Sample test cases :
// Input 1 :

// 4
// 10 15 5 3

// Output 1 :

// 3 5 15 10 

// Input 2 :

// 8
// 80 40 120 20 60 100 140 10 

// Output 2 :

// 10 20 60 40 100 140 120 80 

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
        else{
            if(r->data>x){
                r->left=insert(r->left,x);
            }
            else if(r->data<x) r->right=insert(r->right,x);
            return r;
        }
    }
    
    void display(NODE *r){
        if(r==NULL) return;
        display(r->left);
        display(r->right);
        printf("%d ",r->data);
    }
    
    int main(){
        int n,ele;
        scanf("%d ",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&ele);
            root=insert(root,ele);
        }
        display(root);
    }