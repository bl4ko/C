
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

char* cleanUP[10000];
int ind = 0;

int izpisiA(A* a, char* cilj);
char* izpisiB(B* b);
char* izpisiC(C* c);
char* izpisiA2(A* a);

int izpisiA(A* a, char* cilj) {
    if (a == NULL) {
        strcpy(cilj, "NULL");
        return 4;
    }
    int dolzina = sprintf(cilj, "{%d, %s}", a->p, izpisiB(a->b));
    for (int i = 0; cleanUP[i] != NULL; i++) {
        //printf("M[%p] = %s\n", cleanUP[i], cleanUP[i]);
        free(cleanUP[i]);
        //printf("M[%p] = %s\n", cleanUP[i], cleanUP[i]);
    }
    return dolzina;
}

char* izpisiA2(A* a) {
    if (a == NULL) {
        char* temp = malloc(sizeof(char)*5);
        strcpy(temp, "NULL");
        cleanUP[ind] = temp;
        ind+=1;
        return temp;
    }   
    char* temp = malloc(sizeof(char) * 10000);
    cleanUP[ind] = temp;
    ind+=1;
    sprintf(temp, "{%d, %s}", a->p, izpisiB(a->b));
    return temp;
}

char* izpisiB(B* b) {
    if (b == NULL) {
        char* temp = malloc(sizeof(char)*5);
        strcpy(temp, "NULL");
        cleanUP[ind] = temp;
        ind+=1;
        return temp;
    }
    char* temp = malloc(sizeof(char) * 10000);
    cleanUP[ind] = temp;
    ind+=1;
    sprintf(temp, "{%s, %s}", b->q, izpisiC(b->c));
    return temp;
}

char* izpisiC(C* c) {
    if (c == NULL) {
        char* temp = malloc(sizeof(char)*5);
        cleanUP[ind] = temp;
        ind+=1;
        strcpy(temp, "NULL");
        return temp;
        }
    char* temp = malloc(sizeof(char) * 10000);
    cleanUP[ind] = temp;
    ind+=1;
    sprintf(temp, "{%s, %s, %s}", c->r ? "true" : "false", izpisiA2(c->a), izpisiB(c->b));
    return temp;
}
    
int main() {
    return 0;
}
