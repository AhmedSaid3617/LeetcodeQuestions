#include <stdio.h>

void shift(int *array, int index, int size)
{
    for (int i = index; i < size; i++)
    {
        array[i] = array[i+1];
    } 
}

int removeDuplicates(int* nums, int numsSize) {
    
    int removed = 0;
    if (numsSize < 3)
    {
        return numsSize;
    }
    
    for (int i = 2; i < numsSize; i+=1)
    {

        while (nums[i] == nums[i-2])
        {
            if (i == numsSize-1)
            {
                numsSize--;
                break;
            }
            shift(nums, i, numsSize);
            numsSize--;
        }
        
    }

    return numsSize;
    
}

int main(){
    int arr[] = {1, 1, 1};
    int size = 3;
    int k = removeDuplicates(arr, size);
    printf("k = %d\n", k);

    for (int i = 0; i < k; i++)
    {
        printf("%d ", arr[i]);
        printf("\n");
    }
    
}