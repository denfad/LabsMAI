//
//  modifying.c
//  KP6
//
//  Created by Денис Фадеев on 4/13/22.
//

#include "repository.h"

int main() {
    
    FILE *f;
    f = fopen("//Users//denisfadeev//Documents//LabsMAI//KP6//KP6//BD.bin", "ab");
    
    Student *s = malloc(sizeof(Student));
    bool modifying = true;
    while(modifying) {
        fprintf(stdout, "Enter student surname:\n");
        fscanf(stdin, "%s", s->surname);
        fprintf(stdout, "Enter student initials:\n");
        fscanf(stdin, "%s", s->initials);
        fprintf(stdout, "Enter student sex: M (male) or W (female)\n");
        fscanf(stdin, "%s", s->sex);
        fprintf(stdout, "Enter student group:\n");
        fscanf(stdin, "%s", s->group);
        int count = 0;
        fprintf(stdout, "Enter student`s count of tests:\n");
        fscanf(stdin, "%d", &count);
        s->count = count;
        s->tests = (test**)malloc(sizeof(test*) * count);
        for(int i = 0; i < count; i++) {
            fprintf(stdout, "Test №%d\n", i + 1);
            test *t = malloc(sizeof(test));
            fprintf(stdout, "Enter test name:\n");
            fscanf(stdin, "%s", t->name);
            fprintf(stdout, "Enter test score:\n");
            fscanf(stdin, "%d", &t->score);
            s->tests[i] = t;
        }
        add_student(s, f);
        fprintf(stdout, "Student with surname %s added\n", s->surname);
        fprintf(stdout, "Add new student? (yes or no)\n");
        char str[MAXCHAR];
        fscanf(stdin, "%s", str);
        if(strcmp(str, "no") == 0) modifying = false;
    }
    fprintf(stdout, "End modifiyng table\n");
    fclose(f);
    
    return 0;
}
