#include <stdio.h>

int divisibilityCheck(int digit, int diviver);

int naturalNumberCheck(int diviver);

int start(int digit, int diviver, int max);

int main() {
    int digit;
    char c;
    if ((scanf("%d%c", &digit, &c) == 2) && (c == '\n')) {
        if (digit <= 2147483647 && digit >= -2147483647) {
            int diviver = 1, max = 1;
            start(digit, diviver, max);
        } else {
            printf("n/a\n");
        }
    } else {    
        printf("n/a\n");
    }
}


int divisibilityCheck(int digit, int diviver) {
    while (digit > 0) {
        digit -= diviver;
    }
    if (digit == 0) {
        return 1;
    } else {
        return 0;
        }
}

int naturalNumberCheck(int diviver) {
    if (diviver == 0) {
        return 0;
    }
    if (diviver == 1 || diviver == 2) {
        return 1;
    }
    int diviver2 = 3;
    while (diviver2 < diviver) {
        if (divisibilityCheck(diviver, diviver2) == 1) {
            break;
        }
        diviver2 += 2;
    }
    if (diviver2 == diviver) {
        return 1;
    }
    return 0;
}

int start(int digit, int diviver, int max) {
    if ((digit == 0) || (digit == 1) || (digit == -1)) {
        printf("n/a\n");
    } else {
        if (digit < 0) {
            digit *= -1;
        }
        while (diviver < digit) {
            if ((divisibilityCheck(digit, diviver) == 1) && (naturalNumberCheck(diviver) == 1)) {
                max = diviver;
            }
                diviver += 1;
        }
        if (max == 1) {
            printf("%d\n", digit);
        } else {
            printf("%d\n", max);
        }
    }
    return 0;
}
