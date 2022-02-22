#include <stdlib.h>
#include <stdio.h>
 
int main() {
    int a, b, c, m = 1000, count, err_point = 0;
    int * array = NULL;
    char c1, c2, c3;
 
    if ((scanf("%d%c", &count, &c1) == 2) && (c1 == '\n') && (1 <= count <= 720)) {
        for (int i = 0; i < count * 3; i++) {
            array = realloc(array, (i + 1) * sizeof(int));       
        }
    } else {
        printf("EROOR!");
        err_point = 1;
    }
 
    if (!err_point) {
        int point = 0;
        for (int i = 0; i < count; i++) {
            if ((scanf("%d%c%d%c%d%c", &a, &c1, &b, &c2, &c, &c3) == 6) &&
                (c1 == ' ') && (c2 == ' ') && (c3 == '\n')) {
                    array[point] = a;
                    array[point + 1] = b;
                    array[point + 2] = c;
                    point += 3;
                } else {
                    printf("EROOR!");
                    err_point = 1;
                    break;
                } 
            }       
    }
 
    if (!err_point) {
        int point = 0;
 
        for (int i = 0; i < count; i++) {
            int difference_a = 0, difference_b = 0, difference_c = 0;

            difference_a = array[point + 1] - (array[point + 2] - array[point + 1]);
            if(difference_a >= array[point] && difference_a % array[point] == 0 && difference_a != 0) {
                printf("YES\n");
                point += 3;
                continue;
            }

            difference_b = array[point] + (array[point + 2] - array[point])/2;
            if(difference_b >= array[point + 1] && (array[point + 2]-array[point])%2 == 0 && difference_b % array[point + 1] == 0 && difference_b != 0) {
                printf("YES\n");
                point += 3;
                continue;
            }

            difference_c = array[point] + 2*(array[point + 1] - array[point]);
            if(difference_c >= array[point + 2] && difference_c % array[point + 2] == 0 && difference_c != 0) {
                printf("YES\n");
                point += 3;
                continue;
            }

            printf("NO\n");  
            point += 3;         
        }         
    }
 
    free(array);           
 
    return 0;
}
