#include <stdio.h>

int main() 
{   
    FILE* output = fopen("output.txt", "w");
    static char stavek[50] = "Danes ni moj dan, niti vceraj ni bil!\n";
    fputs(stavek, output);    // na izhod zapisemo A
    fputs(stavek, stdout);    // na zaslon izpisemo A
    fputs("NAPAKA: pojdi se stusirat!\n", stderr);
}
