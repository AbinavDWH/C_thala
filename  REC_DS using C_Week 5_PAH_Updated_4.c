// // Yogi is working on a program to manage a binary search tree (BST) containing integer values. He wants to implement a function that removes nodes from the tree that fall outside a specified range defined by a minimum and maximum value.


// // Help Yogi by writing a function that achieves this.
// // Input format :

// // The first line of input consists of an integer N, representing the number of elements to be inserted into the BST.

// // The second line consists of N space-separated integers, representing the elements to be inserted into the BST.

// // The third line consists of two space-separated integers min and max, representing the minimum value and the maximum value of the range.
// // Output format :

// // The output prints the remaining elements of the BST in an in-order traversal, after removing nodes that fall outside the specified range.


// // Refer to the sample output for formatting specifications.
// // Code constraints :

// // The given test cases will fall under the following constraints:

// // 1 ≤ N ≤ 20

// // 1 ≤ elements ≤ 1000

// // 1 ≤ min, max ≤ 1000
// // Sample test cases :
// // Input 1 :

// // 5
// // 10 5 15 20 12
// // 5 15

// // Output 1 :

// // 5 10 12 15 

// // Input 2 :

// // 7
// // 10 5 15 20 12 18 8
// // 8 18

// // Output 2 :

// // 8 10 12 15 18 

//     // You are using GCC
//     #include<stdio.h>
//     #include<stdlib.h>
    
//     struct node {
//         int data;
//         struct node *right,*left;
//     }*root=NULL;
    
//     typedef struct node NODE;
    
//     NODE *insert(NODE *r,int x){
//         if(r==NULL){
//             NODE *nn=(NODE *)malloc(sizeof(NODE));
//             nn->data=x;
//             nn->left=nn->right=NULL;
//             return nn;
//         }
//         else{
//             if(r->data>x){
//                 r->left=insert(r->left,x);
//             }
//             else if(r->data<x) r->right=insert(r->right,x);
//             return r;
            
//         }
//     }
    
//     NODE *findmin(NODE *f){
//         while(f->left!=NULL){
//             f=f->left;
//         }
//         return f;
//     }
    
//     NODE *del(NODE *r,int d){
//         if(r==NULL) return NULL;
//         if(r->data>d)
//         r->left=del(r->left,d);
//         else if(r->data<d)
//         r->right=del(r->right,d);
        
//         else if(r->data==d){
//             NODE *temp=NULL;
//             if(r->left==NULL){
//                 temp=r;
//                 r=r->right;
//             }
//             else if(r->right==NULL){
//                 temp=r;
//                 r=r->left;
//             }
//             else{
//                 temp=findmin(r->right);
//                 r->data=temp->data;
//                 r->right=del(r->right,temp->data);
//             }
//             free(temp);
//             return r;
//         }return r;
//     }
    
//     void display(NODE *r,int start,int end){
//         if(r==NULL) return;
//         display(r->left,start,end);
//         if(r->data>=start&&r->data<=end)
//         printf("%d ",r->data);
//         display(r->right,start,end);
//     }
    
//     NODE* delr(NODE *r,int start,int end){
//         if(r==NULL) return NULL;
//         r->left=delr(r->left,start,end);
//         r->right=delr(r->right,start,end);
//         if(r->data<start || r->data>end){
//             r=del(r,r->data);
//         }
//         return r;
//     }
    
//     int main(){
//         int n,ele;
//         scanf("%d",&n);
//         for(int i=0;i<n;i++){
//             scanf("%d",&ele);
//             root=insert(root,ele);
//         }
//         int f,e;
//         scanf("%d %d",&f,&e);
//         root=delr(root,f,e);
//         display(root,f,e);
        
//     }

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a new node into the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return newNode(data);
    }
    
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    
    return root;
}

// Function to perform in-order traversal of the BST
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function to remove nodes outside the specified range [min, max]
struct Node* trimBST(struct Node* root, int min, int max) {
    if (root == NULL) {
        return NULL;
    }
    
    // If the current node's data is less than the min, discard the left subtree
    if (root->data < min) {
        struct Node* rightNode = trimBST(root->right, min, max);
        free(root);
        return rightNode;
    }
    
    // If the current node's data is greater than the max, discard the right subtree
    if (root->data > max) {
        struct Node* leftNode = trimBST(root->left, min, max);
        free(root);
        return leftNode;
    }
    
    // Otherwise, trim both subtrees and return the root
    root->left = trimBST(root->left, min, max);
    root->right = trimBST(root->right, min, max);
    return root;
}

int main() {
    int N, min, max;
    
    // Read input
    scanf("%d", &N);
    struct Node* root = NULL;
    
    for (int i = 0; i < N; i++) {
        int value;
        scanf("%d", &value);
        root = insert(root, value);
    }
    
    scanf("%d %d", &min, &max);
    
    // Trim the BST
    root = trimBST(root, min, max);
    
    // Print the in-order traversal of the trimmed BST
    inorder(root);
    printf("\n");
    
    return 0;
}
