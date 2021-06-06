#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// unfinished business :(((

char* sprehod(int i, int j, int** memo, int** matrika, int maxI, int maxJ, char* pot) {
    if (memo[vrstica][stolpec] != -1) // v temu polju smo ze bili
        return NULL;
    else 
        memo[vrstica][stolpec] = 0; // novo polje oznacimo
    if (i == maxI && j == maxJ) // konec labirinta
        return pot;

    // preverimo vse moznosti
    int moznosti = matrika[i][j];
    for (int smer = 0; smer < 4; smer++, moznosti\=2) {
        if (moznosti % 2 == 0) {
            char* tempPot = malloc(sizeof(char)*(maxI+1)*(maxJ+1));
            strcpy(tempPot, pot);
            char* moznaPot = sprehod( 
        }
    }
}

int main(int argc, char** argv) {
    FILE* vhod = fopen(argv[1], "r");
    int numRow; fscanf(vhod, "%d", &numRow);
    int numCol; fscanf(vhod, "%d", &numCol);

    int** matrika = malloc(sizeof(int*) * numRow);
    int** memo = malloc(sizeof(int*) * numRow);

    for (int i = 0; i < numRow; i++) {
        int* memoLine = malloc(sizeof(int) * numCol); 
        int* vrstica = malloc(sizeof(int) * numCol);
        matrika[i] = vrstica;
        memo[i] = memoLine;
        for (int j = 0; j < numCol; j++) {
            fscanf(vhod, "%d", &vrstica[j]);
            memo[i][j] = -1;
        }
    }
    for (int i = 0; i < numRow; i++, putchar('\n')) {
        for (int j = 0; j < numCol; j++, putchar(' ')) {
            printf("{%d,%d}", matrika[i][j], memo[i][j]);
        }
    }
    //char* pot = malloc(sizeof(char)*numRow*numCol);
    //printf("%s\n", sprehod(0, 0, memo, matrika, numRow-1, numCol-1, pot));
    //free(pot);
    for (int i = numRow-1; i >= 0; i--) {
        free(memo[i]);
        free(matrika[i]);
    }
    return 0;
}

