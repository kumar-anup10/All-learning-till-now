#include<stdio.h>
int checkpower(int n)
{
return (n > 0) && (n & (n - 1)) == 0;
}
int main()
{
    int n;
    printf("Enter the number");
    scanf("%d",&n);
    checkpower(n);
    if (checkpower(n)) {
        printf("%d is a power of 2.\n", n);
    } else {
        printf("%d is not a power of 2.\n", n);
    }
    return 0;
}