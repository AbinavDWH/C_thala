// Sharon is developing a queue using an array. She wants to provide the functionality to find the Kth largest element. The queue should support the addition and retrieval of the Kth largest element effectively. The maximum capacity of the queue is 10.


// Assist her in the program.
// Input format :

// The first line of input consists of an integer N, representing the number of elements in the queue.

// The second line consists of N space-separated integers.

// The third line consists of an integer K.
// Output format :

// For each enqueued element, print a message: "Enqueued: " followed by the element.

// The last line prints "The [K]th largest element: " followed by the Kth largest element.


// Refer to the sample output for formatting specifications.
// Code constraints :

// The maximum size of the queue is 10.

// 1 ≤ N ≤ 10

// 1 ≤ values ≤ 100

// 4 ≤ K ≤ 10
// Sample test cases :
// Input 1 :

// 5
// 23 45 93 87 25
// 4

// Output 1 :

// Enqueued: 23
// Enqueued: 45
// Enqueued: 93
// Enqueued: 87
// Enqueued: 25
// The 4th largest element: 25

// Input 2 :

// 8
// 26 71 82 67 18 29 34 52
// 7

// Output 2 :

// Enqueued: 26
// Enqueued: 71
// Enqueued: 82
// Enqueued: 67
// Enqueued: 18
// Enqueued: 29
// Enqueued: 34
// Enqueued: 52
// The 7th largest element: 26

// You are using GCC
#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int arr[MAX],front=-1,rear=-1;

int isfull(){
    return (rear==MAX-1);
}

int compare(void const *a,void const *b){
    return(*(int *)b-*(int *)a);
}

void enq(int x){
    if(front==-1 && rear==-1){
        front++;
        arr[++rear]=x;
        printf("Enqueued :%d\n",x);
    }
    else if(isfull()){
        return;
    }
    else{
        arr[++rear]=x;
        printf("Enqueued :%d\n",x);
    }
}

int main(){
    int n,l,ele;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&ele);
        enq(ele);
    }
    scanf("%d",&l);
    qsort(arr,n,sizeof(int),compare);
    printf("The %dth largest element: %d",l,arr[l-1]);
    return 0;
}