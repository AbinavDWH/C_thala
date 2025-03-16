#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL; // Properly initialize head to NULL

void insert(int new_data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = NULL;

    if (head == NULL) { // If list is empty, set head to new node
        head = new_node;
        return;
    }

    struct node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

int main() {
    int n, x;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        insert(x);
    }

    struct node *temp = head;
    while (temp != NULL) { // Fix loop condition
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
