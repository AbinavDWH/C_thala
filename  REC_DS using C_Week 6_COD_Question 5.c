
// Kavya, a software developer, is analyzing data trends. She has a list of integers and wants to identify the nth largest number in the list after sorting the array using QuickSort.


// To optimize performance, Kavya is required to use QuickSort to sort the list before finding the nth largest number.
// Input format :

// The first line of input consists of an integer n, representing the size of the array.

// The second line consists of n space-separated integers, representing the elements of the array nums.

// The third line consists of an integer k, representing the position of the largest number you need to print after sorting the array.
// Output format :

// The output prints the k-th largest number in the sorted array (sorted in ascending order).


// Refer to the sample output for formatting specifications.
// Code constraints :

// The given test cases fall under the following constraints:

// 3 ≤ n ≤ 3000

// 1 ≤ k ≤ n

// −100000Quicksort ≤ nums[i] ≤ 1000000
// Sample test cases :
// Input 1 :

// 6
// -1 0 1 2 -1 -4
// 3

// Output 1 :

// 0

// Input 2 :

// 3
// 9 7 5
// 1

// Output 2 :

// 9

#include <stdio.h>
#include <stdlib.h>

// You are using GCC
void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

int partition(int arr[], int low, int high) {
    //Type your code here
    int p=arr[high];
    int i=low-1;
    
    for(int j=low;j<high;j++){
        if(arr[j]>p){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }swap(&arr[i+1],&arr[high]);
    return i+1;
}

void quickSort(int arr[], int low, int high) {
    //Type your code here
    if(low<high){
        int m=partition(arr,low,high);
        
        quickSort(arr,low,m-1);
        quickSort(arr,m+1,high);
    }
}

void findNthLargest(int* nums, int n, int k) {
    //Type your code here
    int c=1;
    quickSort(nums,0,n-1);
    
    printf("%d ",nums[k-1]);
}

int main() {
    int n, k;
    scanf("%d", &n);
    int* nums = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    scanf("%d", &k); 
    findNthLargest(nums, n, k); 
    free(nums);
    return 0;
}