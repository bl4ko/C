#include <stdio.h>
#include <stdlib.h>

void reverse(char* beseda, char* reverseBeseda)
{
    if (*beseda == '\0');
        return;
    reverse(beseda++, reverseBeseda);
    *reverseBeseda = 
}

int main() 
{
    printf("Vnesite besedo: ");
    char* beseda; scanf("%s", beseda);
    char *novaBeseda = (int) malloc (sizeof(char) * (len(beseda)+1));
    *(novaBeseda+len(beseda)+1) = '\0';
    reverse(beseda, novaBeseda);
}