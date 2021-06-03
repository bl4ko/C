#include <stdio.h>
#include <stdlib.h>

#define MAXNUM_LINES 10000000

int main(int argc, char** argv) 
{   
    if (argc < 3) {
        fprintf(stderr, "NAPAKA: premalo vhodnih argumentov!\n");
        return 1;
    }
    FILE* vhod = fopen(argv[1], "r");
    if (vhod == NULL) {
        fprintf(stderr, "NAPAKA: vhodna datoteka ni bila najdena\n");
        return 1;
    }
    if (argv[2] == NULL) {
        fprintf(stderr, "NAPAKA: int [n] ni bil usepsno prebran\n");
        return 1;
    }
    int n = atoi(argv[2]);
    char** vrstice = malloc(sizeof(char *) * MAXNUM_LINES);
    int stevec = 0;
    while (1) {
        char* vrstica = malloc(sizeof(char) * 10);
        if (fgets(vrstica, 11, vhod) == NULL) break;
        vrstice[stevec] = vrstica;
        stevec++;
    }
    if (n > stevec)
        n = stevec;
    int razlika = stevec - n;
    for (int i = 0; i < n; i++) {
        fprintf(stdout, "%s", vrstice[razlika+i]);
    }
    for (int i = 0; i < stevec; i++)
        free(vrstice[stevec]);
    fclose(vhod);
    return 0;
}
// n = 1000000
