
    
    
  #include <stdio.h>
#include <stdlib.h>

void printPattern(int n) {
    int size = 2 * n - 1;  // Size of the pattern (size x size)
    int pattern[size][size];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int min = i < j ? i : j;  // Minimum of row or column index
            min = min < size - i ? min : size - i - 1;  // Minimum of (size - row index)
            min = min < size - j ? min : size - j - 1;  // Minimum of (size - column index)
            pattern[i][j] = n - min;
        }
    }

    // Print the pattern
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", pattern[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n ;
      // Change this value to generate the pattern for different n
    scanf("%d",&n);
    printPattern(n);
    return 0;
}

  	

    
