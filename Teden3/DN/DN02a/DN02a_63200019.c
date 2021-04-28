#include <stdio.h>
#include <stdbool.h>

int main() {
    int c;
    //int stevec = 0;
    while ((c=getchar()) != EOF) {
        //stevec += 1;
        //printf("stevec:%d ", stevec);
        bool stevilo = true;
        if (c == '-' || c == '+') {
            c = getchar();
            //printf(" predznak ");
            if (c == ' ' || c == '\n' || c == EOF) 
               stevilo = false; 
        }
        bool nic = (c=='0') ? true : false;
        if (nic) c = getchar();
        while (c != ' ' &&  c != '\n') {
            if (c < '0' || c > '9' || nic)
                stevilo = false;
            c = getchar();
            //printf(" c:%d ", c);
        }
        //printf("[out:");
        putchar(stevilo ? 49 : 48);
        //printf("]\n");

    }
    putchar('\n');
    return 0;
}