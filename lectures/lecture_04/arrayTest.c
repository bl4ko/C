#include <stdio.h>

int a[10];

int main()
{   
    printf("naslov kazalca: %p\n", &a);
    printf("naslov: %p\n", a);
    printf("naslov: %p\n", a);
    for (int i = 0; i < 10; i++) {
        printf("indeks: %d, vrednost: %d, naslov: %p\n", i, a[i], &a[i]);       
    }

}