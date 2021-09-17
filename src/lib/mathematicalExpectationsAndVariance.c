#include <stdio.h>
#define NMAX 10

int input(int *data, int *arrayLength);
int max(int *data, int *arrayLength);
int min(int *data, int *arrayLength);

double mean(int *data, int *arrayLength);
double variance(int *data, int *arrayLength);

void output(int *data, int *arrayLength);
void output_result(int *data, int *arrayLength);

int main() {
    int arrayLength, data[NMAX];
    if (input(data, &arrayLength) == 1) {
        output(data, &arrayLength);
        output_result(data, &arrayLength);
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

int max(int *data, int *arrayLength) {
    int maxV = -2147483648;
    for (int *pArray = data; pArray - data < *arrayLength; pArray++) {
        if (*pArray > maxV) {
            maxV = *pArray;
        }
    }
    return (maxV);
}

int min(int *data, int *arrayLength) {
    int minV = 2147483647;
    for (int *pArray = data; pArray - data < *arrayLength; pArray++) {
        if (*pArray < minV) {
            minV = *pArray;
        }
    }
    return (minV);
}

double mean(int *data, int *arrayLength) {
    double meanRes = 0;
    for (int *pArray = data; pArray - data < *arrayLength; pArray++) {
        meanRes += *pArray;
    }
    meanRes = meanRes/  *arrayLength;
    return (meanRes);
}

double variance(int *data, int *arrayLength) {
    double varianceRes = 0;
    double endRes = 0;
    for (int *pArray = data; pArray - data < *arrayLength; pArray++) {
        varianceRes += *pArray * *pArray;
    }
    varianceRes = varianceRes/  *arrayLength;
    endRes = varianceRes - (mean(data, arrayLength) * mean(data, arrayLength));
    return (endRes);
}

void output_result(int *data, int *arrayLength) {
    printf("\n%d %d %f %f", max(data, arrayLength), min(data, arrayLength),
    mean(data, arrayLength), variance(data, arrayLength));
    }

