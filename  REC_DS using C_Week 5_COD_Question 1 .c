
// Charan is designing a garden where each tree has a specific height, represented as nodes in a binary search tree. Charan needs help traversing the garden in post-order and determining the tallest tree.


// Your task is to build the binary search tree from the tree heights, perform a post-order traversal, and find the tallest tree for Charan.
// Input format :

// The first line of input consists of an integer n, representing the number of trees (nodes) in the garden (binary search tree).

// The second line consists of n space-separated integers, representing the height of each tree.
// Output format :

// The first line of output prints the heights of the trees in post-order traversal.

// The second line prints the height of the tallest tree in the garden.


// Refer to the sample output for formatting specifications.
// Code constraints :

// The given test cases fall under the following constraints:

// 1 ≤ n ≤ 15

// 1 ≤ tree height ≤ 100
// Sample test cases :
// Input 1 :

// 3
// 1 8 3

// Output 1 :

// 3 8 1 
// Tallest Tree: 8

// Input 2 :

// 5
// 5 3 8 2 9

// Output 2 :

// 2 3 9 8 5 
// Tallest Tree: 9


#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 

#define MAX_NODES 100

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};


// You are using GCC
typedef struct Node NODE;
struct Node* insertBST(struct Node* root, int data) {
    //Type your code here
    if(root==NULL){
        struct Node *nn=(NODE *)malloc(sizeof(NODE));
    nn->data=data;
    nn->left=NULL;
    nn->right=NULL;
    
    return nn;
    }
    else if(root->data>data){
        root->left=insertBST(root->left,data);
        }else if(root->data<data){
    root->right=insertBST(root->right,data);
        
    }return root;
}

void postOrderTraversalAndMax(struct Node* root, int* maxVal) {
    //Type your code here
    if(root==NULL)
    return;
    postOrderTraversalAndMax(root->left,&root->data);
    postOrderTraversalAndMax(root->right,&root->data);
    printf("%d ",root->data);
    if(*maxVal<0){
        NODE *temp=root;
        while(temp->right!=NULL)
        temp=temp->right;
        *maxVal=temp->data;
    }
}
int main() {
    struct Node* root = NULL;
    int n, data;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insertBST(root, data);
    }
    int maxVal = INT_MIN;
    postOrderTraversalAndMax(root, &maxVal);
    printf("\n");
    printf("Tallest Tree: %d", maxVal);
    return 0;
}