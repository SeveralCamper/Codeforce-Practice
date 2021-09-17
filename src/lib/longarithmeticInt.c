#include <stdio.h>

#define LEN 100


int inputBig(int *a, int *n);
void outputRev(int *a, int n);
void reverseArray(int *data, int n);
void zeroer(int *data, int n);
int sum(const int *buff1, int len1, const int *buff2, int len2, int *result, int *result_length);
int sub(const int *buff1, int len1, const int *buff2, int len2, int *result, int *result_length);

int main() {
    int number1[LEN], n1, number2[LEN], n2;
    int err = 0;

    err += inputBig(number1, &n1);
    err += inputBig(number2, &n2);

    reverseArray(number1, n1);
    reverseArray(number2, n2);

    if (err == 0) {
        int res[LEN+1], resn;
        sum(number1, n1, number2, n2, res, &resn);
        outputRev(res, resn);
        zeroer(res, resn);
        printf("\n");
        if (sub(number1, n1, number2, n2, res, &resn) == 0)
            outputRev(res, resn);
        else
            printf("n/a");
    } else {
        printf("n/a");
    }
    return 0;
}

int inputBig(int *a, int *n) {
    char nl = 'a';
    int i = 0;

    while (nl != '\n') {
        if (i == LEN)
            return 1;
        if (scanf("%d%c", &a[i], &nl) != 2)
            return 1;
        if (a[i] < 0 || a[i] > 9)
            return 1;
        i++;
    }
    *n = i;

    return 0;
}

void outputRev(int *a, int n) {
    int i = n-1;
    while (a[i] == 0)
        i--;
    for (; i > 0; i--)
        printf("%d ", a[i]);
    printf("%d", a[0]);
}

void reverseArray(int *data, int n) {
    int array[LEN];
    for (int i=0; i < n; i++)
        array[n-1-i] = data[i];
    for (int i=0; i < n; i++)
        data[i] = array[i];
}


int sum(const int *buff1, int len1, const int *buff2, int len2, int *result, int *result_length) {
    int i, a, b, err = 0;
    int largest_length = (len1 > len2 ? len1 : len2);
    *result_length = largest_length + 1;

    result[0] = 0;

    for (i = 0; i < largest_length; i++) {
        if (i < len1)
            a = buff1[i];
        else
            a = 0;
        if (i < len2)
            b = buff2[i];
        else
            b = 0;

        result[i] += (a + b)%10;
        result[i+1] = (a + b)/10;
    }
    if (result[i] != 0)
        err = 1;
    return err;
}

int sub(const int *buff1, int len1, const int *buff2, int len2, int *result, int *result_length) {
    int err = 0;
    int i, a, b;
    int largest_length = (len1 > len2 ? len1 : len2);
    *result_length = largest_length + 1;

    result[0] = 0;

    for (i = 0; i < largest_length; i++) {
        if (i < len1)
            a = buff1[i];
        else
            a = 0;
        if (i < len2)
            b = buff2[i];
        else
            b = 0;

        if (a - b < 0) {
            result[i] = result[i] + a - b + 10;
            result[i+1]--;
        } else {
            result[i] += a - b;
        }
    }
    for (i = 0; i < *result_length; i++)
        if (result[i] < 0)
            err = 1;
    return err;
}

void zeroer(int *data, int n) {
    for (int i=0; i < n; i++)
        data[i] = 0;
}
