#include <stdio.h>

int scanner()
{   
    int a = 0;
    int predznak = getchar();
    if (predznak != 45) {
        a = predznak - 48;
        predznak = 43;
    }
    int c = getchar();
    while ('0' <= c && c <= '9') {
        a = a * 10 + (c - 48);
        c = getchar();
    }
    return (predznak == 43) ? a : -a;
}

void izpisi(int n)
{
    if (n < 0) {
        n = -n;
        putchar('-');
    }
    if (n/10)
        izpisi(n/10);
    putchar(n%10 + '0');
}

int main() 
{   
    int a = scanner();
    int b = scanner();
    izpisi(a+b);
    putchar('\n');
    return 0;
}

