#include <stdio.h>
#include <stdlib.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {

    int i = 0;
    int j = 0;
    int result[m + n];
    int index = -1;

    while (i < m || j < n)
    {
        if (i < m && j >= n)
        {
            for (i = i; i < m; i++)
            {
                index++;
                result[index] = nums1[i];
            }
        }

        else if (i >= m && j < n)
        {
            for (j = j; j < n; j++)
            {
                index++;
                result[index] = nums2[j];
            }
        }
        
        else if (nums1[i] < nums2[j])
        {
            index++;
            result[index] = nums1[i];
            i++;
        }
        else if (nums1[i] > nums2[j])
        {
            index++;
            result[index] = nums2[j];
            j++;
        }
        else if (nums1[i] == nums2[j])
        {
            index++;
            result[index] = nums1[i];
            i++;

            index++;
            result[index] = nums2[j];
            j++;
        }
    }

    for (int k = 0; k < (m + n); k++)
    {
        nums1[k] = result[k];
    }
}

int main() {
    int nums1[] = {1, 2, 3, 0, 0, 0};
    int nums2[] = {2, 5, 6};
    merge(nums1, 6, 3, nums2, 3, 3);
    for (int i = 0; i < 6; i++) printf("%d ", nums1[i]);
    printf("\n");
    return 0;
}