#include <stdio.h>
#define M 2
#define N 3
 
int main(){
  int sizeH, sizeW;
    scanf("%d%d", &sizeH, &sizeW);

    int firstMatrix[sizeH][sizeW];
    int tmpMatrix[sizeW][sizeH];
    int count = 1;

    for (int i = 0; i < sizeH; i++) {
        for (int j = 0; j < sizeW; j++) {
            firstMatrix[i][j] = count;
            if (j == 0){
                printf("%d", firstMatrix[i][j]);
            } else {
                printf(" %d", firstMatrix[i][j]);
            }
            count++;
        }
        printf("\n");
    }

    printf("\n");

    int i,j;
    for(i=0; i<sizeH; i++)
        for(j=0; j<sizeW; j++)
        tmpMatrix[i][j] = firstMatrix[j][N-i-1];
    for(j=0; j<sizeH; j++){
        for(i=0;i<sizeW; i++)printf("%i\t", firstMatrix[i][j]);
        printf("\n");
    }
    printf("-------------\n");
    for(j=0; j<M; j++){
        for(i=0;i<N; i++)printf("%i\t", tmpMatrix[i][j]);
        printf("\n");
    }
}

/*int main() {
    int sizeH, sizeW;
    scanf("%d%d", &sizeH, &sizeW);

    int firstMatrix[sizeH][sizeW];
    int tmpMatrix[sizeW][sizeH];
    int count = 1;

    for (int i = 0; i < sizeH; i++) {
        for (int j = 0; j < sizeW; j++) {
            firstMatrix[i][j] = count;
            if (j == 0){
                printf("%d", firstMatrix[i][j]);
            } else {
                printf(" %d", firstMatrix[i][j]);
            }
            count++;
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < sizeH; i++) {
        for (int j = 0; j < sizeW; j++) {
            firstMatrix[i][j] = count;
            tmpMatrix[i][j] = firstMatrix[i][sizeH - i - 1];
        }
    }

    printf("\n");

    for (int i = 0; i < sizeW; i++) {
        for (int j = 0; j < sizeH; j++) {
            if (j == 0){
                printf("%d", tmpMatrix[i][j]);
            } else {
                printf(" %d", tmpMatrix[i][j]);
            }
        }
        printf("\n");
    }
}*/
