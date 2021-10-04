#include <stdio.h>
#include <stdlib.h>

void cicleShift(int *data, int arrayLength, int shift);
void outPutData(int *a, int arrayLength);
void fillData(int *a, int arrayLength);
void cyclic_roll(int *a, int *b, int *c, int *d);

int main () {
    int length = 0, hight;
    scanf("%d%d", &length, &hight);

    int **array;

    array = malloc(sizeof(*array) * length);
    for (int i = 0; i < length; i++) {
        array[i] = malloc(sizeof(**array) * hight);
    }

    for (int i = 0; i < hight; i++) {
        for (int j = 0; j < length; j++) {
            array[i][j] = (i+1) + (j+1);
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    for(int i=0; i<length/2; i++)
        for(int j=0; j<(length+1)/2; j++)
            cyclic_roll(&array[i][j], &array[length-1-j][i], &array[length-1-i][length-1-j], &array[j][length-1-i]);

    printf("\n");

    for (int i = 0; i < hight; i++) {
        for (int j = 0; j < length; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }        

    for (int i = 0; i < length; i++) {
        free (array[i]);
    }
    free (array);

    return 0;
}

void cicleShift(int *data, int arrayLength, int shift) {
    if (shift % arrayLength != 0) {
        if (shift < 0) {
            shift *= -1;
            for (int i = 0; i < shift; ++i) {
                int tmp = data[arrayLength-1];
                for (int j = arrayLength - 1; j > 0; j--) {
                    data[j] = data[j-1];
                }
                data[0] = tmp;
            }
        } else {
            for (int i = 0; i < shift; ++i) {
                int tmp = data[0];
                for (int j = 0; j < arrayLength - 1; j++) {
                    data[j] = data[j+1];
                }
                data[arrayLength-1] = tmp;
            }
        }
    } else {
        return;
    }
}

void fillData(int *a, int arrayLength) {
    for (int i = 0; i < arrayLength; i++) {
        a[i] = i + 1;
    }
}

void outPutData(int *a, int arrayLength) {
    for (int i = 0; i <arrayLength; i++) {
        if (i + 1 != arrayLength) {
            printf("%d ", a[i]);
        } else {
            printf("%d", a[i]);
        }
    }
}

void cyclic_roll(int *a, int *b, int *c, int *d) {
   int temp = *a;
   *a = *b;
   *b = *c;
   *c = *d;
   *d = temp;
}