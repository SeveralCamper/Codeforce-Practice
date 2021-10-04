#include <stdio.h>
#include <stdlib.h>

int main () {
    int *a = NULL, i = 0, tmpAdd = 0, min = 0, max = 0, maxJ = 0, minJ = 0;
    char c;   
    while (tmpAdd != -1) {
        if ((scanf("%d%c", &tmpAdd, &c) == 2) && ((c == '\n') || (c == ' '))) {
            if (tmpAdd == -1) {
                break;
            } else if (tmpAdd < -1) {
                printf("n/a");
                free(a);
                exit(1);
            }else {
                a = (int*)realloc(a, (i + 1) * sizeof(int));
                a[i] = tmpAdd;
                i++;
            }
        } else {
        printf("n/a");
        free(a);
        exit(1);
        }
    }

    for (int j = 0; j < i; j++) {
            if (j + 1 == i) {
                printf("%d", a[j]);
            } else {
            printf("%d ", a[j]);
            }
        }

    printf("\n\n");

    if (i == 0) {
        free(a);
        exit(1);
    } else {
        for (int j = 0; j < i; j++) {
        if (j == 0) {
            min = a[j];
            max = a[j];
        }
        if (a[j] < min) {
            min = a[j];
            minJ = j;
            }   

        if (a[j] > max) {
            max = a[j];
            maxJ = j;
            }
        }


        int tmp = a[maxJ];
        a[maxJ] = a[minJ];
        a[minJ] = tmp; 

        for (int j = 0; j < i; j++) {
            if (j + 1 == i) {
                printf("%d", a[j]);
            } else {
                printf("%d ", a[j]);
            }
        }

        free(a);

    }

}
