#include <stdio.h>
#include <stdlib.h>

typedef struct _Vozlisce {
    int val;
    struct _Vozlisce* next;
} Vozlisce;

Vozlisce* prepisi(int* t) {
    if (t == NULL || t[0] == 0) {
        return NULL;
    }
    Vozlisce* zacetek = malloc(sizeof(Vozlisce));
    zacetek -> val = t[0];
    Vozlisce* prejsne = zacetek;
    for (int i = 1; t[i] != 0; i++) {
        Vozlisce* novo = malloc(sizeof(Vozlisce));
        novo -> val = t[i];
        prejsne -> next = novo;
        prejsne = novo;
    }
    prejsne->next = NULL;
    return zacetek;
}

int main() {
    int t[10] = {1, 2, 3, 0, 5, 6, 7, 8, 9, 0};
    //izpis verige
    
    Vozlisce* zacetek = prepisi(t);
    while (zacetek != NULL) {
        printf("[%d]-->", zacetek->val);
        zacetek = zacetek -> next;
    }
    printf("%p", zacetek);
}