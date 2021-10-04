#include <stdio.h>

int main () {
    int digit;
    char c;
    if ((scanf("%d%c", &digit, &c) == 2) && (c == '\n')) {
        printf("%d", digit % 10 * 100 + (digit % 100) - (digit%100)%10 + digit / 100);
    } else {
        printf("n/a");
    }
    return 0;
}
