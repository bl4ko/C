#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void razlike(FILE* prva, FILE* druga, FILE* izhod) {
    char* vrsticaPrva = malloc(sizeof(char)*1001);
    char* vrsticaDruga = malloc(sizeof(char)*1001);
    int i = 1;
    while (fgets(vrsticaPrva,1001,prva) != NULL) {
        fgets(vrsticaDruga, 1001, druga);
        if (strcmp(vrsticaPrva, vrsticaDruga) != 0) {
            fprintf(izhod, "%d\n", i);
        }
        i++;
    }
}

int main(int argc, char** argv) {
    FILE* prva = fopen(argv[1], "r");
    FILE* druga = fopen(argv[2], "r");
    razlike(prva, druga, stdout);
    fclose(prva);
    fclose(druga);
    return 0;
}