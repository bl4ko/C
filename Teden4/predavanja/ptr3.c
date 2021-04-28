#include <stdio.h>

//sprejme samo vrednost
void f1(int n) {
    printf("f1: n=%d @ %p\n", n, &n);
    n = 2 * n;
    printf("f1: n=%d @ %p\n", n, &n);
}

//sprejme naslove spremenljivke n2
void f2(int *n) {
    printf("f2: n=%p @ %p\n", n, &n);
    printf("f2: *n=%d\n", *n);
    // n = 0x.....3787c
    // n naslovu 0x....3787c je shranjena vrednost 4
    // *n = 4
    (*n) = 2 * (*n);
    printf("f2: n=%p @ %p\n", n, &n);
    printf("f2: *n=%d\n", *n);
}


int main() 
{
    int n1 = 3;
    int n2 = 5;
    printf("%lu %lu\n", sizeof (int), sizeof(int*));
    printf("n1 @ %p\n", &n1);
    printf("n2 @ %p\n", &n2);
    printf("n1=%d n2=%d\n", n1, n2);
    f1(n1);
    f2(&n2); //poslemo naslov
    printf("n1=%d n2=%d\n", n1, n2);
    return 0;
}