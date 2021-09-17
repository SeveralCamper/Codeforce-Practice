#include <stdio.h>
#include <stdlib.h>

long Fact(int n);

int main() {
    int intPart;
    char charPart;
if (scanf("%d%c", &intPart, &charPart) == 2 && charPart == '\n') {
    for (int k = 0; k <= intPart; k++) {
        int res;
        res = (Fact(intPart))/(Fact(k)*Fact(intPart-k));
        printf("%d", res);
        if (k <= intPart - 1) {
            printf(" ");
        }
    }    
} else {
    printf("%s", "n/a");
}

return 0;
}

long Fact(int n) {
    long res = 1;

    for (int i = n; i > 1; i--) {
        res = res * i;
    }
    return res;
}
