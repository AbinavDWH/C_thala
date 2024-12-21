
    #include <stdio.h>

    int main() {
        __int128_t very_large_number = (__int128_t)1 << 100; // Example: 2 raised to the power of 100
        printf("The very large number is (approximately): %llu\n", (unsigned long long)(very_large_number >> 64)); // Print only upper 64 bits
        printf("%d\n", (unsigned long long)( 0x4C652066));
         // Print lower 64 bits
        return 0;
    }
