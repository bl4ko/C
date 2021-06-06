#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool logic(char* izraz, int ind) {
    char operator = izraz[ind];
    if (operator == 'T' || operator == 'F') {
        return operator == 'T' ? true : false;
    }
    if (operator == '!')
        return !logic(izraz,ind+1);

    // ind2 indeks drugega izraza
    int ind2 = ind+1;
    for (;izraz[ind2] != 'T' && izraz[ind2] != 'F'; ind2++);
    ind2+=1;
    switch (operator) {
        case '|':
            return logic(izraz,ind+1) || logic(izraz,ind2);
        case '&':
            return logic(izraz,ind+1) && logic (izraz,ind2);
    }
}

int main() {
    char* izraz = malloc(sizeof(char)*1001);
    scanf("%s", izraz);
    printf("%c\n", logic(izraz, 0) ? 'T' : 'F');
    free(izraz);
    return 0;
}