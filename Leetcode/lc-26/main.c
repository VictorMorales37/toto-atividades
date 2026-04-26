#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize) {

    int newNums[numsSize];
    int k = 0;
    
    for (int i = 0; i < numsSize; i++)
    {
        if (i == 0 || nums[i] != nums[i-1]) 
        {
            newNums[k] = nums[i];
            k++;
        }
    }

    for (int i = 0; i < k; i++)
    {
        nums[i] = newNums[i];
    }

    return k;
}

int main() {
    int nums[] = {1, 1, 2};
    int k = removeDuplicates(nums, 3);
    printf("%d\n", k);
    for (int i = 0; i < k; i++) printf("%d ", nums[i]);
    printf("\n");
    return 0;
}