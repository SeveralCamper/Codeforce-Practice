#include <stdio.h>
#include <stdlib.h>

// Удаление из строки последнего вхождения подстроки
// совподающего с substr. Входная строка str и подстрока substr
// задаются последовательно и заканчиваются символом \n,
// результирующую строку вывести на стандартный поток вывода.
// Ввод                     |      Вывод
// This is my test \n  my   |  This is test
// one two onethree \n one  |  one two three

char inputStr(char **string, int *strLen);
int foundLastOcc(char *string, char *subString, int strLen, int subStrLen);
int outPut(char *string, int strLen);

int main() {
    char *string = NULL, *subString = NULL;
    int strLen = 0, subStrLen = 0;
    inputStr(&string, &strLen);
    fflush(NULL);
    inputStr(&subString, &subStrLen);

    outPut(string, strLen);
    outPut(subString, subStrLen);
    printf("%d", foundLastOcc(string, subString, strLen, subStrLen));
}

char inputStr(char **string, int *strLen) {
    *string = malloc(sizeof(char));
    int i = 0;
    char addSymbol;
    while (addSymbol != '\n') {
        scanf("%c", &addSymbol);
        *string = realloc(*string, (i + 1) * sizeof(char));
        *(*string + i) = addSymbol;
        i++;
    }
    *strLen = i;
    return *strLen;
}

int outPut(char *string, int strLen) {
    for (int i = 0; i < strLen; i++) {
        printf("%c", string[i]);
    }
    return strLen;
}

int foundLastOcc(char *string, char *subString, int strLen, int subStrLen) {
    int lastI;
    for (int i = 0; i < strLen; i++) {
        printf("%d", subStrLen);
        if (string[i] == subString[0] && subStrLen == 2) {
            lastI = i;
        } else if (string[i] == subString[0] && subStrLen > 1) {
            for (int j = 0; j < subStrLen; j++) {
                printf("\n%d     %d\n", string[i + j], subString[j]);
                if (subString[j + i] != string[i + j + 1]) {
                    lastI = 0;
                    break;
                } else {
                    lastI = i;
                }
            }
        }
    }
    return lastI;
}
