#include <stdio.h>
#include <stdlib.h>

void rotate(int *nums, int numsSize, int k)
{
    int net_rotation = k % numsSize;
    int *temp = (int *)calloc(net_rotation, sizeof(int));
    int j = net_rotation - 1;
    // Fill temp.
    for (int i = numsSize - 1; i >= numsSize - net_rotation; i--)
    {
        temp[j] = nums[i];
        j--;
    }

    // Rotate the latter half by k steps.
    for (int i = numsSize - 1; i >= net_rotation; i--)
    {
        nums[i] = nums[i - net_rotation];
    }

    // Put temp at the start of nums.
    for (int i = 0; i < net_rotation; i++)
    {
        nums[i] = temp[i];
    }
    
}

int main()
{
    int nums[] = {1,2,3,4,5,6,7};
    int size = 7;
    rotate(nums, size, 3);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", nums[i]);
    }
}