// Vishnu, a math enthusiast, is given a task to explore the magic of numbers. He has an array of positive integers, and his goal is to find the integer with the highest digit sum in the sorted array using the merge sort algorithm.


// You have to assist Vishnu in implementing the merge sort algorithm.
// Input format :

// The first line of input consists of an integer N, representing the number of elements in the array.

// The second line consists of N space-separated integers, representing the array elements.
// Output format :

// The first line of output prints "The sorted array is: " followed by the sorted array, separated by a space.

// The second line prints "The integer with the highest digit sum is: " followed by an integer representing the highest-digit sum.


// Refer to the sample output for formatting specifications.
// Code constraints :

// In this scenario, the test cases fall under the following constraints:

// 1 ≤ N ≤ 10

// 1 ≤ array elements ≤ 1000
// Sample test cases :
// Input 1 :

// 5
// 123 456 789 321 654

// Output 1 :

// The sorted array is: 123 321 456 654 789 
// The integer with the highest digit sum is: 789

// Input 2 :

// 6
// 789 123 456 876 234 567

// Output 2 :

// The sorted array is: 123 234 456 567 789 876 
// The integer with the highest digit sum is: 789

// You are using GCC
#include<stdio.h>
#include<string.h>

void merge(int arr[],int l,int m,int r){
    int n1=m-l+1;
    int n2=r-m;
    
    int arr1[n1],arr2[n2];
    
    for(int i=0;i<n1;i++){
        arr1[i]=arr[l+i];
    }
    
    for(int i=0;i<n2;i++)
    arr2[i]=arr[m+1+i];
    
    int i=0,j=0,k=l;
    
    while(i<n1&&j<n2){
        if(arr1[i]<=arr2[j]){
            arr[k]=arr1[i];
            i++;
        }else{
            arr[k]=arr2[j];
            j++;
        }k++;
    }
    
    while(i<n1){
        arr[k]=arr1[i];
        i++;
        k++;
    }
    
    while(j<n2){
        arr[k]=arr2[j];
        j++;
        k++;
    }
}

void mergesort(int arr[],int l,int r){
    
    if(l<r){
        int m=l+(r-l)/2;
        
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        
        merge(arr,l,m,r);
    }
    
    
}

int sum(int n){
    char s[10];
    sprintf(s,"%d",n);
    int t=strlen(s);
    int su=0;
    for(int i=0;i<t;i++){
        su+=s[i]-'0';
    }
    return su;
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    mergesort(arr,0,n-1);
    printf("The sorted array is: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }printf("\n");
    int n_arr[n];
    for(int i=0;i<n;i++){
        n_arr[i]=sum(arr[i]);
    }
    int big=n_arr[0];
    int k=0;
    for(int i=1;i<n;i++){
        if(big<n_arr[i]){
            big=n_arr[i];
            k=i;
        }
    }
    printf("The integer with the highest digit sum is: %d",arr[k]);
}