// Ravi is given an array of integers and is tasked with sorting it uniquely. He needs to sort the elements in such a way that the elements at odd positions are in descending order, and the elements at even positions are in ascending order.


// Your task is to help Ravi create a program that uses insertion sort to sort the array as per the specified conditions and then print the sorted array. Position starts from 1.


// Example

// Input:

// Size of the array = 10

// Array elements = 25 36 96 58 74 14 35 15 75 95


// Output:

// Resultant array = 96 14 75 15 74 36 35 58 25 95 


// Explanation:

// Initial Array: 25 36 96 58 74 14 35 15 75 95

// Elements at odd positions (1, 3, 5, 7, 9): 25 96 74 35 75

// Elements at odd positions sorted descending order: 96 75 74 35 25

// Elements at even positions (2, 4, 6, 8, 10): 36 58 14 15 95

// Elements at even positions sorted ascending order: 14 15 36 58 95

// So, the final array is 96 14 75 15 74 36 35 58 25 95.
// Input format :

// The first line contains an integer N, representing the number of elements in the array.

// The second line contains N space-separated integers, representing the elements of the array.
// Output format :

// The output displays integers, representing the sorted array elements separated by a space.


// Refer to the sample output for formatting specifications.
// Code constraints :

// In this scenario, the given test cases will fall under the following constraints:

// 1 ≤ N ≤ 10

// 1 ≤ Each element of the array ≤ 100

// Position starts from 1.
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

// 96 14 75 15 74 36 35 58 25 95 

#include<stdio.h>

void insertion(int arr[],int n,int q)
{
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
            arr1[k1]=arr[i];
            k1++;
        }else{
            arr2[k2]=arr[i];
            k2++;
        }
    }
    
    
    insertion(arr1,n-m,1);
    insertion(arr2,m,0);
    
    int i=0,j=0;
    for(int k=0;k<n;k++){
        if( k%2==0&&i<n-m) printf("%d ",arr1[i++]);
        if (k%2==0&&j<(m)) printf("%d ",arr2[j++]);
    }
}