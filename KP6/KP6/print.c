//
//  print.c
//  KP6
//
//  Created by Денис Фадеев on 4/13/22.
//

#include "repository.h"

int main() {
    
    FILE *f;
    
    f = fopen("//Users//denisfadeev//Documents//LabsMAI//KP6//KP6//BD.bin", "rb");
    fprintf(stdout, "+---------------+--------+---+----------+-----\n");
    fprintf(stdout, "|    Surname    |initials|sex|  group   |exams\n");
    Student s;
    while (get_student(&s, f) == 0) {
        fprintf(stdout, "+---------------+--------+---+----------+");
        if(s.tests != NULL) {
        for(int i = 0; i < s.count; i++) {
            for(int j = 0; j < strlen(s.tests[i]->name); j++) fprintf(stdout, "-");
            fprintf(stdout, "--+");
        }
        }
        fprintf(stdout, "\n");
        fprintf(stdout, "|%-15s|   %c.%c  | %s |%-10s|", s.surname, s.initials[0], s.initials[1], s.sex, s.group);
        if(s.tests != NULL) {
        for(int i = 0; i < s.count; i++) fprintf(stdout, "%s %d|", s.tests[i]->name, s.tests[i]->score);
        }
        fprintf(stdout, "\n");
            fprintf(stdout, "+---------------+--------+---+----------+");
        if(s.tests != NULL) {
        for(int i = 0; i < s.count; i++) {
            for(int j = 0; j < strlen(s.tests[i]->name); j++) fprintf(stdout, "-");
            fprintf(stdout, "--+");
        }
            fprintf(stdout, "\n");
        }
    }
    
   
    
    return 0;
}
