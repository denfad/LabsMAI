//
//  main.c
//  KP6
//
//  Created by Денис Фадеев on 4/12/22.
//

#include "repository.h"


int main(int argc, const char * argv[]) {
    // insert code here...,
    printf("Hello, World!\n");
    
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
 
   
    
    
    f = fopen("//Users//denisfadeev//Documents//LabsMAI//KP6//KP6//BD.bin", "rb");
    fprintf(stdout, "+---------------+--------+---+----------+-----\n");
    fprintf(stdout, "|    Surname    |initials|sex|  group   |exams\n");
    Student s8;
    while (get_student(&s8, f) == 0) {
        fprintf(stdout, "+---------------+--------+---+----------+");
        if(s8.tests != NULL) {
        for(int i = 0; i < s8.count; i++) {
            for(int j = 0; j < strlen(s8.tests[i]->name); j++) fprintf(stdout, "-");
            fprintf(stdout, "--+");
        }
        }
        fprintf(stdout, "\n");
        fprintf(stdout, "|%-15s|   %c.%c  | %s |%-10s|", s8.surname, s8.initials[0], s8.initials[1], s8.sex, s8.group);
        if(s8.tests != NULL) {
        for(int i = 0; i < s8.count; i++) fprintf(stdout, "%s %d|", s8.tests[i]->name, s8.tests[i]->score);
        }
        fprintf(stdout, "\n");
            fprintf(stdout, "+---------------+--------+---+----------+");
        if(s8.tests != NULL) {
        for(int i = 0; i < s8.count; i++) {
            for(int j = 0; j < strlen(s8.tests[i]->name); j++) fprintf(stdout, "-");
            fprintf(stdout, "--+");
        }
            fprintf(stdout, "\n");
        }
    }
    fclose(f);
    
   
    
    return 0;
}
