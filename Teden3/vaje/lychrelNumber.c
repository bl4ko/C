#include <stdio.h>
#include <stdbool.h>

long int reverse(long int n) 
{
    long int reverse = 0;
    while (n > 0) {
        reverse = reverse * 10 + n % 10; 
        n /= 10;
    }
    return reverse;
}

bool jeLych(long int n, int k)
{   
    for (int i = 0; i < k; i++) {
        n = n + reverse(n);
        if (n == reverse(n))
            return false;
        if (n > 1e17)
            return true;
    }
    return true;
}


int main()
{
    int k, a, b;
    scanf("%d %d %d", &k, &a, &b);
    int stStevil = 0;
    for (int i = a; i <= b; i++) {
        if (jeLych(i,k)) {
            stStevil++;
        }

    }
    printf("%d\n", stStevil);
    return 0;
}
