#include <stdio.h>

char *my_strset(char* str, int ch) {
    char *ptr = str;int i=0;
    while (*ptr) {
        *ptr = ch;
        ptr++;
    }
    printf("%s",ptr-14);
    
    return str;
}

int main() {
    char str[] = "Hello, World!";
    printf("Original string: %s\n", str);
    char *p=str;
printf("%s",str+2);
    // Use my_strset to set all characters to 'x'
    my_strset(str, 'x');
    printf("Modified string: %s\n", str);

    return 0;}