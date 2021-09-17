#include <stdio.h>

long sum(int firstDigit, int secondDigit);
long diff(int firstDigit, int secondDigit);
long mult(int firstDigit, int secondDigit);
long div(int firstDigit, int secondDigit);

int main()
{
    int firstDigit, secondDigit;
    char c;
    if ((scanf("%d%c", &firstDigit, &c) == 2) && (c == '\n')) {
        char c2;
        if ((scanf("%d%c", &secondDigit, &c2) == 2) && (c2 == '\n')) {
            if((firstDigit <= 2147483647 && firstDigit >= -2147483647) && (secondDigit <= 2147483647 && secondDigit >= -2147483647)) {
                if (secondDigit != 0) {
                sum(firstDigit,secondDigit);
                diff(firstDigit,secondDigit);
                mult(firstDigit,secondDigit);
                div(firstDigit,secondDigit);
                }  
                else {
                    sum(firstDigit,secondDigit);
                    diff(firstDigit,secondDigit);
                    mult(firstDigit,secondDigit);
                    printf("\nВторая введенная цифра: 0\n");
                    printf("n/a");
                } 
            }
            else printf("n/a");
        }
        else printf("n/a");
    }
    else printf("n/a");
    return 0;
}

long sum(int firstDigit, int secondDigit){
    long result = (long) firstDigit + (long) secondDigit;
    printf("%ld ",result);
    return (firstDigit + secondDigit);
}

long diff(int firstDigit, int secondDigit){
    long result = (long) firstDigit - (long) secondDigit;
    printf("%ld ",result);
    return (firstDigit - secondDigit);
}  

long mult(int firstDigit, int secondDigit){
    long result = (long) firstDigit * (long) secondDigit;
    printf("%ld ",result);
    return (firstDigit * secondDigit);
}

long div(int firstDigit, int secondDigit){
    long result = (long )firstDigit / (long) secondDigit;
    printf("%ld",result);
    return (firstDigit / secondDigit);
}