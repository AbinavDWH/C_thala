
// Ravi is given an array of integers and is tasked with sorting it in a unique way. He needs to sort the elements in such a way that the elements at odd positions are in descending order, and the elements at even positions are in ascending order. Ravi decided to use the Insertion Sort algorithm for this task.


// Your task is to help ravi, to create even_odd_insertion_sort function to sort the array as per the specified conditions and then print the sorted array. 


// Example


// Input:

// 10

// 25 36 96 58 74 14 35 15 75 95


// Output:

// 96 14 75 15 74 36 35 58 25 95 
// Input format :

// The first line of input consists of a single integer, N, which represents the size of the array.

// The second line contains N space-separated integers, representing the elements of the array.
// Output format :

// The output displays the sorted array using the even-odd insertion sort algorithm and prints the sorted array.


// Refer to the sample output for formatting specifications.
// Code constraints :

// 1 ≤ N ≤ 10

// 1 ≤ Elements of the array ≤ 100
// Sample test cases :
// Input 1 :

// 4
// 3 1 4 2

// Output 1 :

// 4 1 3 2 

// Input 2 :

// 6
// 6 4 8 2 10 12

// Output 2 :

// 10 2 8 4 6 12 

// Input 3 :

// 10
// 25 36 96 58 74 14 35 15 75 95

// Output 3 :

// 96 14 75 15 74 36 35 58 25 95 

// Input 4 :

// 10
// 25 36 96 58 74 14 35 15 75 95

// Output 4 :

// // 96 14 75 15 74 36 35 58 25 95 

// You are using GCC
#include<stdio.h>

void insertsort(int arr[],int n,int q){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0&&((key<arr[j] && q==0)||(key>arr[j] && q==1))){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    int m=n/2;
    int arr1[n-m],arr2[m];
    int k1=0,k2=0;
    for(int i=0;i<n;i++){
        if(i%2==0){
            arr1[k1++]=arr[i];
        }else{
            arr2[k2++]=arr[i];
        }
    }
    
    insertsort(arr1,n-m,1);
    insertsort(arr2,m,0);
k1=0;k2=0;
    for(int i=0;i<n;i++){
        if(i%2==0&&k1<(n-m)) printf("%d ",arr1[k1++]);
        if(i%2==0&&k2<m) printf("%d ",arr2[k2++]);
    }
    
}