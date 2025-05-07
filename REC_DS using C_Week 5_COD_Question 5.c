
// In his computer science class, John is learning about Binary Search Trees (BST). He wants to build a BST and find the maximum value in the tree.


// Help him by writing a program to insert nodes into a BST and find the maximum value in the tree.
// Input format :

// The first line of input consists of an integer N, representing the number of nodes in the BST.

// The second line consists of N space-separated integers, representing the values of the nodes to insert into the BST.
// Output format :

// The output prints the maximum value in the BST.


// Refer to the sample output for formatting specifications.
// Code constraints :

// The given test cases will fall under the following constraints:

// 1 ≤ N ≤ 10

// 1 ≤ node values ≤ 100

// The input values are unique integers.
// Sample test cases :
// Input 1 :

// 5
// 10 5 15 2 7

// Output 1 :

// 15

// Input 2 :

// 3
// 10 15 20

// Output 2 :

// 20

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
        }else{
            root->right=insert(root->right,key);
        }
        return root;
    }
}

int findMax(struct TreeNode* root) {
    //Type your code here
    struct TreeNode* temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return (temp->data);
}

int main() {
    int N, rootValue;
    scanf("%d", &N);

    struct TreeNode* root = NULL;

    for (int i = 0; i < N; i++) {
        int key;
        scanf("%d", &key);
        if (i == 0) rootValue = key;
        root = insert(root, key);
    }

    int maxVal = findMax(root);
    if (maxVal != -1) {
        printf("%d", maxVal);
    } 

    return 0;
}