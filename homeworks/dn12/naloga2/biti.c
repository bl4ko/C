#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char** argv) 
{
    if (argc < 4) {
        fprintf(stderr, "NAPAKA: premalo vhodnih argmuentov\n");
    }
    FILE* vhod = fopen(argv[1], "rb");
    int p = atoi(argv[2]);
    int q = atoi(argv[3]);
    
    unsigned char c;
    int indeksBita = 0;
    while ((fread(&c, sizeof(unsigned char), 1, vhod)) != 0) {
        if ((indeksBita+7) >= p) {
            int byteVal = c;
            bool val[8];
            for (int i = 0; i < 8; i++) {
                val[7-i] = byteVal % 2;
                byteVal /= 2;
            }
            int zac = (indeksBita >= p) ? 0 : p-indeksBita;
            int kon = (indeksBita + 7 < q) ? 7 : q-indeksBita-1;
            for (int i = zac; i <= kon; i++) {
                fprintf(stdout, "%d", val[i]);
            }
            if (kon < 7) {
                fputc('\n', stdout);
                fclose(vhod);
                return 0;
            }
        }
        indeksBita += 8;
    }
    fclose(vhod);
    return 0;

}

