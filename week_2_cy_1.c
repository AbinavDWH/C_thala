/*
Sam is learning about two-way linked lists. He came across a problem where he had to populate a two-way linked list and print the original as well as the reverse order of the list. Assist him with a suitable program.
Input format :

The first line of input consists of an integer n, representing the number of elements in the list.

The second line consists of n space-separated integers, representing the elements.
Output format :

The first line displays the message: "List in original order:"

The second line displays the elements of the doubly linked list in the original order.

The third line displays the message: "List in reverse order:"

The fourth line displays the elements of the doubly linked list in reverse order.


Refer to the sample output for the formatting specifications.
Code constraints :

The given test cases fall under the following constraints:

1 ≤ n ≤ 30
Sample test cases :
Input 1 :

5
1 2 3 4 5

Output 1 :

List in original order:
1 2 3 4 5 
List in reverse order:
5 4 3 2 1 

Input 2 :

8
45 63 95 74 14 25 36 96

Output 2 :

List in original order:
45 63 95 74 14 25 36 96 
List in reverse order:
96 36 25 14 74 95 63 45 

*/

// You are using GCC
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next,*pre;
}*head=NULL,*tail=NULL;

typedef struct node NODE;

void insert(int x){
    NODE *nn=(NODE *)malloc(sizeof(NODE));
    nn->data=x;
    nn->next=NULL;
    nn->pre=NULL;
    if(head==NULL && tail==NULL){
        head=nn;
    }
    else if(head!=NULL && tail==NULL){
        tail=nn;
        nn->pre=head;
        head->next=tail;
    }
    else{
        tail->next=nn;
        nn->pre=tail;
        tail=nn;
    }
}

void display(){
    NODE *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }printf("\n");
}

void displayrev(){
    NODE *temp=tail;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->pre;
    }
}

int main(){
    int n,ele;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&ele);
        insert(ele);
    }
    printf("List in original order:\n");
    display();
    printf("List in reverse order:\n");
    displayrev();
}