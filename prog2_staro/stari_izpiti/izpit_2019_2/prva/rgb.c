#include <stdio.h>
#include <stdlib.h>

int main() {
    char* ime = malloc(sizeof(char)*21);
    scanf("%s", ime);
    FILE* vhod = fopen(ime, "rb");
    int n; scanf("%d", &n);
    scanf("%s", ime);
    FILE* izhod = fopen(ime, "w");
    int vrednosti[3] = {0, 0, 0};
    for (int i = 0; i < n; i++) {
        unsigned char bajti[3];
        fread(bajti, sizeof(unsigned char), 3, vhod);
        if (bajti[0] > 0 && bajti[1] == 0 && bajti[2] == 0)
            vrednosti[0]++;
        else if (bajti[0] == 0 && bajti[1] > 0 && bajti[2] == 0) {
            vrednosti[1]++;
        }
        else if (bajti[0] == 0 && bajti[1] == 0 && bajti[2] > 0) {
            vrednosti[2]++;
        }
    }
    for (int i = 0; i < 3; i++) {
        printf("%d\n", vrednosti[i]);
    }
    free(ime);
    fclose(vhod);
    fclose(izhod);
    return 0;
}