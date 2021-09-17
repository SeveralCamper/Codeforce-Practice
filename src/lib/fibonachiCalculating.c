#include <stdio.h>

int fibonachi(int digit);

int main() {
    int digit;
    char c;
    if ((scanf("%d%c", &digit, &c) == 2) && (c == '\n')) {
        if (digit <= 2147483647 && digit >= 0) {
            printf("%d", fibonachi(digit));
        } else {
            printf("n/a\n");
        }
    } else {
        printf("n/a\n");
    }
    return 0;
}

int fibonachi(int digit) {
    if (digit == 0) {
        return 0;
    }

    if (digit == 1) {
        return 1;
    }

    if (digit == 2) {
        return 1;
    }

    return (fibonachi(digit-1) + fibonachi(digit-2));
}
