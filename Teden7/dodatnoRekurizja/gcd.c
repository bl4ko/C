#include <stdio.h>

int gcd(int n1,int n2, int min)
{
    if (n1 % min == 0 && n2 % min == 0)
        return min;
    return gcd(n1, n2, min-1);
}

int main()
{
    printf("Input 1st number: "); int n1;
    scanf("%d", &n1);
    printf("Input 2nd number: "); int n2;
    scanf("%d", &n2);
    printf("gcd(%d,%d) = %d\n", n1, n2, gcd(n1, n2, n1 > n2 ? n2 : n1));
}