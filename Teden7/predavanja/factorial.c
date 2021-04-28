#include <stdio.h>
#include <stdlib.h>

int fact_itr (int n)
{
    int nf = 1;
    for (int i = 1; i <= n; i++)
        nf *= i;
    return nf;
}

int fact0() 
{
    return 1;
}

int fact1()
{
    return 1* fact0();
}

int fact2()
{
    return 2* fact1();
}

int fact3()
{
    return 3* fact2();
}

int fact4()
{
    return 4* fact3();
}

int num_calls;

int fact_rec (int n)
{   
    num_calls++;
    if (n==0)
        return 1;
    else 
        return fact_rec(n-1) * n;
}

int main()
{
    for (int n = 0; n < 10; n++) {
        num_calls = 0;
        printf("%4d! = %d, num_calls = %d\n",n, fact_itr(n), num_calls);
    }
    
    putchar('\n');
}
