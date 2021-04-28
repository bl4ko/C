#include <stdio.h>

//grsi nacin z uporabo goto;
int collatz (int n) 
{
    if (n % 2 == 0) 
        goto even;
    odd:
        n = 3 * n + 1;
        goto exit;
    even:
        n = n /2;
        goto exit;
    exit:
        return n;
}

int collatz_length(int n)
{
    int len = 1;
    loop:
        if (n == 1)
            goto exit;
        n = collatz(n);
        len = len + 1;
        goto loop;
    exit:
        return len;
}


int main ()
{
    int n = 2021;
    printf("%d\n", collatz_length (n));
    return 0;
}




