#include<stdio.h>
#include<stdlib.h>
struct node {
int data;
struct node *next;
};
struct node *insertbeg(struct node *head, int x) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = head;
    head=newnode;
    return head;
}
struct node * insertend(struct node *head, int x)
{
struct node *newnode;
struct node *p;
p=head;
newnode=(struct node *)malloc(sizeof(struct node *));
newnode->data=x;
newnode->next=NULL;
while(p->next!=NULL)
p=p->next;
p->next=newnode;
return head;
}

void printList(struct node *head) {
struct node *temp = head;
while (temp != NULL) {
printf("%d -> ", temp->data);
temp = temp->next;
}
printf("NULL\n");
}
int main() {

    struct node *head = NULL;
    int choice, ele;
    
    do {
    printf("\n1. Insert at Beginning\n2. Insert at End\n3. Print List\n4. Exit\nChoice: ");
    scanf("%d", &choice);
    
    switch (choice) {
    case 1:
    printf("Enter element: ");
    scanf("%d", &ele);
    head = insertbeg(head, ele);
    break;
    case 2:
    printf("Enter element: ");
    scanf("%d", &ele);
    head = insertend(head, ele);
    break;
    case 3:
printList(head);
break;
case 4:
printf("Exiting the program.\n");
exit(0);
default:
printf("Invalid Choice. Try again.\n");
break;
}
} while (choice != 4);
return 0;
}