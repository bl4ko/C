#include <stdio.h>

int y = 200;
int a[10] = {0,1,2,3,4,5,6,7,8,9};
int x = 100;


int main()
{
    for (int i = 0; i < 10; i++) {
        printf("%d\n", a[i]);
    }

    int *p = a; // = &a[0]

    printf("a[0]=%d\n", *p);
    printf("a[1]=%d\n", p[1]); //cudasko
    printf("%p\n", p);
    p++; //povecaj p za velikost podatka na katerega p kaze
    printf("a[-1]=%d\n", p[-1]); //GRDO
    printf("a[0]=%d\n", *p);
    printf("a[1]=%d\n", p[1]);
    printf("p=%p\n", p);

    p = p + 1; //p = p + 1 * sizeof(int)  ker je p kazalec na int
    printf("a[-1]=%d\n", p[-1]); //GRDO
    printf("a[0]=%d\n", *p);
    printf("a[1]=%d\n", p[1]);
    printf("p=%p\n", p);

    int *b = &(a[0]);
    b[0] = 100;
    b[1] = 200;
    b[2] = 300;
    *(b+3) = 400; //b[3] = 400; //GRDO
    *(4 + b) = 500; //ZELO GRDO
    5[b] = 600; //ZELO ZELO GRDO
    (2 * 3)[b] =  700; //ZELO ZELO ZELO GRDO!!!

    for (int i = 0; i < 10; i++) {
        printf("%d\n", a[i]);
    }

    //Vidimo da C zlozi spremenljivke v static delu skupaj
    printf("a[10]=%d\n", a[10]); //lahko dobimo vrednost x in y, (static del pomnilnika), so zlozene skupaj
    printf("&a[10]=%p, &x=%p\n", &a[10], &x);
    a[10] = 300;
    printf("x = %d\n", x);

    //same shit different day
    int *c = &(a[0]);
    printf("a[10]=%d\n", c[10]); //x je zraven tabele v pomnilniku
    printf("x=%d\n", x);
    c[10] = 300;
    printf("x = %d\n", x);

    c--;
    printf("c[0]=%d\n", c[0]); 
    printf("c[1]=a[0]=%d\n", c[1]);
    printf("c[12]=%d\n", c[12]); 

    printf("&x = %p, &c[0] = %p\n", &x, c);
    
    return 0;
}