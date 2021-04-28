#include <stdio.h>

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

int fib_memo(int n, int* arr) 
{
    num_calls++;
    if (n == 1 || n == 0)
        return 1;
    else {
        if (*(arr+n-1) == 0)
            *(arr+n-1) = fib_rec(n-1);
        if (*(arr+n-2) == 0)
            *(arr+n-2) = fib_rec(n-2);
        return *(arr+n-1) + *(arr+n-2);
    }
}

int main()
{
    for (int n = 0; n < 30; n++) {
        num_calls = 0;
        int* arr = (int*) calloc(n+1, sizeof(int));
        printf("fib(%d) = %d ", n, fib_rec(n));
        printf("(%d)-------------", num_calls);
        num_calls = 0;
        printf("fib_memo(%d) = %d ", n, fib_memo(n, arr));
        printf("(%d)\n", num_calls);
        
    }
    return 0;
}