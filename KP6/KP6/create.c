//
//  create.c
//  KP6
//
//  Created by Денис Фадеев on 4/13/22.
//

#include "repository.h"

int main() {
    FILE *f;
    f = fopen("//Users//denisfadeev//Documents//LabsMAI//KP6//KP6//BD.bin", "wb");
    char surnames[][MAXCHAR] = {"Fadeev", "Jilin", "Mamontova", "Ignatyeva", "Subotina", "Gorohova", "Kirilov", "Sokolov", "Basharov", "Makarov", "Ivanov"};
    char initials[][MAXCHAR] = {"DV", "MD", "PV", "ES", "MS", "DG", "KA", "VV", "DS", "MM", "TO"};
    char sex[][MAXCHAR] = {"M", "W"};
    char group[][MAXCHAR] = {"M103", "M108", "M105"};
    char exam[][MAXCHAR] = {"MATH", "RUS", "HISTORY", "OOP", "TRMH", "JAVA"};
    
    for(int i = 0; i < 11; i++) {
        Student *s = malloc(sizeof(Student));
        strcpy(s->surname, surnames[rand()%11]);
        strcpy(s->initials, initials[rand()%11]);
        strcpy(s->sex, sex[rand()%2]);
        strcpy(s->group, group[rand()%3]);
        int count = rand()%4+1;
        for(int i = 0; i<count; i++) {
            test *t = malloc(sizeof(test));
            strcpy(t->name, exam[rand()%6]);
            t->score = rand()%5;
            add_test_to_student(t, s);
        }
        s->count = count;
        add_student(s, f);
    }
    
    fclose(f);
    
    return 0;
}
