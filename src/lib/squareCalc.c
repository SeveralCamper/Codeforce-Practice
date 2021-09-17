#include <stdio.h>

struct Abstract {
    int widht, height;
};

void calc(struct Abstract obj);

int main(){
    struct Abstract rectangle = {5,7};
    calc (rectangle);
    struct Abstract square = {6,6};
    calc (square);
    return 0;
}

void calc(struct Abstract obj){
    int res = obj.widht * obj.height;
    printf ("Результат: %d\n", res);
}

