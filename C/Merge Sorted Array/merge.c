#include <stdio.h>

void shift(int *array, int index, int size);

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{
    int index = 0;
    int output_size = m;

    // If one of the arrays is empty.
    if (!n || !m)
    {
        // Then copy nums2 into nums1.
        // Note: If  nums2 is empty then this loop doesn't get executed and nums1 stays the
        // same, which is the expected behavior.
        for (int i = 0; i < n; i++)
        {
            nums1[i] = nums2[i];
        }
    }
    else
    {
        // Loop over nums2
        for (int i = 0; i < n; i++)
        {
            // If nums2[i] is greater than the last element in the output array?
            if (nums2[i] >= nums1[output_size - 1])
            {
                // Just append the rest of num2 to the output array.
                for (int k = output_size; k < n + m; k++)
                {
                    nums1[k] = nums2[i++];
                }
                // Then break.
                break;
            }

            for (int j = 0; j < output_size; j++)
            {
                if (nums2[i] <= nums1[j])
                {
                    shift(nums1, j, n + m);
                    nums1[j] = nums2[i];
                    index = j + 1;

                    output_size++;
                    break;
                }
            }
        }
    }
}

void shift(int *array, int index, int size)
{
    for (int i = size - 1; i > index; i--)
    {
        array[i] = array[i - 1];
    }

    array[index] = 0;
}

int main()
{
    int nums1[] = {-100, -10, -3, 0, 0, 0};
    int nums2[] = {-100, 10, 5000};

    merge(nums1, -190, 3, nums2, -190, 3);

    for (int i = 0; i < 6; i++)
    {
        printf("%d, ", nums1[i]);
    }
}