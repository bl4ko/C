#include <stdio.h>
#include <stdlib.h>

// not working properly rip

int main() {
    int n; scanf("%d", &n);
    char* zaporedje = malloc(sizeof(char)*(n+1));
    scanf("%s", zaporedje);

    // poiscemo najvisjo dosezeno visino
    int maxHeight = 0;
    int height = 0;
    for (int i = 0; i < n; i++) {
        height = zaporedje[i] == 'G' ? height+1 : height-1;
        if (height > maxHeight) maxHeight = height;
    }

    char** izhod = malloc(sizeof(char*)*n);
    height = maxHeight-1; //reverse picutre
    for (int i = 0; i < n; i++) {
        char* level = malloc(sizeof(char)*maxHeight);
        for (int j = 0; j < maxHeight; j++) {
            if (j == height) 
                level[j] = zaporedje[i] == 'G' ? '/' : '.';
                if (level[j] == '.') {
                    level[j+1] = '\\';
                    j++;
                }
            else 
                level[j] = '.';
        }
        izhod[i] = level;
        height = zaporedje[i] == 'G' ? height-1 : height+1;
    }

    for (int i = 0; i < maxHeight; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c", izhod[j][i]);
            if (i == maxHeight-1) {
                free(izhod[j]);
            }
        }
        putchar('\n');
    }
}