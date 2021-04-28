#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void rekurzija(char** besede, int nivo, int n, char* memo) 
{   
    if (nivo == n) {
        printf("%s\n", memo);
        return;
    }
    for (int i = 0; i < strlen(besede[nivo]); i++) {
        memo[nivo] = besede[nivo][i];
        rekurzija(besede, nivo+1, n, memo);
    }
}   

int main()
{  
    int n; scanf("%d", &n);
    char** besede = malloc (n * sizeof(char*)); 
    for (int i = 0; i < n; i++) {
        char* temp = calloc (42, sizeof(char));
        scanf("%s", temp);
        besede[i] = temp;
    }
    char* trenutna_beseda = calloc(42, sizeof(char));
    rekurzija(besede, 0, n, trenutna_beseda);
}