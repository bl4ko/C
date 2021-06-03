
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VRSTICA 1000

int main(int argc, char** argv) 
{   
    if (argc < 3) {
        fprintf(stderr, "Premalo vnesenih argumentov!\n");
        return 1;
    }
    FILE* grdaKoda = fopen(argv[1], "r");
    if (grdaKoda == NULL) {
        fprintf(stderr, "NAPAKA: datoteka:\"grda koda\" ni bila najdena\n");
        return 1;
    }
    FILE* lepaKoda = fopen(argv[2], "w");
    if (lepaKoda == NULL) {
        fprintf(stderr, "NAPAKA: datoteka:\"lepa koda\" ni bila najdena\n");
        return 1;
    }

    int stPresledkov = 0;          // #presledkov
    char* vrstica = malloc(sizeof(char) * MAX_VRSTICA + 1);
    while (1) {
        char prviZnak;
        while ((prviZnak=fgetc(grdaKoda)) == ' '); //se znebimo presledkov
        if (prviZnak == EOF) {
            free(vrstica);
            fclose(lepaKoda);
            fclose(grdaKoda);
            return 0;
        }
        else if (prviZnak == '\n') {  // prazna vrstica
            fputc(prviZnak, lepaKoda); 
            continue;       
        }
        else if (prviZnak == '}') {
            stPresledkov-=4; stPresledkov = stPresledkov < 0 ? 0 : stPresledkov;
        }
        for (int i = 0; i < stPresledkov; i++) {// v lepo kodo nalozimo presledke
            fputc(' ', lepaKoda);   
        }
        fputc(prviZnak, lepaKoda);  // v lepo kodo nalozimo prvi znak
        fgets(vrstica, MAX_VRSTICA+1, grdaKoda); // preberemo vrstico do konca
        fputs(vrstica, lepaKoda);  // v lepo kodo nalozimo vrstico do konca
        if (((strlen(vrstica) == 1) && (prviZnak == '{')) || vrstica[strlen(vrstica) - 2] == '{') { // preverimo zadni znak v vrstici
            stPresledkov+=4;
        }
    }
}