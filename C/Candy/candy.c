#include <stdio.h>
#include <stdlib.h>

int ratings[] = {5, 4, 9, 0, 0, 0};

int getCandy(int ratings[], int ratingsSize)
{
    if (ratingsSize == 1)
    {
        return 1;
    }

    int candy_sum = 0;

    for (int i = 0; i < ratingsSize; i++)
    {
        candy_sum++;
        if (i && (ratings[i - 1] < ratings[i]) || (ratingsSize - i - 1) && ratings[i + 1] < ratings[i])
        {
            candy_sum++;
        }
    }

    return candy_sum;
}

int main()
{
    printf("\n%d\n", getCandy(ratings, 6));

    return 0;
}
