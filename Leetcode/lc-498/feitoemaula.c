#include <stdio.h>
#include <stdlib.h>

int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize) {

    int* result = malloc(sizeof(int) * (matSize * *matColSize));
    *returnSize = matSize * *matColSize;
    for (int i = 0; i < *returnSize; i++)
    {
        result[i] = 0;
    }

    int index = -1;
    int lines = 0;
    int cols = 0;

    while (index < *returnSize - 1)
    {
        index++;
        if (index >= *returnSize) break;

        while (lines >= 0)
        {
            result[index] = mat[lines][cols];
            if (lines - 1 < 0) break;
            lines--;
            cols++;
        }
        lines = 0;

        while (cols >= 0)
        {
            result[index] = mat[lines][cols];
            if (cols - 1 < 0) break;
            lines++;
            cols--;
        }
        cols = 0;
    }
    return result;
}