#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// <3 fuerst

int main() {
    char* vhod = malloc(sizeof(char)*1001);
    scanf("%s", vhod);
    int* levels = malloc(sizeof(int)*334); // 334 max num of (
    int level = 0;
    int maxLevel = 0;
    int maxVal = 0;
    int len = strlen(vhod);
    for (int i = 0; i < len; i++) {
        if (vhod[i] == '(') {
            level++;
            if (level > maxLevel) maxLevel = level;
        }
        else if (vhod[i] == ')') {
            level--;
        }
        else if (vhod[i] == ',') {
            levels[level] += 1;
            if (levels[level] > maxVal) maxVal = levels[level];
        }
    }
    printf("%d\n", maxVal+1);
    free(vhod);
    free(levels);
    return 0;
}