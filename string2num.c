#include <stdio.h>

int string_to_int(char* str) {
    int num = 0;
    int sign = 1;
    if (*str == '-') {
        sign = -1;
        str++;
    }
    while (*str != '\0') {
        num = num * 10 + (*str - '0');
        str++;
    }
    return num * sign;
}

int main() {
    char str[] = "8";
    int num = string_to_int(str);
    printf("Number: %d\n", num);
    return 0;
}