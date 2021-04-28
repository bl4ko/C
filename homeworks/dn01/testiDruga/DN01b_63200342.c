#include <stdio.h>
#include <stdbool.h>

void rekurzija(int st){
    int temp = 0;
    if(st > 9){
        temp = st % 10;
        rekurzija(st/10);
    }else{
        temp = st;
    }
    putchar(temp + '0');
    return;
}

int main(){

    bool enica = false;
    int input = getchar();
    int counter = 0;
    while(input != '\n'){
        if(input == '1')
            enica = true;
        if(enica)
            counter++;
        input = getchar();
    }
    rekurzija(counter);
    putchar('\n');
    return 0;
}