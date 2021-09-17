#include <stdio.h>
#define NMAX 10

int input(int *data, int *arrayLength);
void output(int *data, int *arrayLength);
void squaring(int *data, int *arrayLength);

int main() {
    int arrayLength, data[NMAX];
    if (input(data, &arrayLength) == 1) {
        squaring(data, &arrayLength);
        output(data, &arrayLength);
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *data, int *arrayLength) {
    char c;
    if ((scanf("%d%c", arrayLength, &c) == 2) && (c == '\n') &&
        (*arrayLength > 0) && (*arrayLength <= NMAX)) {
        for (int *pArray = data; pArray - data < *arrayLength; pArray++) {
           if ((scanf("%d%c", pArray, &c) == 2) && ((c == ' ' &&
           pArray - data < *arrayLength - 1) || c == '\n')) {
           } else {
                return 0;
           }
        }
    } else {
        return 0;
    }
    return 1;
}

void output(int *data, int *arrayLength) {
    for (int *pArray = data; pArray - data < *arrayLength; pArray++) {
            printf("%d", *pArray);
            if (data - pArray + *arrayLength > 1) {
                printf("%c", ' ');
            }
        }
}

void squaring(int *data, int *arrayLength) {
    for (int *pArray = data; pArray - data < *arrayLength; pArray++) {
            *pArray = (*pArray) * (*pArray);
        }
}
