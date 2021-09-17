#include <stdio.h>
#define NMAX 10

void input(int *data, int *arrayLength, int
*shift, int *he);
void output(int *data, int *arrayLength);
void cicleShift(int *data, int arrayLength, int shift);

int sum_numbers(int *buffer, int arrayLength);

int main() {
    int n = 0;
    int shift = 0;
    int arrayLength = 10, data[NMAX];
        input(data, &arrayLength, &shift, &n);
        if (n == 0) {
            cicleShift(data, arrayLength, shift);
            output(data, &arrayLength);
        } else {
            printf("n/a");
        }
    return 0;
}

void input(int *data, int *arrayLength, int
*shift, int *he) {
    char c;
    if ((scanf("%d%c", arrayLength, &c) == 2) && (c == '\n') &&
    (*arrayLength > 0) && (*arrayLength <= NMAX)) {
        for (int *pArray = data; pArray - data < *arrayLength; pArray++) {
            if ((scanf("%d%c", pArray, &c) == 2) && ((c == ' ' &&
            pArray - data < *arrayLength - 1) || c == '\n')) {
                } else {
                    *he += 1;
                    return;
                }
        }
        if ((scanf("%d%c", shift, &c) == 2) && (c == '\n')) {
            } else {
                *he += 1;
                return;
            }
        } else {
                *he += 1;
                return;
        }
    }

void output(int *data, int *arrayLength) {
    for (int *pArray = data; pArray - data < *arrayLength; pArray++) {
            printf("%d", *pArray);
            if (data - pArray + *arrayLength > 1) {
                printf("%c", ' ');
            }
        }
}

int find_numbers(int* data, int arrayLength, int number, int* numbers) {
    int x = 0;
    int n = 0;
    while (x < arrayLength) {
        if ((*(data + x) != 0) && (number % (*(data + x)) == 0)) {
            *(numbers + n) = *(data + x);
            n += 1;
        }
        x += 1;
    }
    return n;
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
