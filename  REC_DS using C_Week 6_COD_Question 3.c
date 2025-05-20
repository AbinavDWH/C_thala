
// Jose has an array of N fractional values, represented as double-point numbers. He needs to sort these fractions in increasing order and seeks your help.


// Write a program to help Jose sort the array using the merge sort algorithm.
// Input format :

// The first line of input consists of an integer N, representing the number of fractions to be sorted.

// The second line consists of N double-point numbers, separated by spaces, representing the fractions array.
// Output format :

// The output prints N double-point numbers, sorted in increasing order, and rounded to three decimal places.


// Refer to the sample output for formatting specifications.
// Code constraints :

// The given test cases will fall under the following constraints:

// 1 ≤ N ≤ 10
// Sample test cases :
// Input 1 :

// 4
// 0.123 0.543 0.321 0.789

// Output 1 :

// 0.123 0.321 0.543 0.789 

// Input 2 :

// 3
// 0.1 0.01 0.001

// Output 2 :

// 0.001 0.010 0.100 

// You are using GCC
int compare(double a, double b) {
    //Type your code here
    return (a<=b)?1:0;
}
void merge(double arr[], int l, int m, int r) {
    //Type your code here
    int n1=m-l+1;
    int n2=r-m;
    
    double arr1[n1],arr2[n2];
    
    for(int i=0;i<n1;i++){
        arr1[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++)
    arr2[i]=arr[m+1+i];
    
    int i=0,j=0,k=l;
    
    
    while(i<n1&&j<n2){
        if(compare(arr1[i],arr2[j])){
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
void mergeSort(double arr[], int l, int r) {
    //Type your code here
    if (l<r){
        int m=l+(r-l)/2;
        
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        
        merge(arr,l,m,r);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    double fractions[n];
    for (int i = 0; i < n; i++) {
        scanf("%lf", &fractions[i]);
    }
    mergeSort(fractions, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%.3f ", fractions[i]);
    }
    return 0;
}