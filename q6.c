#include <stdio.h>

int square(int x)
{
    int result = 0;

    // Add x to result x times
    for (int i = 0; i < x; i++)
    {
        result += x;
    }

    return result;
}

int main()
{
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    int result = square(number);
    printf("The square of %d is: %d\n", number, result);

    return 0;
}
