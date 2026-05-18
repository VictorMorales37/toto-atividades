//Nome: Victor Matheus Marques Morales
//Matrícula: 25100782
//Turma: M1

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {
    
    int *result = malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;

    int stack[10000];
    int top = -1;

    for (int i = 0; i < numsSize; i++)
    {
        result[i] = -1;
    }

    for (int i = 2 * numsSize - 1; i >= 0; i--)
    {
        int index = i % numsSize;

        while (top >= 0 && stack[top] <= nums[index])
        {
            top--;
        }

        if (top >= 0)
        {
            result[index] = stack[top];
        }

        stack[++top] = nums[index];
    }

    return result;
}