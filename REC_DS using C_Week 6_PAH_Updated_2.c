// You're a coach managing a list of finishing times for athletes in a race. The times are stored in an array, and you need to sort this array in ascending order to determine the rankings.


// You'll use the insertion sort algorithm to accomplish this.
// Input format :

// The first line of input contains an integer n, representing the number of athletes.

// The second line contains n space-separated integers, each representing the finishing time of an athlete in seconds.
// Output format :

// The output prints the sorted finishing times of the athletes in ascending order.


// Refer to the sample output for formatting specifications.
// Code constraints :

// The given test cases fall under the following constraints:

// 1 ≤ n ≤ 20

// 10 ≤ finishing time ≤ 120
// Sample test cases :
// Input 1 :

// 5
// 75 89 65 90 70

// Output 1 :

// 65 70 75 89 90 

// Input 2 :

// 5
// 60 65 70 75 80

// Output 2 :

// 60 65 70 75 80 

// Input 3 :

// 5
// 90 85 80 75 70

// Output 3 :

// 70 75 80 85 90 

// Input 4 :

// 5
// 80 85 80 70 85

// Output 4 :

// 70 80 80 85 85 

// You are using GCC
#include<stdio.h>

int main(){
    int n;
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
        }
        arr[j+1]=key;
    }
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
}