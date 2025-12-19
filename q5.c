#include <stdio.h>
int countSetBits(int n) {
    int count = 0;
    while (n) {
        count += n & 1; 
        n >>= 1;   
    }
    return count;
}
int countBitsToFlip(int a, int b) {
    return countSetBits(a ^ b); 
}
int main() {
    int a, b;

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    printf("Number of bits to be flipped to convert %d to %d: %d\n", a, b, countBitsToFlip(a, b));

    return 0;
}
