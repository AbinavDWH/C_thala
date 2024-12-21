#include <stdio.h>

int main() {
    char s[10]; // Array to store characters
    for (int i = 0; i < 3; i++) {
        scanf(" %x", &s[i]); // Read one character at a time
    }
    s[3] = '\0'; // Null-terminate the string
    printf("%s", s); // Print the string
    return 0;
}

