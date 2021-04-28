#include <stdio.h>

//staticni podatki (inicializerane na 0)
int i1, i2, i3;

int a[3]; //na zaporednih naslovih, staticno

int main()
{   
    //int a[1000000000]; //velikih tabel nikoli ne dajemo na sklad, saj nam bo zmankalo prostora
    //segmentation fault - porabil sem ves prostor ki mi ga C nudi na skladu
    printf("int    : %p %p %p\n", &i1, &i2, &i3);
    printf("int    : %p %p %p\n", &(a[0]), &(a[1]), &(a[2]));

    for (int i =0; i < 3; i++) {
        a[i] = i;
    }
    for (int i=0; i < 3; i++) {
        printf("a[%d]=%d\n", i, a[i]);
    }

    return 0;
}