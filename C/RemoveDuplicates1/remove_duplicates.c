#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int *nums, int numsSize)
{
    int k = 0;
    int *unique = calloc(numsSize, sizeof(int));

    for (int i = 0; i < numsSize; i++)
    {
        if (k == 0 || (nums[i] != unique[k-1]))
        {
            unique[k++] = nums[i];
        }
    }

    for (int i = 0; i < k; i++)
    {
        nums[i] = unique[i];
    }

    free(unique);

    return k;
}

int main()
{
    int nums[] = {0, 1, 1, 2};
    int numsCount = 4;
    int k_out = removeDuplicates(nums, numsCount);
    printf("Num: %d\n", k_out);

    for (int i = 0; i < k_out; i++)
    {
        printf("%d\n", nums[i]);
    }
}
