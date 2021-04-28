#include <stdio.h>

void naturalnumbs(int n, int lim) {
    if (n<=lim) {
        printf("%d ", n);
        naturalnumbs(n+1, lim); 
    }
}

int main()
{   
    int n; scanf("%d",&n);
    int lim; scanf("%d",&lim);
    printf("The natural numbers are: ");
    naturalnumbs(n, lim);
    putchar('\n');
}