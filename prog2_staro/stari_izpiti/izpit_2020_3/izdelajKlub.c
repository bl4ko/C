#include <stdio.h>
#include <stdlib.h>

typedef struct _Klub {
    char* ime;
    int stClanov;
    char** imenaClanov;
} Klub;

Klub* izdelaj() {
    Klub* klub = malloc(sizeof(Klub));
    char* imeKluba = malloc(sizeof(21));
    fscanf(stdin, "%s", imeKluba);
    klub->ime = imeKluba;
    int n; fscanf(stdin, "%d", &n);
    klub -> stClanov = n;
    klub -> imenaClanov = malloc(sizeof(char*)*n);
    for (int i = 0; i < n; i++) {
        char* ime = malloc(sizeof(char)*21);
        fscanf(stdin, "%s", ime);
        (klub->imenaClanov)[i]=ime;
    }
    return klub;
}

int main() {
    Klub* novi = izdelaj();
    printf("ime: %s\nstClanov: %d\n", novi-> ime, novi-> stClanov);
    printf("clani: ");
    for (int i = 0; i < novi->stClanov; i++) {
        printf("[%d]=%s ",i+1, (novi->imenaClanov)[i]);
    }
    putchar('\n');
    free(novi);
    return 0;
}