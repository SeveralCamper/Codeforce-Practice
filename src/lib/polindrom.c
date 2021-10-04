#include <stdio.h>
#include <stdlib.h>

char strRead(char **string, int *len);
int stringPolindrom(char *string, int len);

int main() {
    char *string = NULL;
    int len;
    strRead(&string, &len);
    printf("%s", string);
    if (stringPolindrom(string, len) == 1) {
        printf("\nYes");
    } else {
        printf("\nNo");
    }
    return 0;
}

char strRead(char **string, int *len) {
    int i = 0;
    char addSymbol = 1;
    *string = malloc(sizeof(char));
    while (addSymbol != '\n') {
        scanf("%c", &addSymbol);
        if (addSymbol == '\n') {
            break;
        } else if (addSymbol != ' ') {
            if (addSymbol >= 'A' && addSymbol <= 'Z') {
                addSymbol += 32;
            }
            *string = realloc(*string, (i + 1) * sizeof(char));
            *(*string + i) = addSymbol;
            i++;
        }
    }
    *len = i;
    return **string;
}

int stringPolindrom(char *string, int len) {
    int flag = 1;
    for (int i = 0; i < len / 2; i++) {
        if (string[i] != string[len - i - 1]) {
            flag = 0;
            break;
        }
    }
    return flag;
}
