#include <stdio.h>

int collatz (int n) 
{
    if (n % 2 == 0) 
        return n / 2;
    else 
        return 3 * n + 1;
}

//resitev z rekurzijo
int collatz_length(int n) 
{
    if (n==1)
        return 1;
    else
        return collatz_length(collatz(n)) + 1;
}

int main ()
{
    int n = getchar() -'0';
    printf("%d\n", collatz_length(n));
    return 0;
}


//------------------------------------------------------------------------
/*

collatz_length: izracuna dolzino zapredja, ki se zacne z n
zgled:
10 5 16 8 4 2 1     cl(10) = 7;

cl(n) = 1 (n=1) || c(n) + 1 n!=1

*/

