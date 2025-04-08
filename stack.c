#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int top=-1;

int arr[MAX];

void ins(int x){
    if(top==MAX-1){
        printf("Stack is full\n");
    }
    else{
        arr[++top]=x;
    }
}

void pop(){
    if(top==-1){
        printf("Stack is empty\n");
        }
        else{
            printf("%d\n",arr[top--]);
        }
}

void peek(){
    if(top==-1){
        printf("Stack is empty\n");
        }
        else{
            printf("%d\n",arr[top]);
        }
}

void display(){
    int i=top;
    if(top==-1){
        printf("Stack is empty\n");
        }
     //   int i=top;
        else{
            do{
                printf("%d ",arr[i--]);
            }while(i!=-1);
        }printf("\n");
}

int main(){
    int choice,x;
    while(1){
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter element to push: ");
            scanf("%d",&x);
            ins(x);
            break;
            case 2:
            pop();
            break;
            case 3:
            peek();
            break;
            case 4:
            display();
            break;
            case 5:
            exit(0);
            default:
            printf("Invalid choice\n");
            }
            }


}