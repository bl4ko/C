#include <stdio.h>
#include <stdlib.h>

int a[100]; //med staticnimi podatki

int main()
{
    int b[100]; //na skladu
    static int c[100]; //med staticnimi podatki

    printf("&a=%p\n", a); //naslov med staticnimi podatki
    printf("&b=%p\n", b); // naslov na STACKU
    printf("&c=%p\n", c); //naslov med staticnimi podatki

    
    //ko nevemo koliko podatkov bomo mel, ne moremo shranit tabele na static
    int m; scanf("%d", &m);
    //static int f[m]; //nebo delovalo, velikost more bit znana ze v casu prevajanja
    //RESITEV spravimo jo na HEAP (vec prostora od STACK)
    int *d; // kazalec d je shranjen na skladu/STACK
    /*
    funkcija malloc (memory allocation)
    -malloc sprejme 1 argument - stBajtov, vrne pa kazalec na prvega od teh bajtov
    void *
    malloc(size_t size);
    */
    d = (int*)malloc(100 * sizeof (int)); 
    //sedaj kaze d na podatek na HEAPu (100intov na katere kaze d, se nahajajo na HEAPu
    //ce d takega bloka nemore naredit - vrne null
    if (d == NULL) { printf ("ERROR\n"); exit (1); }
    for (int i = 0; i < 100; i++)
        printf("%d ", d[i]);
    printf("\n");

    free(d); //sprostimo pomnilnik

    int n; scanf("%d", &n);
    int *e;
    e = (int*)calloc(n, sizeof (int));  //calloc pocisti del pomnilnika (dobimo same nicle)
    if (e == NULL) { printf ("ERROR\n"); exit (1); }
    for (int i = 0; i < n; i++) printf("%d ", e[i]);
    printf("\n");
    free(e);
    for (int i = 0; i < n; i++) { e[i] = 2 * i; printf("%d ", e[i]); } printf("\n"); //  ZELO NEVARNO !!!, kos pomnilnika na katerega kaze e ni vec moja last (zaradi free(e))

    //primer tabele na SKLADU
    int m; scanf("%d", &m);
    int f[m]; // <- to bo delovalo za majhne vrednosti m, ker je na skladu/STACK malo prostora
    for (int i=0; i <m; i++) { f[i] = 2* 1; printf("%d ", f[i]); } printf("\n");

    
}