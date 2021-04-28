
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "naloga.h"

//1.testni primer
int poisciStudenta(Student** studentje, int stStudentov, int vpisna) {
    for (int i = 0; i < stStudentov; i++) 
        if (studentje[i] -> vpisna == vpisna) 
            return i;
    return -1;
}

//2. testni primer
int poisciPO(Student* student, char* predmet) {
    for (int i = 0; i < student->stPO; i++) 
        if (strcmp(student->po[i].predmet, predmet) == 0)  
            return i;
    return -1;
}

//3-10 testni primer
int dodaj(Student** studentje, int stStudentov, int vpisna, char* predmet, int ocena) {
    int indeks_studenta = poisciStudenta(studentje, stStudentov, vpisna);
    if (indeks_studenta < 0) {
        //Student v tabeli se ni prisoten - usvarimo novo strukturo
        Student* novi_student = malloc(sizeof(Student));
        novi_student->vpisna = vpisna;
        novi_student->stPO = 1;
        novi_student->po = malloc(sizeof(PO) * 10);
        novi_student->po[0].ocena = ocena;
        strcpy(novi_student->po[0].predmet, predmet);
        studentje[stStudentov] = novi_student;
        stStudentov++;
    }
    else {
        Student* student = studentje[indeks_studenta];
        int indeks_predmeta = poisciPO(student, predmet);
        PO* predmeti = student->po;
        if (indeks_predmeta == -1) {
            while (predmeti->ocena != 0) {
                predmeti++;
            }
            predmeti->ocena = ocena;
            strcpy(predmeti->predmet, predmet);
            student->stPO +=1;
        }
        else {
            (predmeti + indeks_predmeta)->ocena = ocena;   
        }
    }
    return stStudentov;
}

int main() {
    return 0;
}
