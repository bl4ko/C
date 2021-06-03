#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_IZRAZ 1000
/*
 * Vrne true natanko tedaj, ko izraz vsebuje odvecni par zunanjih oklepajev
 * izraz: kazalec na zacetek izraza
 * dolzina: dolzina izraza( redundanten podatek, a poveca ucinkovitost) 
 */
bool odvecniZunanjiParOklepajev(char* izraz, int dolzina) {
    if (izraz[0] != '(' || izraz[dolzina - 1] != ')') {
        return false;
    }
    //         ((3-2)*6)/(8-3) // nista odvec
    //bilanca: 122221110  -> oklepaji niso odvec (prisli smo do 0)
    int bilanca = 1; // pove, znotraj koliko oklepajev se trenutno nahajamo
    for (int i = 1; i < dolzina -1; i++) {
        char znak = izraz[i];
        if (znak == '(') {
            bilanca++;
        } else if (znak == ')') {
            bilanca--;
            if (bilanca < 1) {
                //obstaja del izraza, ki je izven okepajev;
                // to pomeni, da zunanji par oklepajev ni odvec
                return false;
            }
        }
    }
    return true;
}

/*
 * Vrne indeks najbolj desnega + ali - izven oklepajev; "ce ga ni,
 * vrne indeks najbolj desnega * ali / izven oklepajev: " ce ni niti tega;
 * vrne -1
 */
int najboljDesniNajsibkejsiOperator(char* izraz, int dolzina) {
    int bilanca = 0; // pove znotraj koliko oklepajev se trenutno nahajamo 
    int zadnjiPM = -1;  // indeks zadnjega + ali - izven oklepajev
    int zadnjiKD = -1;  // indeks zadnjega * ali / izven oklepajev

    for (int i = 0; i < dolzina; i++) {
        char znak = izraz[i];
        if (znak == '(' || znak == ')') {
            bilanca += (znak == '(' ? (1) : (-1));
        } else if (bilanca == 0) {
            if (znak == '+' || znak == '-') {
                zadnjiPM = i;
            } else if ( znak == '*' || znak == '/') {
                zadnjiKD = i;
            }
        }
    }
    return (zadnjiPM >= 0) ? (zadnjiPM) : (zadnjiKD);
}

int izracunaj(char* izraz) {
    int dolzina = strlen(izraz);

    // odstranjuj odvecne pare zunanjih oklepajev, dokler obstajajo
    while (odvecniZunanjiParOklepajev(izraz, dolzina)) {
        izraz[dolzina-1] = '\0';
        izraz++;
        dolzina -= 2;
    }

    // ugotovi polozaj najbolj desnega najsibkejsega operatorja izven okelapjov
    int polozaj = najboljDesniNajsibkejsiOperator(izraz, dolzina);

    if (polozaj < 0) {
        // izraz nima operatorjev izven oklepajev, kar pomeni
        // da je sestavljen iz enega samega operanda, torej iz 
        // ene same stevke
        return izraz[0] - '0';  //pew pew pew
    }

    char operator = izraz[polozaj];

    // izracunaj desni podizraz
    //indeks desnega podizraza = izraz + polozaj + 1
    int desni = izracunaj(izraz + polozaj + 1);
    // izracunaj levi podizraz
    izraz[polozaj] = '\0';  // furst nice hack
    int levi = izracunaj(izraz);

    // povezi razultata z operatorjem
    switch (operator) {
        case '+':
            return levi + desni;
        case '-':
            return levi - desni;
        case '*':
            return levi * desni;
        case '/':
            return levi / desni;
    }
    return 0;     // do tod ne bi smeli nikoli priti
}

int main() {
    char* izraz = malloc(MAX_IZRAZ + 1 * sizeof(char));
    scanf("%s", izraz);
    printf("%d\n", izracunaj(izraz));
    free(izraz);
    return 0;
}