// Arun is exploring operations on binary search trees (BST). He wants to write a program with an unsorted distinct integer array that represents the BST keys and construct a height-balanced BST from it. 



// After constructing, he wants to perform the following operations that can alter the structure of the tree and traverse them using a level-order traversal:

// Insertion
// Deletion


// Your task is to assist Arun in completing the program without any errors.

// Input format :
// The first line of input consists of an integer N, representing the number of initial keys in the BST.

// The second line consists of N space-separated integers, representing the initial keys.

// The third line consists of an integer X, representing the new key to be inserted into the BST.

// The fourth line consists of an integer Y, representing the key to be deleted from the BST.

// Output format :
// The first line of output prints "Initial BST: " followed by a space-separated list of keys in the initial BST after constructing it in level order traversal.

// The second line prints "BST after inserting a new node X: " followed by a space-separated list of keys in the BST after inserting X n level order traversal.

// The third line prints "BST after deleting node Y: " followed by a space-separated list of keys in the BST after deleting Y n level order traversal.



// Refer to the sample output for formatting specifications.

// Code constraints :
// The given test cases fall under the following constraints:

// 1 ≤ N ≤ 15

// 1 ≤ initial keys ≤ 1000

// 1 ≤ X, Y ≤ 500

// Sample test cases :
// Input 1 :
// 5
// 25 14 56 28 12
// 34
// 12
// Output 1 :
// Initial BST: 25 14 56 12 28 
// BST after inserting a new node 34: 25 14 56 12 28 34 
// BST after deleting node 12: 25 14 56 28 34 
// Input 2 :
// 6
// 5 1 4 6 9 8
// 7
// 9
// Output 2 :
// Initial BST: 5 1 6 4 9 8 
// BST after inserting a new node 7: 5 1 6 4 9 8 7 
// BST after deleting node 9: 5 1 6 4 8 7 

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a BST node
typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;

// Create a new BST node
Node* newNode(int key) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

// Insert a key into BST
Node* insert(Node* root, int key) {
    if (root == NULL) return newNode(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    return root;
}

// Find the node with minimum value in BST
Node* minValueNode(Node* node) {
    while (node && node->left != NULL)
        node = node->left;
    return node;
}

// Delete a key from BST
Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: get the inorder successor
        Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Queue node for level-order traversal
typedef struct QueueNode {
    Node* treeNode;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, Node* treeNode) {
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->treeNode = treeNode;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

Node* dequeue(Queue* q) {
    if (q->front == NULL) return NULL;
    QueueNode* temp = q->front;
    Node* result = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return result;
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}

// Print level-order traversal
void levelOrder(Node* root) {
    if (!root) return;
    Queue* q = createQueue();
    enqueue(q, root);
    while (!isEmpty(q)) {
        Node* current = dequeue(q);
        printf("%d ", current->key);
        if (current->left) enqueue(q, current->left);
        if (current->right) enqueue(q, current->right);
    }
    free(q);
}

int main() {
    int N;
    scanf("%d", &N);

    int keys[15];
    for (int i = 0; i < N; i++) {
        scanf("%d", &keys[i]);
    }

    int X, Y;
    scanf("%d", &X);
    scanf("%d", &Y);

    // Step 1: Insert in the given order to form initial BST
    Node* root = NULL;
    for (int i = 0; i < N; i++) {
        root = insert(root, keys[i]);
    }

    printf("Initial BST: ");
    levelOrder(root);
    printf("\n");

    // Step 2: Insert new key X
    root = insert(root, X);
    printf("BST after inserting a new node %d: ", X);
    levelOrder(root);
    printf("\n");

    // Step 3: Delete key Y
    root = deleteNode(root, Y);
    printf("BST after deleting node %d: ", Y);
    levelOrder(root);
    printf("\n");

    return 0;
}
