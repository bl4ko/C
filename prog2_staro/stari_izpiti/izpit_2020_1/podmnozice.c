#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


void podmnozice(int* stevila, bool* t, int i, int len) {
    if (i == len) {
        bool prvi = true;
        printf("{");
        for (int j = 0; j  < len; j++) {
            if (t[j]) {
                if (prvi) {
                    printf("%d", stevila[j]);
                    prvi = false;
                }
                else {
                    printf(", %d", stevila[j]);
                }
            }
        }
        printf("}\n");
        return;
    }
    t[i] = true;
    podmnozice(stevila, t, i+1, len);
    t[i] = false;
    podmnozice(stevila, t, i+1, len);
}

void podmnoziceIterativno(int* stevila, int n) 
{   
    int numNums = (int) pow(2, n);
    for (int i = 0; i < numNums; i++) {
        printf("{");
        int vrednost = i;
        bool prva = true;
        for (int j = 0; j < n; j++) {
            if ((vrednost % 2) == 1) {
                printf("%s%d", prva ? "" : ", ", stevila[j]);
                if (prva) prva = false;
            }
            vrednost /= 2;
        }
        printf("}\n");
    }
}

int main() {
    int n; scanf("%d", &n);
    int* t = malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }
    bool* vsebovane = malloc(sizeof(bool)*n);
    podmnozice(t, vsebovane, 0, n);
    printf("\n\n\n\n");
    podmnoziceIterativno(t, n);

    free(t);
    free(vsebovane); 
    return 0;
}