
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga1.h"

char* zdruzi(char** nizi, char* locilo) {
    int dolzina = 0;
    int indeks = 0;
    while (*(nizi+indeks) != NULL) {
        dolzina += strlen(*(nizi+indeks)) + strlen(locilo);
        indeks++;
    }
    if (dolzina > 0)
        dolzina -= strlen(locilo);
    char* zdruzeno = (char*) malloc (sizeof(char) * (dolzina + 1));
    for (int i = 0; *(nizi+i) != NULL; i++) {
        strcat(zdruzeno, *(nizi+i));
        if (i != indeks)
            strcat(zdruzeno, locilo);
    }
    *(zdruzeno+dolzina) = '\0';
    return zdruzeno;
}

int main() {
    return 0;
}
