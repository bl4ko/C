
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "naloga.h"

// int steviloZnakov(char* niz, char znak) {
//     int dolzina = strlen(niz);
//     int stZnakov = 0;
//     for (int i = 0; i < dolzina; i++)
//         if (*(niz+i) == znak)
//             stZnakov++;
//     return stZnakov;
// }

//V2
int steviloZnakov(char* niz, char znak) {
    int stZnakov = 0;
    while (*niz != '\0') { 
        if (*niz == znak) 
            stZnakov++;
        niz++;
    }
    return stZnakov;
}

// char* kopirajDoZnaka(char* niz, char znak) {
//     int novaDolzina = 0;
//     int dolzina = strlen(niz);
//     for (int i = 0; i < dolzina; i++, novaDolzina++) {
//         if (*(niz+i) == znak)
//             break;
//     }
//     char* podniz = (char*) calloc (novaDolzina + 1, sizeof(char));
//     for (int i = 0; i < novaDolzina; i++)
//         *(podniz + i) = *(niz + i);
//     *(podniz + novaDolzina) = '\0';
//     return podniz;
// }

//V2
char* kopirajDoZnaka(char* niz, char znak) {
    char* p = niz;
    while (*p != znak && *p != '\0') 
        p++;
    int dolzinaPodZaporedja = p-niz;
    char* podniz = (char*) calloc (dolzinaPodZaporedja + 1, sizeof(char));
    for (int i = 0; i < dolzinaPodZaporedja; i++)
        *(podniz + i) = *(niz + i);
    *(podniz + dolzinaPodZaporedja) = '\0';
    return podniz;
}

// char** razcleni(char* niz, char locilo, int* stOdsekov) {
//     *stOdsekov = steviloZnakov(niz, locilo) + 1;
//     char** odseki = (char**) calloc (*stOdsekov, sizeof(char*));
//     for (int i = 0; i < *stOdsekov; i++) {
//         char* delniOdsek = kopirajDoZnaka(niz, locilo);
//         niz += strlen(delniOdsek) + 1;
//         *(odseki+i) = delniOdsek;
//     }
//     return odseki;
// }

//V2
char** razcleni(char* niz, char locilo, int* stOdsekov) {
    *stOdsekov = steviloZnakov(niz, locilo) + 1;
    char** odseki = (char**) calloc (*stOdsekov, sizeof(char*));
    for (int i = 0; i < *stOdsekov; i++) {
        char* delniOdsek = kopirajDoZnaka(niz, locilo);
        niz += strlen(delniOdsek) + 1;
        *(odseki+i) = delniOdsek;
    }
    return odseki;
}

int main() {
    // koda za ro"cno testiranje (po "zelji)
    //prva naloga
    //printf("%d\n", steviloZnakov("abrakadabra", 'a'));
    //printf("%d\n", steviloZnakov("prijazen niz z enim samim presledkom med besedami", ' '));

    //druga
    // printf("%s\n", kopirajDoZnaka("prijazen niz z enim samim presledkom med besedami", 't'));
    // printf("%s\n", kopirajDoZnaka("prijazen niz z enim samim presledkom med besedami", 'e'));
    // printf("%s\n", kopirajDoZnaka("prijazen niz z enim samim presledkom med besedami", ' '));
    // printf("%s\n", kopirajDoZnaka("prijazen niz z enim samim presledkom med besedami", 'p'));

    //tretja
    // char* niz = "svoje_delo_oddajte_najkasneje_do_nedelje";
    // int stOdsekov = 0;
    // char** razclenjeno = razcleni(niz, '_', &stOdsekov); 
    // for (int i = 0; i < stOdsekov; i++)
    //     printf("%s\n", *(razclenjeno+i));
    // // //printf("velikost = %ld\n", sizeof(char*)); 
    return 0;
}
  