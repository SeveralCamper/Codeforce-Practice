#include <stdio.h>

int main () {
    int max, tmpAdd, i = 0;
    char c;
    while((scanf("%d%c", &tmpAdd, &c) == 2) && ((c == ' ') || (c == '\n')) && (tmpAdd > -1)) {
        if (i == 0) {
            max = tmpAdd;
        }
        if (tmpAdd > max) {
            max = tmpAdd;
        }
        i++;
    }

    if(tmpAdd < -1) {
        printf ("n/a");
    } else {
        printf("%d", max);
    }
}