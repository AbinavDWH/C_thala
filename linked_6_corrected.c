#include <stdio.h>
#include <stdlib.h>

struct node {
    int x, ex;
    struct node *next;
} *head = NULL, *head2 = NULL, *result = NULL;

typedef struct node NODE;

void ins(int x, int ex, struct node **head) {
    NODE *new_node = (NODE *)malloc(sizeof(NODE));
    new_node->x = x;
    new_node->ex = ex;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
    } else {
        NODE *p = *head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = new_node;
    }
}

void ins_result(int x, int ex) {
    NODE *new_node = (NODE *)malloc(sizeof(NODE));
    new_node->x = x;
    new_node->ex = ex;
    new_node->next = result;
    result = new_node;
}

void pol_add() {
    NODE *temp1 = head, *temp2 = head2;
    while (temp1 != NULL || temp2 != NULL) {
        if (temp1 != NULL && temp2 != NULL) {
            if (temp1->ex == temp2->ex) {
                ins_result(temp1->x + temp2->x, temp1->ex);
                temp1 = temp1->next;
                temp2 = temp2->next;
            } else if (temp1->ex > temp2->ex) {
                ins_result(temp1->x, temp1->ex);
                temp1 = temp1->next;
            } else {
                ins_result(temp2->x, temp2->ex);
                temp2 = temp2->next;
            }
        } else if (temp1 != NULL) {
            ins_result(temp1->x, temp1->ex);
            temp1 = temp1->next;
        } else if (temp2 != NULL) {
            ins_result(temp2->x, temp2->ex);
            temp2 = temp2->next;
        }
    }
}

void display() {
    NODE *p = result;
    while (p != NULL) {
        printf("%dx^%d ", p->x, p->ex);
        p = p->next;
        if (p != NULL) printf("+ ");
    }
    printf("\n");
}

int main() {
    int x, ex;
    
    // Read first polynomial
    do {
        scanf("%d %d", &x, &ex);
        ins(x, ex, &head);
    } while (ex != 0);
    
    // Read second polynomial
    do {
        scanf("%d %d", &x, &ex);
        ins(x, ex, &head2);
    } while (ex != 0);
    
    pol_add();
    display();
    
    return 0;
}