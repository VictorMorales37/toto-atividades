#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {

    int *result = malloc(sizeof(int) * 2);
    *returnSize = 2;

    int l = 0;
    int r = numbersSize - 1;

    while (l < r)
    {
        int sum = numbers[l] + numbers[r];
        if (sum > target) r--;
        else if (sum < target) l++;
        else 
        {
            result[0] = l + 1;
            result[1] = r + 1;
            return result;
        }
    }
    return result;
}

int main()
{
    int array[4] = {2, 7, 11, 15};
    int returnSize;
    int * result = twoSum(array, 4, 9, &returnSize);
    for (int i = 0; i < 2; i++) printf("%d ", result[i]);
}