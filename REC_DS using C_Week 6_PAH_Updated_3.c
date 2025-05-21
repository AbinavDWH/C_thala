// You are working as a programmer at a sports academy, and the academy holds various sports competitions regularly. 


// As part of the academy's system, you need to sort the scores of the participants in descending order using the Quick Sort algorithm.


// Write a program that takes the scores of n participants as input and uses the Quick Sort algorithm to sort the scores in descending order. Your program should display the sorted scores after the sorting process.
// Input format :

// The first line of input consists of an integer n, which represents the number of scores.

// The second line of input consists of n integers, which represent scores separated by spaces.
// Output format :

// Each line of output represents an iteration of the Quick Sort algorithm, displaying the elements of the array at that iteration.

// After the iterations are complete, the last line of output prints the sorted scores in descending order separated by space.


// Refer to the sample outputs for the formatting specifications.
// Code constraints :

// 1 ≤ n ≤10

// 1 ≤ scores ≤ 1000
// Sample test cases :
// Input 1 :

// 5
// 78 54 96 32 53

// Output 1 :

// Iteration 1: 78 54 96 53 32 
// Iteration 2: 96 54 78 
// Iteration 3: 78 54 
// Sorted Order: 96 78 54 53 32 

// Input 2 :

// 4
// 153 65 84 36

// Output 2 :

// Iteration 1: 153 65 84 36 
// Iteration 2: 153 84 65 
// Sorted Order: 153 84 65 36 

// You are using GCC
#include<stdio.h>


void swap(int *a,int *b){
   int temp=*a;
   *a=*b;
   *b=temp;
}
int part(int *arr,int low,int high){
    int p=arr[high];
    int i=low-1;
    
    for(int j=low;j<high;j++){
        if(arr[j]>=p){
            swap(&arr[++i],&arr[j]);
        }
    }    swap(&arr[i+1],&arr[high]);
    return i+1;
}
int itera=1;
void quick(int arr[],int low,int high){
    if(low<high){
        int p=part(arr,low,high);
        printf("Iteration %d:",itera++);
        for(int i=low;i<=high;i++)
        printf("%d ",arr[i]);
        printf("\n");
        quick(arr,low,p-1);
        quick(arr,p+1,high);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    quick(arr,0,n-1);
    printf("Sorted Order: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}