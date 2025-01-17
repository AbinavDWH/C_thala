#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert hours to minutes
int h2m(int h) {
    return h * 60;
}

int main() {
    char *input = NULL;
    size_t len = 0;
    int count = 0;

    // Read input line
    if (getline(&input, &len, stdin) == -1) {
        perror("Error reading input");
        free(input);
        return 1;
    }

    // Tokenize the input string by spaces
    char *token = strtok(input, " ");
    while (token != NULL) {
        int total_time = 0;

        // Parse the time string (expected format: "HH:MM")
        char *colon = strchr(token, ':'); // Find the colon in the token
        if (colon != NULL) {
            // Extract hours and minutes
            int hours = atoi(token);
            int minutes = atoi(colon + 1);

            // Calculate total time in minutes
            total_time = h2m(hours) + minutes;
        }

        // Check if total time exceeds 600 minutes
        if (total_time > 600) {
            count++;
        }

        // Move to the next token
        token = strtok(NULL, " ");
    }

    // Print the count
    printf("%d\n", count);

    // Free allocated memory
    free(input);

    return 0;
}