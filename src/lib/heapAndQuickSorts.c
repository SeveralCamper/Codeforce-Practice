#include <stdio.h>
#define NMAX 10

int input(int *data, int *arrayLength);
int copyArray(int* data, int arrayLength, int* numbers);

void output(int *data, int *arrayLength);
void quickSort(int *data, int *first, int *last);
void heapify(int *data, int root, int bottom);
void heapSort(int *data, int arrayLength);
void swap(int *first, int *second);
void calculations();

int main() {
    calculations();
    return 0;
}

int input(int *data, int *arrayLength) {
    char c;
    for (int *pArray = data; pArray - data < *arrayLength; pArray++) {
        if ((scanf("%d%c", pArray, &c) == 2) &&  ((c == ' ' &&
           pArray - data < *arrayLength - 1) || c == '\n')) {
        } else {
            return 0;
        }
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

void quickSort(int *data, int *first, int *last) {
    if (*first < *last) {
        int left = *first, right = *last, middle = data[(left + right) / 2];
        do {
            while (data[left] < middle)
                left++;
            while (data[right] > middle)
                right--;
            if (left <= right) {
                swap(data + left, data + right);
                left++;
                right--;
            }
        } while (left <= right);
        quickSort(data, first, &right);
        quickSort(data, &left, last);
    }
}

void heapify(int *data, int root, int bottom) {
    int maxChild = 0;
    int heapifyCompletFlag = 0;

    while ((root * 2 <= bottom) && (!heapifyCompletFlag)) {
        if (root * 2 == bottom) {
            maxChild = root * 2;
        } else if (data[root * 2] > data[root * 2 + 1]) {
            maxChild = root * 2;
        } else {
            maxChild = root * 2 + 1;
        }

        if (data[root] < data[maxChild]) {
            int tmp = data[root];
            data[root] = data[maxChild];
            data[maxChild] = tmp;
            root = maxChild;
        } else {
            heapifyCompletFlag = 1;
        }
    }
}

void heapSort(int *data, int arrayLength) {
    for (int i = arrayLength/2; i >= 0; i--) {
        heapify(data, i, arrayLength - 1);
    }
    for (int i = arrayLength - 1; i >= 1; i--) {
        int tmp = data[0];
        data[0] = data[i];
        data[i] = tmp;
        heapify(data, 0, i-1);
    }
}

void swap(int *first, int *second) {
    int tmp = *first;
    *first = *second;
    *second = tmp;
}

int copyArray(int* data, int arrayLength, int* numbers) {
    int x = 0;
    int n = 0;
    while (x < arrayLength) {
        *(numbers + n) = *(data + x);
        n += 1;
        x += 1;
    }
    return n;
}

void calculations() {
    int first, last;
    int arrayLength = 10, data[NMAX];
    int dataCopy[NMAX];
    first = 0;
    last = 9;
    if (input(data, &arrayLength) == 1) {
        copyArray(data, arrayLength, dataCopy);
        quickSort(data, &first, &last);
        output(data, &arrayLength);
        printf("\n");
        heapSort(dataCopy, arrayLength);
        output(dataCopy, &arrayLength);
    } else {
        printf("n/a");
    }
}
