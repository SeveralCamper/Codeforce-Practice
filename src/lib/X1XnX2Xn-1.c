#include <stdio.h>
#include <stdlib.h>

void output(int* data, int arrayLength);

int main() {
    int *array = malloc (sizeof(int)), addNum, i;
    char c;
    while(addNum != -1) {
        if((scanf("%d%c", &addNum, &c) == 2) && ((c == ' ') || (c == '\n'))) {
            if (addNum == -1) {
            break;
            }
            if (addNum < -1) {
                printf("n/a");
                exit(1);
            } else {
                array = realloc(array, (i + 1) * sizeof(int));
                array[i] = addNum;
                i++;
            }
        } else {
            printf("n/a");
            exit(1);
        }
    }
    printf("\n");
    output(array, i);
}

void output(int* data, int arrayLength) {
 for (int i = 0; i < arrayLength / 2; i++) {
 	printf("%d %d ", data[i], data[arrayLength - i - 1]);
 }
 if (arrayLength % 2) {
 	printf("%d", data[arrayLength / 2]);
    }
    if (arrayLength % 2 == 0) {
 	printf("\b");
    }
}