// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// struct _person
// {
//     char name[100]; //komponenti struktue
//     int age;
// };

// typedef struct _person person; //_person lahko nadomestim z person
// //tako kot
// typedef int integer;
// typedef char character;

// struct person2 
// {
//     char name[100];
//     int age;
//     int height;
// };

// void print_person(struct _person p) 
// {   
//     p.age = p.age + 2;
//     printf("{ %s %d }\n", p.name, p.age);
// }

// void print_person2(struct _person *p) 
// {   
//     p->age = p->age + 2;
//     printf("{ %s %d }\n", p->name, p->age);
// }

// // struct_person p1 = {"Janez", 20};
// person p1 = {"Janez", 20};  // struct person je ime tipa (tako kot int, definiramo ga sami zgoraj)
// struct person *p2;
// struct person *p;

// int main()
// {   
//     //lahko shranimo tudi na skladu (moramo paziti da jih ne prevec saj zavzame veliko prostora)
//     struct person p3 = {"Jaka, 55"};

//     p2 = (struct person*) malloc (sizeof (struct person));  //na heapu
//     strcpy (p2->name, "Marko"); p2->age=21;


//     printf("%lu\n", sizeof(struct person)); //104 = 100 * 1 (sizeof(char)) + 4 (sizeof(int))

//     printf("[%s] %d\n", p1.name, p1.age);
//     printf("[%s] %d\n", p2->name, p2->age);

//     p = &p1;
//     printf("Naslov kazalec = %p\n", &p1);
//     printf("[%s] %d\n", (*p).name, (*p).age);
//     p = p2;
//     printf("[%s] %d\n", p->name, p->age);

//     // p1 = *p2;
//     // //memcpy(&p1, p2, sizeof(struct person));  // <-- GRDO - tega ne delamo
//     // printf("-> [%s] %d\n", p1.name, p1.age);

//     //strukturo posiljamo po vrednosti - vec prepisovanja po pomnilniku, vecja poraba sklada
//     print_person(p1);
//     print_person(*p2);

//     //naslov posiljamo po vrednosti, strukturo pa po referenci
//     print_person2(&p1); 
//     print_person2(p2);

//     free(p2);

//     return 0;
// }