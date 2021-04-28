#include <stdio.h>

//extern - zunanje spremenljivke
extern int f1calls; //nekje drugje je definirana spremenljivka f1calls,
//izognimo se tezavam z: naprej deklaracija, potem uporaba

//register je hitrejsi od pomnilnika (ni treba prenasati podatkov med pomnilnikom in procesorjem)
// register int m;, zgolj sugeriramo racunalniki da se jo hrani na pomnilniku
// register se prakticno ne uporablja


//spremelnljivke so hkrati v pomnliniku na razlicnih mestih
//zato jih pomnilnik shranjuje v skladu
int f1(int n)
{   
    f1calls = f1calls + 1;
    int m; //ne inacializerana spremenljivka nima garantirane vrednosti
    //m bo enak tistemu delu pomnilnika ki ga b f dubu na skladu
    //ni garantirano da bo tisti del prezaen;



    printf("%d %d\n",n,m);
    if (n==1)
        return 1;
    else 
        return n * (f1(n-1));
}

int f2(int n)
{   
    int m; //ne inacializerana spremenljivka nima garantirane vrednosti
    static int f2calls = 0; //static zagotavlja da f2calls ni na skladu ampak je med staticnimi 
    //podatki ravno tako kot f1calls, (inicializacija se izvede samo enkrat)
    f2calls = f2calls + 1;
    if (f2calls > 7) printf("!!!\n");
    printf("%d %d\n",n,m);
    if (n==1)
        return 1;
    else 
        return n * (f2(n-1));
}

/* seed -> (seed * 42746 + 62831) % 19 */
//int seed = 13;

int rnd(int new_seed)
{
    static int seed = 13; //dela enako le da je vidna znotraj funkcije
    //njena trenutna vrednost se zapomne med posamzenimi klici
    //ob vsakem klicu bo staticna spremenljivka imela vrednost na istm mestu v pomnilniku (data)
    if (new_seed != 0)
        seed = new_seed % 19;
    seed = (seed * 42746 + 62831) % 19;
    return seed;
}



int main()
{
    printf ("%d (%d)\n", f1(10), f1calls); //k so printf izvrsi, se sklad sprosti
    
    // printf ("%d\n", f2(10));
    // printf ("%d\n", f2(10)); //f2calls ohrani vrednost med razlicnimi klici fun. f2
    // for (int i = 0; i < 100; i++) {
    //     printf("%d ", rnd(i));
    // }
    // printf("\n");
    return 0;
}

//staticna spremenljivka
int f1calls; //staticne so inicializerane avtomatsko na 0