
// Alex is working on a project that involves merging and sorting two arrays. He wants to write a program that merges two arrays, sorts the merged array in ascending order, removes duplicates, and prints the sorted array without duplicates.


// Help Alex to implement the program using the merge sort algorithm.
// Input format :

// The first line of input consists of an integer N, representing the number of elements in the first array.

// The second line consists of N integers, separated by spaces, representing the elements of the first array.

// The third line consists of an integer M, representing the number of elements in the second array.

// The fourth line consists of M integers, separated by spaces, representing the elements of the second array.
// Output format :

// The output prints space-separated integers, representing the merged and sorted array in ascending order, with duplicate elements removed.


// Refer to the sample output for the formatting specifications.
// Code constraints :

// The given test cases will fall under the following constraints:

// 1 ≤ N, M ≤ 10

// 1 ≤ array elements ≤ 100
// Sample test cases :
// Input 1 :

// 4
// 1 2 3 4
// 3
// 3 4 5

// Output 1 :

// 1 2 3 4 5 

// Input 2 :

// 4
// 14 27 31 79
// 4
// 43 58 65 79

// Output 2 :

// 14 27 31 43 58 65 79 

// You are using GCC
#include<stdio.h>

void merge(int arr[],int left[],int right[],int l,int r){
    
    int i=0,j=0,k=0;
    
    while(i<l&&j<r){
        if(left[i]<=right[j]){
            arr[k]=left[i];
            i++;
        }
        else{
            arr[k]=right[j];
            j++;
        }
        k++;
    }
    
    while(i<l){
        arr[k]=left[i];
        i++;
        k++;
    }
    
    while(j<r){
        arr[k]=right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[],int n){
    if(n<2) return;
    int m=n/2;
    
    int arr1[m],arr2[n-m];
    
    for(int i=0;i<m;i++){
        arr1[i]=arr[i];
    }
    for(int i=0;i<n-m;i++){
        arr2[i]=arr[m+i];
    }
    
    mergeSort(arr1,m);
    mergeSort(arr2,n-m);
    
    merge(arr,arr1,arr2,m,n-m);
    
}

int main(){
    int n1,n2;
    scanf("%d",&n1);
    int arr1[n1];
    for(int i=0;i<n1;i++){
        scanf("%d",&arr1[i]);
    }
    mergeSort(arr1,n1);
    scanf("%d",&n2);
    int arr2[n2];
    for(int i=0;i<n2;i++){
        scanf("%d",&arr2[i]);
    }
    mergeSort(arr2,n2);
    int mer[n1+n2];
    merge(mer,arr1,arr2,n1,n2);
   
    for(int i=0;i<n1+n2;i++){
    if(i!=n1+n2-1&&mer[i]==mer[i+1])
    continue;
    printf("%d ",mer[i]);
        
    }
}