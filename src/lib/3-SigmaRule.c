#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NMAX 30

int input(int *data, int *arrayLength);
int searchCheck(int *data, int *arrayLength);

double mean(int *data, int *arrayLength);
double variance(int *data, int *arrayLength);

int main() {
    int arrayLength, data[NMAX];
    if (input(data, &arrayLength) == 1) {
        if (searchCheck(data, &arrayLength) == 1) {
        } else {
            printf("0");
        }
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
           if ((scanf("%d%c", pArray, &c) == 2) &&  ((c == ' ' &&
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

int searchCheck(int *data, int *arrayLength) {
    for (int *pArray = data; pArray - data < *arrayLength; pArray++) {
        int varianceMean = variance(data, arrayLength);
        if ((*pArray != 0) && (*pArray % 2 == 0)
        && (*pArray >= (mean(data, arrayLength))
        && (*pArray <= (mean(data, arrayLength)) +
        3 * sqrt(varianceMean)))) {
        printf("%d", *pArray);
        return 1;
            }
        }
    return 0;
}
