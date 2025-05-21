
// Meera is organizing her art supplies, which are represented as a list of integers: red (0), white (1), and blue (2). She needs to sort these supplies so that all items of the same color are adjacent, in the order red, white, and blue. To achieve this efficiently, Meera decides to use QuickSort to sort the items. Can you help Meera arrange her supplies in the desired order?
// Input format :

// The first line of input consists of an integer n, representing the number of items in the list.

// The second line consists of n space-separated integers, where each integer is either 0 (red), 1 (white), or 2 (blue).
// Output format :

// The output prints the sorted list of integers in a single line, where integers are arranged in the order red (0), white (1), and blue (2).


// Refer to the sample output for formatting specifications.
// Code constraints :

// 1 ≤ n ≤ 100

// nums[i] ∈ {0,1,2}
// Sample test cases :
// Input 1 :

// 6
// 2 0 2 1 1 0

// Output 1 :

// Sorted colors:
// 0 0 1 1 2 2 

// Input 2 :

// 3
// 2 0 1

// Output 2 :

// Sorted colors:
// 0 1 2 

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
        if(arr[j]<p){
            swap(&arr[++i],&arr[j]);
        }
    }swap(&arr[i+1],&arr[high]);
    return i+1;
}

void quickSort(int arr[],int low,int high){
    if(low<high){
        int p=part(arr,low,high);
        
        quickSort(arr,low,p-1);
        quickSort(arr,p+1,high);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    quickSort(arr,0,n-1);
    printf("Sorted colors:\n");
    for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
}