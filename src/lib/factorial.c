#include <stdlib.h>
#include <stdio.h>

long Fact(int n);

int main() {
    printf ("%ld", Fact(13));
    return 1;
}

long Fact(int n) {
    long res = 1;

    for (int i = n; i > 1; i--) {
        res = res * i;
    }
    return res;
}