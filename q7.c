#include <stdio.h>
int division(int n, int m)
{
    int rem = 0;
    int que = 0;
    while (m <= n)
    {
        n = n - m;
        que++;
    }
    printf("quotient will be %d \n Remainder will be %d", que, n);
    return n;
}
int main()
{
    int n = 20;
    int m = 3;
    division(n, m);
}