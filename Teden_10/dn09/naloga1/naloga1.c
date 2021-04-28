
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "naloga1.h"

//urejeno po padajocih ocenah, v primeru enakih ocen - po narascujocih vpisnih
VO** opravili(Student** studentje, int stStudentov, char* predmet, int* stVO) {
    *stVO = 0;
    VO** opravili = malloc (sizeof(VO*) * stStudentov);
    for (int i = 0; i < stStudentov; i++) {
        Student* student = studentje[i];
        //printf("____student[%d] = %d____\n", i, student->vpisna);
        for (int j = 0; j < student->stPO; j++) {
            if (strcmp(predmet, student->po[j].predmet) == 0) {
                //printf("predmet_st: %d\n", j);
                int ocena = student->po[j].ocena;
                int vpisna_stevilka = student->vpisna;
                //printf("ocena: %d\n", ocena);
                if (ocena >= 6) {
                    //printf("ocena >= 6\n");
                    //primerjamo z vsemi studenti ze v tabeli
                    int indeks = 0;
                    while (indeks < *stVO && (ocena < opravili[indeks]->ocena
                    || (ocena == opravili[indeks]->ocena && 
                    opravili[indeks]->vpisna < vpisna_stevilka)))
                        indeks++;
                    //printf("opravili_indeks = %d\n", indeks);
                    //printf("st_opravljenih = %d\n", *stVO);
                    for (int i = *stVO; i > indeks; i--) {
                        //printf("[%p] = [%p]\n", opravili[i], opravili[i-1]);
                        opravili[i] = opravili[i-1];
                    }
                    //printf("xd\n");
                    opravili[indeks] = malloc(sizeof(VO));
                    opravili[indeks] -> vpisna = vpisna_stevilka;
                    opravili[indeks] -> ocena = ocena;
                    (*stVO)++;
                }
                break;
            }
        }
        //printf("\n");
    }
    return opravili;
}

int main() {
    //  Student* studentje[] = {
    //     (Student[]) {
    //         555,
    //         (PO[]){{"FIZ", 10}, {"P1", 6}, {"P2", 7}, {"ODV", 5}, {"ARS", 6}},
    //         5
    //     },
    //     (Student[]) {
    //         444,
    //         (PO[]){{"FIZ", 9}, {"P1", 7}, {"P2", 7}, {"ODV", 6}, {"ARS", 7}},
    //         5
    //     },
    //     (Student[]) {
    //         333,
    //         (PO[]){{"FIZ", 8}, {"P1", 8}, {"P2", 7}, {"ODV", 5}, {"ARS", 6}, {"OMA", 10}},
    //         6
    //     },
    //     (Student[]) {
    //         222,
    //         (PO[]){{"FIZ", 7}, {"P1", 9}, {"P2", 7}, {"ODV", 6}, {"ARS", 7}},
    //         5
    //     },
    //     (Student[]) {
    //         111,
    //         (PO[]){{"FIZ", 6}, {"P1", 10}, {"P2", 7}, {"ODV", 5}, {"ARS", 6}},
    //         5
    //     },
    // };
    // int stStudentov = sizeof(studentje) / sizeof(studentje[0]);
    // int st_opravljenih = 0;
    // VO** opravljeni = opravili(studentje, stStudentov, "ARS", &st_opravljenih);
    // //printf("%d \n", st_opravljenih);
    return 0;
}
