#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int numOfPermutations;

bool preveri(int stevilo, int n, int* arr) {
    int indeks = 0;
    while (indeks < n) {
        if (*(arr+indeks) == stevilo)
            return false;
        indeks++;
    }
    return true;
}

void permutation(int n, int dimension, int* arr)
{
    if (n == dimension) {
        numOfPermutations++; 
        for (int i = 0; i < n; i++) {
            if (i == 0) 
                printf("(%d,",*(arr+i));
            else if (i == n-1)
                printf(" %d)\n", *(arr+i));
            else
                printf(" %d,", *(arr+i));
        }
    }
    else {
        for (int i = 1; i <= n; i++) {
            if (preveri(i, dimension, arr)) {
                *(arr+dimension) = i;
                permutation(n, dimension+1, arr);
            }
        }
    }
}

int main()
{   
    int n; scanf("%d", &n);
    int* arr = (int*) malloc (sizeof(int) * n);
    permutation(n, 0, arr);
    printf("%d! = %d\n", n, numOfPermutations);
    return 0;
}