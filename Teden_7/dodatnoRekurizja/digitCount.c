#include <stdio.h>

int digCount(int n)
{
    if (n == 0)
        return 0;
    return 1 + digCount(n/10);
}

int main()
{
    printf("Vnesite stevilo : ");
    int n; scanf("%d", &n);
    printf("St mest = %d\n", digCount(n));
    return 0;
}