stack - malo prostora
heap - veliko prostora    .... dinamicni  
stat = veliko prostora    .... staticni


2 DIMENSION VS 1 DIMENSION
int *a; a je kazaledc na int, *a je int
a[5] = *(a + 5)
        int* 5*sizeof(int)
        a vsebuje naslov
        a + 5*sizeof(int) je naslov
        *(a+5) kar je na naslovu a[5]

int **b, b je kazalaec na kazalec na int
        *b je kazalec na int
       **b je int 
