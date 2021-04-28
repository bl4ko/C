#include <stdio.h>

//staticni podatki (inicializerane na 0)
int i1, i2, i3;

void ini1(int a[100])
{
    for (int i =0; i < 100; i++) {
        a[i] = i;
    }
}

void init2 (int a[], int n)
{
    for (int i =0; i < n; i++) {
        a[i] = i;
    }
}

void init3(int *a, int n) {
    for (int i =0; i < n; i++) {
        a[i] = i;
    }
}

int main()
{   
    static int a[100];
    printf("int    : %p %p %p\n", &i1, &i2, &i3);
    printf("int    : %p %p %p\n", &(a[0]), &(a[1]), &(a[2]));

    //init1(a); //poslemo naslov
    //init2(a, 100);
    //init2(&(a[0]), 100);
    init3(&(a[10]), 100);
    

    for (int i=0; i < 100; i++) {
        printf("a[%d]=%d\n", i, a[i]);
    }
    
    return 0;
}