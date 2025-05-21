// You are working on an optimization task for a sorting algorithm that uses insertion sort. Your goal is to determine the efficiency of the algorithm by counting the number of swaps needed to sort an array of integers.


// Write a program that takes an array as input and calculates the number of swaps performed during the insertion sort process.


// Example 1:


// Input:

// 5

// 2 1 3 1 2


// Output: 

// 4


// Explanation:

// Step 1: [2, 1, 3, 1, 2] (No swaps)

// Step 2: [1, 2, 3, 1, 2] (1 swap, element 1 shifts 1 place to the left)

// Step 3: [1, 2, 3, 1, 2] (No swaps)

// Step 4: [1, 1, 2, 3, 2] (2 swaps; element 1 shifts 2 places to the left)

// Step 5: [1, 1, 2, 2, 3] (1 swap, element 2 shifts 1 place to the left)

// Total number of swaps: 1 + 2 + 1 = 4


// Example 2:


// Input:

// 7

// 12 15 1 5 6 14 11


// Output:

// 10


// Explanation:

// Step 1: [12, 15, 1, 5, 6, 14, 11] (No swaps)

// Step 2: [12, 15, 1, 5, 6, 14, 11] (1 swap, element 15 shifts 1 place to the left)

// Step 3: [12, 15, 1, 5, 6, 14, 11] (No swaps)

// Step 4: [1, 12, 15, 5, 6, 14, 11] (2 swaps, element 1 shifts 2 places to the left)

// Step 5: [1, 5, 12, 15, 6, 14, 11] (1 swap, element 5 shifts 1 place to the left)

// Step 6: [1, 5, 6, 12, 15, 14, 11] (2 swaps, element 6 shifts 2 places to the left)

// Step 7: [1, 5, 6, 12, 14, 15, 11] (1 swap, element 14 shifts 1 place to the left)

// Step 8: [1, 5, 6, 11, 12, 14, 15] (3 swaps, element 11 shifts 3 places to the left)

// Total number of swaps: 1 + 2 + 1 + 2 + 1 + 3 = 10
// Input format :

// The first line of input consists of an integer n, representing the number of elements in the array.

// The second line of input consists of n space-separated integers, representing the elements of the array.
// Output format :

// The output prints the number of swaps performed during the insertion sort process.


// Refer to the sample output for the formatting specifications.
// Code constraints :

// In this scenario, the given test cases will fall under the following constraints:

// 1 ≤ n ≤ 10

// 1 ≤ array elements ≤ 100
// Sample test cases :
// Input 1 :

// 5
// 2 1 3 1 2

// Output 1 :

// 4

// Input 2 :

// 7
// 12 15 1 5 6 14 11

// Output 2 :

// 10

// You are using GCC
#include<stdio.h>

int main(){
    int n,c=0;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
            c++;
        }
        arr[j+1]=key;
    }
    printf("%d ",c);
}