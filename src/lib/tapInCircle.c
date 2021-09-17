#include <stdio.h>

double powFunc(double digit);
double shotOnSircle(double firstDigit, double secondDigit);

int main()
{
    double firstDigit;
    double secondDigit;
    char c;
    if ((scanf("%lf%c", &firstDigit, &c) == 2) && (c == '\n')) {
        char c2;
        if ((scanf("%lf%c", &secondDigit, &c2) == 2) && (c2 == '\n')) {
            shotOnSircle(firstDigit, secondDigit);
        }
        else printf("n/a");
    }
    else printf("n/a");
    return 0;
}

double powFunc(double digit) {
        digit = digit * digit;
    return (digit);
}

double shotOnSircle(double firstDigit, double secondDigit){
    if (((powFunc(firstDigit) + powFunc(secondDigit)) <= 5)) {
        printf ("GOTCHA");
    }
    else printf ("MISS");
   return (1);
}
