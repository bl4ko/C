
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

int ceiling(int dividend, int divisor) {
    int quotient = dividend / divisor;
    return dividend - quotient*divisor > 0 ? quotient + 1 : quotient;
}

int** ap2pp(int(*kazalec)[N], int izvornoStVrstic, int ciljnoStVrstic) {
    int numOfElems = N * izvornoStVrstic;
    int lenNewRow = ceiling(numOfElems, ciljnoStVrstic) + 1;
    int** new2DArr = (int**) malloc (sizeof(int*) * ciljnoStVrstic);
    int index_newRow = 0;
    *(new2DArr+index_newRow) = (int*) malloc (sizeof(int) * lenNewRow);
    int index_column = 0;
    numOfElems -= lenNewRow-1;
    for (int i = 0; i < izvornoStVrstic; i++) {
        int* oldRow = *(kazalec+i);
        for (int j =0; j < N; j++) {
            if (index_column == lenNewRow-1) {
                *(*(new2DArr+index_newRow)+index_column) = 0;
                index_column = 0;
                index_newRow++;
                if (numOfElems >= lenNewRow-1) 
                    *(new2DArr+index_newRow) = (int*) malloc (sizeof(int) * lenNewRow);
                else 
                    *(new2DArr+index_newRow) = (int*) malloc (sizeof(int) * numOfElems+1);
                numOfElems -= lenNewRow-1;
            }
            *(*(new2DArr+index_newRow)+index_column) = *(oldRow+j);
            index_column++;
        }
    }
    *(*(new2DArr+index_newRow)+index_column) = 0;
    return new2DArr;
}

int (*pp2ap(int** kazalec, int izvornoStVrstic, int* ciljnoStVrstic))[N] {
    int numOfElems = 0;
    for (int i = 0; i < izvornoStVrstic; i++) {
        int* oldRow = *(kazalec+i);
        for (int j = 0; *(oldRow+j) != 0; j++)
            numOfElems++;
    }
    *ciljnoStVrstic = ceiling(numOfElems, N);
    int (*newArr)[N] =  malloc (sizeof(int) * N * (*ciljnoStVrstic));
    int index_oldRow = 0;
    int index_oldCol = 0;
    for (int i = 0; i < (*ciljnoStVrstic); i++) {
        for (int j = 0; j < N; j++) {
            if (kazalec[index_oldRow][index_oldCol] == 0) {
                if (index_oldRow == izvornoStVrstic-1) {
                    for (int k = j; k < N; k++)
                        newArr[i][j] = 0;
                    return newArr;
                }
                else 
                    index_oldRow++, index_oldCol = 0;
            }
            newArr[i][j] = kazalec[index_oldRow][index_oldCol];
            index_oldCol++;
        }
    }
    return newArr;
}

int main() {
    return 0;
}
