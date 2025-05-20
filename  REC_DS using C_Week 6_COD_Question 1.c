
// John and Mary are collaborating on a project that involves data analysis. They each have a set of age data, one sorted in ascending order and the other in descending order. However, their analysis requires the data to be in ascending order.


// Write a program to help them merge the two sets of age data into a single sorted array in ascending order using merge sort.
// Input format :

// The first line of input consists of an integer N, representing the number of age values in each dataset.

// The second line consists of N space-separated integers, representing the ages of participants in John's dataset (in ascending order).

// The third line consists of N space-separated integers, representing the ages of participants in Mary's dataset (in descending order).
// Output format :

// The output prints a single line containing space-separated integers, which represents the merged dataset of ages sorted in ascending order.


// Refer to the sample output for formatting specifications.
// Code constraints :

// The given test cases will fall under the following constraints:

// 1 ≤ N ≤ 10

// 1 ≤ age ≤ 100
// Sample test cases :
// Input 1 :

// 5
// 1 3 5 7 9
// 10 8 6 4 2

// Output 1 :

// 1 2 3 4 5 6 7 8 9 10 

// Input 2 :

// 4
// 14 19 25 28
// 34 29 18 15

// Output 2 :

// 14 15 18 19 25 28 29 34 

#include <stdio.h>

// You are using GCC
void merge(int arr[], int left[], int right[], int left_size, int right_size) {
    //Type your code here
    int i=0,j=0,k=0;
    while(i<left_size && j<right_size){
        if(left[i]<=right[j]){
            arr[k]=left[i];
            i++;
        }else{
            arr[k]=right[j];
            j++;
        }
        k++;
    }
    
    while(i<left_size){
        arr[k]=left[i];
            i++;
            k++;
    }
    
    while( j<right_size){
        arr[k]=right[j];
            j++;
            k++;
    }
}

void mergeSort(int arr[], int size) {
    //Type your code here
    if(size<2){
        return;
    }
    
    int m=size/2;
    int l[m],r[size-m];
    for(int i=0;i<m;i++){
        l[i]=arr[i];
    }
    for(int i=m;i<size;i++){
        r[i-m]=arr[i];
    }
    
    mergeSort(l,m);
    mergeSort(r,size-m);
    
    merge(arr,l,r,m,size-m);
}

int main() {
    int n, m;
    scanf("%d", &n);
    int arr1[n], arr2[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr2[i]);
    }
    int merged[n + n];
    mergeSort(arr1, n);
    mergeSort(arr2, n);
    merge(merged, arr1, arr2, n, n);
    for (int i = 0; i < n + n; i++) {
        printf("%d ", merged[i]);
    }
    return 0;
}