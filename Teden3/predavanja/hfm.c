#include <stdio.h>

/*
F(0) = 1
M(0) = 0;

F(n) = n - M(F(n-1))
M(n) = n - F(M(n-1))
*/

int m(int n);

int f(int n)
{   
    //printf(".");
    if (n == 0)
        return 1;
    else 
        return n - m(f(n-1));
}

int m(int n)
{
    //printf("*");
    if (n == 0)
        return 0;
    else
        return n - f(m(n-1));
}

int main()
{
    for (int n = 0; n < 10; n++)
        printf("(%d,%d)\n", f(n), m(n));
    return 0;
}