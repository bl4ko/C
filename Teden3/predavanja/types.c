#include <stdio.h>


int main()
{
    //po def int signed
    //%lu pomeni stevilo v obliki unsigned long
    // signed (predznacen) (npr za 4 bite: -8...7)
    printf("%lu\n", sizeof(int));
    printf("%lu\n", sizeof(short int));
    printf("%lu\n", sizeof(long int));

    //unsigned (nepredznacen) (npr za 4 bite: 0....15)
    printf("%lu\n", sizeof(unsigned int));
    printf("%lu\n", sizeof(unsigned short int));
    printf("%lu\n", sizeof(unsigned long int));

    signed char sc;  //256 vrednosti: -128...+127
    unsigned char uc; //256 vrednosti: 0..255
    printf("%lu\n", sizeof(char));

    // float, double, long double
    printf("%lu\n", sizeof(float));     //32 bit
    printf("%lu\n", sizeof(double));    //64 bit
    printf("%lu\n", sizeof(long double));   //128 bit

    printf("\n");
    float x = 0.1;
    //if (x==0.1) printf("ENAKO\n");
    if ((x - 0.1 < 1e-3) || (0.1- x < 1e-3)) printf("ENAKO\n");
    while (x!=1.0) {
        x = x + 0.1;
        printf("%2.25f\n", x); //zoprne numericne napake, pogoji se ne izvedejo
        //0.1 = 0 * 10^0 + 1 * 10^-2
        //0.1 = 0*2^0 + x1 * 2^-1 + .... + xn * 2^-n
        //nemoremo z omejeno biti v dvojiskem sistemu predstavit 0.1
        //0.1 nemorem predstavit s koncnim n jem v binarni obliki

    }
    printf("KONEC\n");
    return 0;
}