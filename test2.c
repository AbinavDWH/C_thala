#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* strtrim(char *str) {
    // Trim leading whitespace
    while (isspace((unsigned char)*str)) str++;

    // Trim trailing whitespace
    char *end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    // Null terminate the trimmed string
    *(end + 1) = '\0';

    return str;
}
int main(){
    char str[] = "  Hello, World!  ";
    strtrim(str);
    printf("%s\n", str);
    
}