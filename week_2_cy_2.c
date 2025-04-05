/*
Vanessa is learning about the doubly linked list data structure and is eager to play around with it. She decides to find out how the elements are inserted at the beginning and end of the list.


Help her implement a program for the same.
Input format :

The first line of input contains an integer N, representing the size of the doubly linked list.

The next line contains N space-separated integers, each representing the values to be inserted into the doubly linked list.
Output format :

The first line of output prints the integers, after inserting them at the beginning, separated by space.

The second line prints the integers, after inserting at the end, separated by space.


Refer to the sample output for formatting specifications.
Code constraints :

The given test cases fall under the following constraints:

1 ≤ N ≤ 10

1 ≤ elements ≤ 1000
Sample test cases :
Input 1 :

5
1 2 3 4 5

Output 1 :

5 4 3 2 1 
1 2 3 4 5 

Input 2 :

6
78 63 25 94 16 15

Output 2 :

15 16 94 25 63 78 
78 63 25 94 16 15 
*/

// You are using GCC
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next,*pre;
}*head=NULL,*tail=NULL;

typedef struct node NODE;

void insert(int x){
    NODE *nn=(NODE *)malloc(sizeof(NODE));
    nn->data=x;
    nn->next=NULL;
    nn->pre=NULL;
    if(head==NULL && tail==NULL)
    head=nn;
    else if(head!=NULL && tail==NULL){
        tail=nn;
        nn->pre=head;
        head->next=nn;
    }
    else{
        tail->next=nn;
        nn->pre=tail;
        tail=nn;
    }
}
void disrev(){
    NODE *temp=tail;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->pre;
    }printf("\n");
}
void dis(){
    NODE *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}


int main(){
    int n,ele;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&ele);
        insert(ele);
    }
    disrev();
    dis();
}