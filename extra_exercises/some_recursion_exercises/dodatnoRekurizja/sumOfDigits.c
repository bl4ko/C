#include <stdio.h>

int sumOfDigits(int n)
{
    if (n==0)
        return 0;
    return n % 10 + sumOfDigits(n/10);
}

int main()
{
    printf("Test Data:\nInput a number : ");
    int n; scanf("%d", &n);
    printf("The sum of digits of %d = %d\n", n, sumOfDigits(n));
}