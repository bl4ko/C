#include <stdio.h>

//staticni podatki (inicializerane na 0)
int i1, i2, i3;
char c1, c2, c3;
double d1, d2, d3;

int main()
{
    printf("int: i1:%p i2:%p i3:%p\n", &i1, &i2, &i3); //& naslove te spremenljivke, %p naslov v sestanjstiski obliki
    printf("char: c1:%p c2:%p c3:%p\n", &c1, &c2, &c3);
    printf("double: d1:%p d2:%p d3:%p\n", &d1, &d2, &d3);

    int *pi;
    pi = &i2; //pi vsebuje naslov spremenljivke i2 (npr; 0x5592e4085030)
    //& mu priredim naslov
    printf("i2: %p\n", pi);

    //spreminjanje pointerja
    i2=5; printf("i2=%d\n", i2);
    //*pi=7, ne shranjuj na pi, ampak na mesto katero kaze pi
    *pi=7; printf("i2=%d\n", *pi);

    *pi = 2 * (*pi); printf("it=%d\n", *pi);
    //spremenijamo vrednost na katero kaze pi

    printf("pi: %p\n", &pi); //naslov kazalca je nekje na drugm koncu pomnilnika
    //i2 zivi med staticnimi podatki
    //kazalec pi pa je lokalna spremenljivka(avtomatska) zivi na skladu
}
