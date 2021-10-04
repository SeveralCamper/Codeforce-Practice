#include <stdio.h>

int main () {
    int A, B, C;    
    char c1, c2;
    if((scanf("%d%c%d%c%d%c", &A, &c1, &B, &c1, &C, &c2) == 6) && (c1 == ' ') && (c2 == '\n')) {
        (A < C && C < B) ? printf("YES") : printf("NO");
    } else {
        printf("n/a");
    }
    return 0;
}