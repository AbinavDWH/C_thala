
// Nandhini asked her students to arrange a set of numbers in ascending order. She asked the students to arrange the elements using insertion sort, which involves taking each element and placing it in its appropriate position within the sorted portion of the array.


// Assist them in the task.
// Input format :

// The first line of input consists of the value of n, representing the number of array elements.

// The second line consists of n elements, separated by a space.
// Output format :

// The output prints the sorted array, separated by a space.


// Refer to the sample output for formatting specifications.
// Code constraints :

// The given test cases fall under the following constraints:

// 1 ≤ n ≤ 100

// -104 ≤ array elements ≤ 104
// Sample test cases :
// Input 1 :

// 5
// 67 28 92 37 59

// Output 1 :

// 28 37 59 67 92 

// Input 2 :

// 8
// -57 92 -89 -25 18 26 31 -49

// Output 2 :

// -89 -57 -49 -25 18 26 31 92 

// Expected Time Complexity : O(N^2)
// Expected Space Complexity : O(N^2) 

#include <stdio.h>

// You are using GCC

#include<stdlib.h>


void insertionSort(int arr[], int n) {
    //Type your code here
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    
}

void printArray(int arr[], int n) {
    
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, n);   
    printArray(arr, n);      
    return 0;
}