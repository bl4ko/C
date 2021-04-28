#include <stdio.h>
#include <stdbool.h>

bool preveri(int c, int a, int b) 
{   
    bool preverjeno = (c == ' ' || c == EOF || c == '\n') ? false : true;
    while (c != ' ' && c != EOF && c != '\n') {
        if ((c < a || c > b) || (c>= 58 && c<= 64)) {
            preverjeno = false;
        }
        c = getchar();
    }
    return preverjeno;
}

int main() 
{   
    int stevec = 0;
    int c;
    while ((c=getchar()) != EOF) {
        stevec += 1;
        bool stevilo = true;
        if (c == '0') {
            switch (c = getchar()) {
                case 'b':
                    stevilo = preveri(c=getchar(),'0','1');
                    break;
                case 'x':
                    stevilo = preveri(c=getchar(),'0','F');
                    break;
                default:
                    stevilo = (c== ' ' || c == '\n') ? true : preveri(c, '0', '7');
            }
        }
        else {
            stevilo = preveri(c, 48, 57);
        }
        putchar(stevilo ? 49 : 48);
    }
    putchar('\n');
    return 0;
}