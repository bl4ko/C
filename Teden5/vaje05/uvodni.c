#include <stdio.h>

void kvadrat(int *x)
{
    *x = *x * *x;
}

int main()
{
    int a = 2;
    int *pa = &a;

    // int *neki;
    // <---
    // .... = *neki (kamor kaze pointer)
    
    printf("%d\n", a);

    kvadrat(a);
    printf("a = %d\n", a);

    return 0;
}