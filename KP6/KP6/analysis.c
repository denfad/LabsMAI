//
//  analysis.c
//  KP6
//
//  Created by Денис Фадеев on 4/13/22.
//

#include "repository.h"

void print_student(Student *s) {
    fprintf(stdout, "+---------------+--------+---+----------+");
    if(s->tests != NULL) {
    for(int i = 0; i < s->count; i++) {
        for(int j = 0; j < strlen(s->tests[i]->name); j++) fprintf(stdout, "-");
        fprintf(stdout, "--+");
    }
    }
    fprintf(stdout, "\n");
    fprintf(stdout, "|%-15s|   %c.%c  | %s |%-10s|", s->surname, s->initials[0], s->initials[1], s->sex, s->group);
    if(s->tests != NULL) {
    for(int i = 0; i < s->count; i++) fprintf(stdout, "%s %d|", s->tests[i]->name, s->tests[i]->score);
    }
    fprintf(stdout, "\n");
    fprintf(stdout, "+---------------+--------+---+----------+");
    if(s->tests != NULL) {
    for(int i = 0; i < s->count; i++) {
        for(int j = 0; j < strlen(s->tests[i]->name); j++) fprintf(stdout, "-");
        fprintf(stdout, "--+");
    }
        fprintf(stdout, "\n");
    }
}

int main(int argc, const char * argv[]) {

    FILE *f;
    
    f = fopen("//Users//denisfadeev//Documents//LabsMAI//KP6//KP6//BD.bin", "rb");
    char p[MAXCHAR] = "";
    bool fflag = false;
    for(int i = 1; i< argc; i++) {
        if(strcmp(argv[i], "-f") == 0) {
            fprintf(stdout, "+---------------+--------+---+----------+-----\n");
            fprintf(stdout, "|    Surname    |initials|sex|  group   |exams\n");
            fflag = true;
        }
        if(strcmp(argv[i], "-p") == 0) {
            strcpy(p, argv[i+1]);
            i++;
        }
    }
    Student s;
    int count = 0;
    while(get_student(&s, f) == 0) {
        if(strcmp(s.sex, "W") == 0 && strcmp(s.group, p) == 0) {
            int five_count = 0;
            for(int i = 0; i < s.count; i ++) {
                if(s.tests[i]->score == 5) {
                    five_count+=1;
                }
            }
            if(five_count == 1) {
                count+=1;
                if(fflag) print_student(&s);
            }
        }
    }
    fprintf(stdout, "Count of females with one five score in tests or exams: %d\n", count);
    fclose(f);
    return 0;
}

