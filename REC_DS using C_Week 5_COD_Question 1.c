// John is learning about Binary Search Trees (BST) in his computer science class. He wants to create a program that allows users to delete a node with a given value from a BST and print the remaining nodes using an in-order traversal.


// Implement a function to help him delete a node with a given value from a BST.
// Input format :

// The first line of input consists of an integer N, representing the number of nodes in the BST.

// The second line consists of N space-separated integers, representing the values of the BST nodes.

// The third line consists of an integer V, which is the value to delete from the BST.
// Output format :

// The output prints the space-separated values in the BST in an in-order traversal, after the deletion of the specified value.

// If the specified value is not available in the tree, print the given input values in-order traversal.


// Refer to the sample output for formatting specifications.
// Code constraints :

// The given test cases will fall under the following constraints:

// 1 ≤ N ≤ 10

// 1 ≤ node values ≤ 100
// Sample test cases :
// Input 1 :

// 5
// 10 5 15 2 7
// 15

// Output 1 :

// 2 5 7 10 

// Input 2 :

// 7
// 54 62 28 95 78 23 91
// 28

// Output 2 :

// 23 54 62 78 91 95 

// Input 3 :

// 3
// 24 87 65
// 89

// Output 3 :

// // 24 65 87 

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int key) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// You are using GCC
struct TreeNode* insert(struct TreeNode* root, int key) {
    //Type your code here
    if(root==NULL){
        struct TreeNode* nn=(struct TreeNode*)malloc(sizeof(struct TreeNode));
        nn->data=key;
        nn->left=nn->right=NULL;
        return nn;
    }
    else{
        if(root->data>key){
            root->left=insert(root->left,key);
        }
        else
        root->right=insert(root->right,key);
        return root;
    }
}

struct TreeNode* findMin(struct TreeNode* root) {
    //Type your code here
    struct TreeNode* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    //Type your code here
    if(root==NULL) return NULL;
    else if(root->data>key){
        root->left=deleteNode(root->left,key);
    }
    else if(root->data<key)
    root->right=deleteNode(root->right,key);
    
    else if(root->data==key){
        if(root->left==NULL){
            struct TreeNode* temp=root;
            root=root->right;
            free(temp);
            return root;
        }
        else if(root->right==NULL){
            struct TreeNode* temp=root->left;
            free(root);
            return temp;
        }
        else{
            struct TreeNode* temp=findMin(root->right);
            root->data=temp->data;
            root->right=deleteNode(root->right,temp->data);
            return root;
        }
    }return root;
}

void inorderTraversal(struct TreeNode* root) {
    //Type your code here
    if (root==NULL) return;
    inorderTraversal(root->left);
    printf("%d ",root->data);
    inorderTraversal(root->right);
}

int main() 
{
    int N, rootValue, V;
    scanf("%d", &N);
    struct TreeNode* root = NULL;
    for (int i = 0; i < N; i++) {
        int key;
        scanf("%d", &key);
        if (i == 0) rootValue = key;
        root = insert(root, key);
    }
    scanf("%d", &V);
    root = deleteNode(root, V);
    inorderTraversal(root);
    return 0;
}