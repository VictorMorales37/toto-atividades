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