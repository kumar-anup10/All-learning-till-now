#include <stdio.h>

int findSetBitPosition(int n)
{
    if (n == 0)
    {
        return -1;
    }

    int position = 1;
    while ((n & 1) == 0)
    {
        n = n >> 1;
        position++;
    }

    return position;
}

int main()
{
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    int position = findSetBitPosition(number);

    if (position == -1)
    {
        printf("No set bits in %d.\n", number);
    }
    else
    {
        printf("The position of the first set bit in %d is: %d\n", number, position);
    }

    return 0;
}
