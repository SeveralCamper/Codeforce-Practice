#include <stdio.h>
#include <stdlib.h>

int inputArray(int *array, int arrayLength);

int main() {
    int *array = NULL, arrayLength, i = 0, addNum, max, min;
    char c;
    while(addNum != -1) {
        if ((scanf("%d%c", &addNum, &c) == 2) && ((c == ' ') || (c == '\n'))) {
            if (addNum == -1) {
                break;
            } else if (addNum < -1) {
                printf("n/a");
                exit(1);
            }  else {
                array = realloc(array, (i + 1) *  sizeof(int));
                array[i] = addNum;
                i++;
            }
        } else {
            printf("n/a");
            exit(1);
        }
    }

    if (i != 0) {
        for (int j = 0; j < i; j++) {
            if (j == 0) {
                max = min = array[j];
            } else if (array[j] > max) {
                max = array[j];
            } else if (array[j] < min) {
                min = array[j];
                }
            }
    printf("\n%d %d\n", min, max);

    int tmpMin, tmpMax, tmp;
    for (int j = 0; j < i; j++) {
        if (array[j] == max) {
            tmpMax = j;
            break;
        } 
    }

    for (int j = 0; j < i; j++) {
        if ( array[j] == min) {
            tmpMin = j;
            break;
        }
    }

    tmp = array[tmpMax];
    array[tmpMax] = array[tmpMin];
    array[tmpMin] = tmp;

    for (int j = 0; j < i; j++) {
        if (j == 0) {
            printf("%d", array[j]);
        } else {
            printf("% d", array[j]);
            }
        }
    }
}

