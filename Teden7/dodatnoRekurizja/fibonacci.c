#include <stdio.h>
#include <stdlib.h>

int num_calls;
int memo[20];


int fib_rec(int n)
{   
    num_calls++;
    if (n == 1 || n == 0)
        return 1;
    else 
        return fib_rec(n-1) + fib_rec(n-2);
}

int fib_memo(int n, int* memo) 
{   
    num_calls++;
    if (n<=1)
        return 1;
    if (*(memo+n) > 0)
        return *(memo+n);
    int pp = fib_memo(n-2, memo);
    int p = fib_memo(n-1, memo);
    *(memo+n) = pp + p;
    return *(memo+n);
}

int main()
{
    for (int n = 0; n <= 30; n++) {
        num_calls = 0;
        int* arr = (int*) calloc(n+1, sizeof(int));
        fib_rec(n);
        printf("fib(%2d) = %7d | ", n, num_calls);

        num_calls = 0;
        fib_memo(n, arr);
        printf("fib_memo(%2d) = %3d ", n, num_calls);
        printf("\n");
    }
    return 0;
}