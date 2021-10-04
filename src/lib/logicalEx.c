#include <stdio.h>

int main() {
    int A, B, C;
    char c1, c2;
    if ((scanf("%d%c%d%c%d%c", &A, &c1, &B, &c2, &C, &c2) == 6) && (c1 == ' ') && (c2 == '\n')) {
        if (((A == 0) || (A == 1)) && ((B == 0)
        || (B == 1)) && ((C == 0) || (C == 1))) {
            if ((A && (B || C)) == 1) {
                printf("1");
            } else {
                printf("0");
            }
        } else {
            printf("n/a");
        }
    } else {
        printf("n/a");
    }
}
