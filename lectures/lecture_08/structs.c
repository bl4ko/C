#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char name[100]; //komponenti struktue
    int age;
} person;

//typedef int integer;
//typedef char character;

struct person2 
{
    char name[100];
    int age;
    int height;
};

void print_person(person p) 
{   
    printf("{ %s %d }\n", p.name, p.age);
}

void print_person2(person *p) 
{   
    p -> age = p->age + 2;
    printf("{ %s %d }\n", p->name, p->age);
}


person p1 = {"Janez", 20}; 
person *p2;
person *p;

int main()
{   
    person p3 = {"Jaka", 55};

    p2 = (person*) malloc (sizeof (person));  
    strcpy (p2->name, "Marko"); p2 -> age=21;


    printf("%lu\n", sizeof(person)); //104 = 100 * 1 (sizeof(char)) + 4 (sizeof(int))

    printf("[%s] %d\n", p1.name, p1.age);
    printf("[%s] %d\n", p2->name, p2->age);

    p = &p1;
    printf("Naslov kazalec = %p\n", &p1);
    printf("[%s] %d\n", (*p).name, (*p).age);
    p = p2;
    printf("[%s] %d\n", p->name, p->age);

    print_person(p1);
    print_person(*p2);

    print_person2(&p1); 
    print_person2(p2);

    free(p2);

    return 0;
}