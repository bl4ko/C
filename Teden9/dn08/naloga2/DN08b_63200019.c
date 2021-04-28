#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool crniZmaga = false;
bool beliMoznost = false;

bool min(int a, int b) {
    return a > b ? b : a;
}

void rekurzija(int n, int k, bool poteza) {
    if (crniZmaga)
        return;
    if (n == 0) {
        if (poteza) 
            crniZmaga = true;
        return;
    }
    for (int i = 1; i <= min(n,k); i++)
        rekurzija(n-i,k,!poteza);
}

void print_rekurzija(int n, int k, int *arr);

int main()
{   
    
    int n; scanf("%d",&n);
    int k; scanf("%d",&k);
    
    for (int i = 1; i <= k; i++) {
        crniZmaga = false;
        rekurzija(n-i,k,false);
        if (!crniZmaga) {
            beliMoznost = true;
            int* arr = calloc(n-i, sizeof(int));
            printf("%d ", i);

        }
    }
    
    if (!beliMoznost)
        printf("CRNI");
    return 0;
}