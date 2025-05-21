// You are the lead developer of a text-processing application that assists writers in organizing their thoughts. One crucial feature is a character-sorting service that helps users highlight the most critical elements of their text. 


// To achieve this, you decide to enhance the service to sort characters in descending order using the Quick-Sort algorithm. Implement the algorithm to efficiently rearrange the characters, ensuring that it is sorted in descending order.
// Input format :

// The first line of the input consists of a positive integer value N, representing the number of characters to be sorted.

// The second line of input consists of N space-separated lowercase alphabetical characters.
// Output format :

// The output displays the set of alphabetical characters, sorted in descending order.


// Refer to the sample output for the formatting specifications.
// Code constraints :

// The given test cases fall under the following constraints:

// 1 ≤ N ≤ 26
// Sample test cases :
// Input 1 :

// 5
// a d g j k

// Output 1 :

// k j g d a 

// Input 2 :

// 8
// a e f h s q m n

// Output 2 :

// s q n m h f e a 

#include <stdio.h>
#include <string.h>

// You are using GCC
void swap(char* a, char* b) {
    //Type your code here
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(char arr[], int low, int high) {
    //Type your code here
    int p=arr[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(arr[j]>p){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    
    return i+1;
}

void quicksort(char arr[], int low, int high) {
    //Type your code here
    if(low<high){
        int p=partition(arr,low,high);
        
        quicksort(arr,low,p-1);
        quicksort(arr,p+1,high);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    char characters[n];

    for (int i = 0; i < n; i++) {
        char input;
        scanf(" %c", &input);
        characters[i] = input;
    }

    quicksort(characters, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%c ", characters[i]);
    }

    return 0;
}