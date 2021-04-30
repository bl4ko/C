#include <stdio.h> 

int main()
{
    //int <-- getchar(void) --> get unsigned char from stdin
    int a = getchar() - '0'; //npr 51 - 48
    getchar(); //preberemo presledek
    int b = getchar() - '0';

    int vsota = (a + b) % 10;

    // int putchar(int char) --> vrne zapisan znak kot unsigned char || EOF
    putchar(vsota + '0');
    putchar('\n');
    return 0;
}
