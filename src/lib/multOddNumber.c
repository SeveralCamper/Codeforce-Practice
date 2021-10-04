#include <stdio.h>
#include <stdlib.h>

int main () {
    int num, mult = 1;
    char c;
    if ((scanf("%d%c", &num, &c) == 2) && (c == '\n')) {
        while (num / 10 != 0) {
            int numTmp = num % 10;
            if (numTmp % 2 != 0) {
                mult *= numTmp;
            }
            num = num / 10;
        }
        printf("%d", mult);
    } else {
        printf("n/a");
    }
}