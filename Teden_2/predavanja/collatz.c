#include <stdio.h>

// n sod: n/2
// n lih: 3n+1

//deklaracija funkcije (pove --> tip razultata, ime, parametri)
int collatz(int n); //uporabljamo ko zelimo premesat vrstni red funkcij, ali rekurzivne
//grdo in prav tudi {int collatz(int);}

int collatz_length(int n)
{
    int len = 1;
    while (n != 1) {
        n = collatz (n);
        len = len + 1;
    }
    return len;
}


int main ()
{
    int n = 2021;
    printf("%d\n", collatz_length (n));
    return 0;
}



//ker je funkcija deklarriana zgoraj, prevajalnik ze ve kaksna je ta funkcija
//sedaj napisemo se definicjo funkcije
int collatz (int n) //tudi int collatz(n) int n; (star nacin)
{
    if (n % 2 == 0) 
        return n / 2;
    else 
        return 3 * n + 1;
}


