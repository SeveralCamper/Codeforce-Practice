#include <stdio.h>

void maxmin(int prob1, int prob2, int prob3, int *max, int *min);

int main() {
    int x, y, z;
    char c, c2, c3;
    if ((scanf("%d%c%d%c%d%c", &x, &c, &y, &c2, &z, &c3) == 6) &&
    (c == ' ') && (c2 == ' ') && (c3 == '\n')) {
        if ((x >= -2147483647 && x <= 2147483647) &&
            (y >= -2147483647 && y <= 2147483647) &&
            (z >= -2147483647 && z <= 2147483647)) {
                int max, min;
                maxmin(x, y, z, &max, &min);

                printf("%d %d", max, min);
            } else {
                printf("n/a");
            }
    } else {
        printf("n/a");
    }
    return 0;
}

void maxmin(int prob1, int prob2, int prob3, int *max, int *min) {
        *max = *min = prob1;

    if (prob2 > *max)
        *max = prob2;
    if (prob2 < *min)
        *min = prob2;
    if (prob3 > *max)
        *max = prob3;
    if (prob3 < *min)
        *min = prob3;
}

