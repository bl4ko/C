#include <stdio.h> //enako kot import

int main () {
    //beremo celo pozitivno stevilo znak po znak
    int n = 0;
    int c;
    do {
        c = getchar(); // vrne Ascii codo naslednjega znaka iz vhoda 
        switch(c) {
            case 48: n = n * 10 + 0; break;
            case 49: n = n * 10 + 1; break;
            case 50: n = n * 10 + 2; break;
            case 51: n = n * 10 + 3; break;
            case 52: n = n * 10 + 4; break;
            case 53: n = n * 10 + 5; break;
            case 54: n = n * 10 + 6; break;
            case 55: n = n * 10 + 7; break;
            case 56: n = n * 10 + 8; break;
            case 57: n = n * 10 + 9; break;
            case '\n': break;
            default:
                printf ("NAPAKA\n");
                return 1;
        }       
    } while (c != '\n');
    printf("%d\n", n);
    return 0;
}