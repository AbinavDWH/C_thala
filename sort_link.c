#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Create a new node
Node* create_node(int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

// Add node to the end of the list
void add_node(Node** head, int value) {
    Node* new_node = create_node(value);
    
    if (*head == NULL) {
        *head = new_node;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Print the linked list
void print_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Free memory allocated for the list
void free_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

// Comparison function for qsort (ascending order)
int  compare_nodes(const void* a, const void* b) {
   const Node* const *node1 = (const Node**)a;
   const Node* const *node2 = (const Node**)b;
    return (*node1)->data - (*node2)->data;
}

// Sort linked list using qsort
void sort_linked_list(Node** head) {
    if (*head == NULL || (*head)->next == NULL) return;

    // Count nodes
    int count = 0;
    Node* current = *head;
    while (current != NULL) {
        count++;
        current = current->next;
    }

    // Create array of node pointers
    Node** array = (Node**)malloc(count * sizeof(Node*));
    current = *head;
    for (int i = 0; i < count; i++) {
        array[i] = current;
        current = current->next;
    }

    // Sort the array
    qsort(array, count, sizeof(Node*), compare_nodes);

    // Rebuild the linked list
    *head = array[0];
    for (int i = 0; i < count - 1; i++) {
        array[i]->next = array[i + 1];
    }
    array[count - 1]->next = NULL;

    free(array);
}

int main() {
    Node* head = NULL;
    
    // Create sample list
    add_node(&head, 5);
    add_node(&head, 2);
    add_node(&head, 7);
    add_node(&head, 1);
    add_node(&head, 3);

    printf("Original list: ");
    print_list(head);

    // Sort the list
    sort_linked_list(&head);

    printf("Sorted list:   ");
    print_list(head);

    // Free memory
    free_list(head);

    return 0;
}