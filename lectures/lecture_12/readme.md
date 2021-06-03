VECJI PROGRAMI
* kodo razdelimo v dolocene sklope(pomensko loceni)
* razdelimo na datoteke, directoriye
* ukvarjali se bomo s stvarmi, ki jih C ponuja za vec datotek   

PROGAM V DVEH DATOTEKAH
* prg.c in lists.c
    * gcc prg.c (program preveden v binarno obliko primerno za izvajanje)
    * (gcc -c prg.c --> prg.o (program preveden v strojno obliko))
        * vsa koda je prevedena, ni pa se dodano (knjizice npr. <stdio.h>)
        * __gcc -o prg prg.o__ --> prg.o povezemo s standardno knjiznico in naredimo exe file
    * Bistvo je da vemo da program prevajamo v dveh korakih
        * __gcc -c prg.c__ #SAMO PREVAJANJE
        * __gcc -o prg prg.o__ #SAMO POVEZOVANJE
    * V datoteki prg uporabimo program lists
        * gcc -c prg.c
        * gcc -c lists.c
        * Sedaj datoteki povezemo:
            * __gcc -o prg prg.o lists.o__ --> program ki deluje
            * Naredili smo program povezan iz dveh razlicnih datotek
        * \[PROBLEM\] uporaba spremenljivke iz lists.c v prg.c
        ```C
        #include <stdio.h>

        extern int num_nodes;   // extern=zunanja
        void lists();
        //...
        ```
* nacini kako skriti spremenljivko/funkcijo v nekem delu programa, pred ostalimi deli programa (da prepreicm spreminjanje vrednosti te spremenljivke od drugod)
* na nek nacin to v javi dosezemo z uporabo besede __private__
* v C ju to dosezemo z kljucno besedo __static__
```C
#include <stdio.h>

static int num_nodes = 0;   // klucna beseda static

void lists ()
{
    printf("[module lists]\n");
    printf("lists: %d\n", num_nodes);
    return;
}
```
`
* z besedo static smo zakrili spremenljivko num_nodes za zunanje programe
* enako z besedo static zakrijemo metodo
```C
static int* lists() 
{
    printf("[module lists]\n");
    printf("lists: %d\n", num_nodes);
    return &num_nodes;
}
```

* lists.h
    * deklaracijska datoteka
    * deklaracije bojo enake v vseh datotekah k jo includajo
    ```C
    //zgled lists.h

    extern int num_nodes;
    void lists();
    ```
    * pvoezemo z datoteko
    ```c
    #include <stdio.h>
    #include "lists.h"  // povezemo z deklaracijsko datoteko
    ```

## POGOJNO PREVAJANJE
* poznamo
    * #ifdef (ali je makro definiran)
    * #ifndef (if makro not defined !ifdef)
    * #if (ali ima makro vrednost razlicno od 0)
* (prevajalniku povem kdaj naj del kode prevede, kdaj naj del kode izpusti) __gcc -E prg.c__
```c
#ifdef TEST // ce je test macro definiran, se bo stavek prevedu, drugace se ne bo
    printf("prg: %d\n", num_nodes);
#endif
```
* na tak nacin lahko vplivam ker del kode se be izvrsil
```C
#include <stdio.h>

#include "lists.h"

int main(int argc, char** argv) 
{
    printf("Hello world\n");
    lists();
#ifdef TEST
    printf("prg: %d\n", num_nodes);
#else
    printf("Done.\n");
#endif
    return 0;
}
}
```
* Oblika deklaracijske datoteke: zagotavljanje da se datoteka "lists.h" vkljuci natancno enkrat; ```C #include "lists.h"; #include "lists.h"; \\../ ```
```c
#ifndef _LISTS_
#define _LISTS_

extern int num_nodes;
void lists();
#endif
```

