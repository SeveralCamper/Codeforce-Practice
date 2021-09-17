#include <stdio.h>
#include <stdlib.h>

int Fact(int n);
int* initAndFillArr(int* arr,int arrSize);
void printArray(int *arr,int arrSize);

int main() {
    int intPart;
    char charPart;
if (scanf("%d%c", &intPart, &charPart) == 2 && charPart == '\n') {
    int* arr = initAndFillArr(arr, intPart);
    if (arr != NULL){
        printArray(arr, intPart + 1);
    free (arr);
    } else {
        printf("%s", "n/a");
    }
} else {
    printf("%s", "n/a");
}

return 0;
}

int Fact(int n) {
    int res = 1;

    for (int i = n; i > 1; i--) {
        res = res * i;
    }
    return res;
}

int* initAndFillArr(int* arr,int arrSize) {
    int k = 0;
    arr = (int*) malloc ((arrSize + 1) * sizeof(int));
    if (arr != NULL){
        for (int* arrPtr = arr; arrPtr - arr < (arrSize + 1); arrPtr++) { 
        *arrPtr = (Fact(arrSize))/(Fact(k)*Fact(arrSize-k));
        k++;
        }   
    } else {
            free (arr);
    }
    return arr;
}

void printArray(int *arr, int arrSize) {
    for (int* arrPtr = arr; arrPtr - arr < arrSize; arrPtr++) { 
        printf("%d", *arrPtr);
        int k = arrPtr - arr;
        if (k <= arrSize - 2) {
        printf(" ");
        }
    } 
}
