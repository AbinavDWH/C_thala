#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1001

int main() {
    int n, x1, x2, y1, y2, t;
    long long total = 0;
    int arr[MAX_SIZE][MAX_SIZE] = {{0}};

    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Error reading input\n");
        return EXIT_FAILURE;
    }

    while (n--) {
        if (scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &t) != 5) {
            fprintf(stderr, "Error reading input\n");
            return EXIT_FAILURE;
        }

        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                if (arr[i][j] == 0) {
                    arr[i][j] += t;
                } else if (arr[i][j] > 0) {
                    arr[i][j] = -1 * (arr[i][j] + t);
                } else if (arr[i][j] < 0) {
                    arr[i][j] -= t;
                }
            }
        }
    }

    for (int i = 1; i < MAX_SIZE; i++) {
        for (int j = 1; j < MAX_SIZE; j++) {
            if (arr[i][j] < 0) {
                total += arr[i][j];
            }
        }
    }

    printf("%lld\n", -1 * total);
    return EXIT_SUCCESS;
}