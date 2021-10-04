#include <stdio.h>
#define RADIANS 57.29

int main() {
    double degrees;
    char c;
    if ((scanf("%lf%c", &degrees, &c) == 2) && (c == '\n')) {
        degrees *= RADIANS;
        printf("%.0lf", degrees);
    } else {
        printf("n/a");
    }
}
