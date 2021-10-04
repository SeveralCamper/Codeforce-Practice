#include <stdio.h>
#include <stdlib.h>

void outPutArray(int *a, int arrayLength);
void arrayWithoutDouble(int *array, int *tmpArray, int arrayLength, int *tmpArrayLength);

int main() {
    int *array = NULL, addNum = 0, i = 1;
    char c;
    while (addNum != -1) {
        if ((scanf("%d%c", &addNum, &c) == 2) && ((c == ' ') || (c == '\n'))) {
            if (addNum == -1) {
                break;
            } else if (addNum < -1) {
                printf("n/a");
                exit(1);
            } else {
                array = realloc(array, (i + 1) * sizeof(int));
                array[i] = addNum;
                i++;
            }
        } else {
            printf("n/a");
            free(array);
            exit(1);
        }
    }

    for(int j = 1; j < i - 1; j++) {
        for (int k = j + 1; k < i; k++) {
            if (array[j] == array[k])  {
                array[k] = -1;
            }
        }
    }

    outPutArray(array, i);

    free(array);
}

void outPutArray(int *array, int arrayLength) {
    for (int j = 1; j < arrayLength; j++) {
        if (array[j] != -1) {
            if (j == 1) {
                printf ("%d", array[j]);
            } else {
                printf(" %d", array[j]);
            }
        }
    }
}
