#include <stdio.h>
#include <stdlib.h>

char *readline() {
    char *line = NULL;
    size_t len = 0;
    size_t read;

    printf("Enter a line: ");
    read = getline(&line, &len, stdin);  // Dynamically allocates memory
    if (read == -1) {
        free(line);
        return NULL;
    }
    return line;
}

int main() {
    char *line = readline();
    if (line) {
        printf("You entered: %s", line);
        free(line);  // Free the allocated memory
    printf("You entered: %s", line);
    }
    return 0;
}