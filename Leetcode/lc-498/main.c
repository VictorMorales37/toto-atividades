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

// Output Valgrind:
/* ==291860== Memcheck, a memory error detector
==291860== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==291860== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==291860== Command: ./main
==291860== 
Diagonal Order:
1 2 4 7 5 3 6 8 9 
==291860== 
==291860== HEAP SUMMARY:
==291860==     in use at exit: 0 bytes in 0 blocks
==291860==   total heap usage: 6 allocs, 6 frees, 1,120 bytes allocated
==291860== 
==291860== All heap blocks were freed -- no leaks are possible
==291860== 
==291860== For lists of detected and suppressed errors, rerun with: -s
==291860== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0) */