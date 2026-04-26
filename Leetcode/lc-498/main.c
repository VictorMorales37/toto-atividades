#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* findDiagonalOrder( int** mat, int matSize, int* matColSize, int* returnSize ) {

    int* result = malloc( sizeof(int) * (matSize * *matColSize) );
    *returnSize = matSize * *matColSize;

    int index = 0;
    int lines = 0;
    int cols = 0;
    bool up = true;

    while ( index < *returnSize ) {

        result[index++] = mat[lines][cols];

        if ( up ) {

            if ( cols == *matColSize-1 ) {
                up = false;
                lines++;
            } else if ( lines == 0 ) {
                up = false;
                cols++;
            } else {
                lines--;
                cols++;
            }

        } else {
            if ( lines == matSize-1 ) {
                up = true;
                cols++;
            } else if ( cols == 0 ) {
                up = true;
                lines++;
            } else {
                lines++;
                cols--;
            }
        }
    }
    return result;
}

int main() {
    
    int matSize = 3;
    int matColSizeVal = 3;
    int* matColSize = &matColSizeVal;

    int** mat = (int**)malloc(sizeof(int*) * matSize);
    for (int i = 0; i < matSize; i++) {
        mat[i] = (int*)malloc(sizeof(int) * matColSizeVal);
    }

    int value = 1;
    for (int i = 0; i < matSize; i++) {
        for (int j = 0; j < matColSizeVal; j++) {
            mat[i][j] = value++;
        }
    }

    int returnSize;
    int* result = findDiagonalOrder(mat, matSize, matColSize, &returnSize);

    printf("Diagonal Order:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    for (int i = 0; i < matSize; i++) {
        free(mat[i]);
    }
    free(mat);
    free(result);

    return 0;
}