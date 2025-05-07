// John, a computer science student, is learning about binary search trees (BST) and their properties. He decides to write a program to create a BST, display it in post-order traversal, and find the minimum value present in the tree.


// Help him by implementing the program.
// Input format :

// The first line of input consists of an integer N, representing the number of elements to insert into the BST.

// The second line consists of N space-separated integers data, which is the data to be inserted into the BST.
// Output format :

// The first line of output prints the space-separated elements of the BST in post-order traversal.

// The second line prints the minimum value found in the BST.


// Refer to the sample output for formatting specifications.
// Code constraints :

// The given test cases will fall under the following constraints:

// 1 ≤ N ≤ 20

// 1 ≤ data ≤ 1000
// Sample test cases :
// Input 1 :

// 3
// 5 10 15

// Output 1 :

// 15 10 5 
// The minimum value in the BST is: 5

// Input 2 :

// 10
// 10 5 15 3 7 12 18 20 25 30

// Output 2 :

// 3 7 5 12 30 25 20 18 15 10 
// The minimum value in the BST is: 3

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// You are using GCC
struct Node* insert(struct Node* root, int data) {
    //Type your code here
    if(root==NULL){
        struct Node* nn=(struct Node*)malloc(sizeof(struct Node));
        nn->data=data;
        nn->left=nn->right=NULL;
        return nn;
    }
    else{
        if(root->data>data){
            root->left=insert(root->left,data);
        }
        else if(root->data<data)
        root->right=insert(root->right,data);
        return root;
    }
}

void displayTreePostOrder(struct Node* root) {
    //Type your code here
    if(root==NULL) return;
    displayTreePostOrder(root->left);
    displayTreePostOrder(root->right);
    printf("%d ",root->data);
}

int findMinValue(struct Node* root) {
    //Type your code here
    struct Node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return (temp->data);
}

int main() {
    struct Node* root = NULL;
    int n, data;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insert(root, data);
    }

    displayTreePostOrder(root);
    printf("\n");

    int minValue = findMinValue(root);
    printf("The minimum value in the BST is: %d", minValue);

    return 0;
}