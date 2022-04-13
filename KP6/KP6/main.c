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
    Student s1 = {"Fadeev", "DV", "M", "M103", NULL};
    test t1 = {"MATH", 5};
    test t2 = {"INFA", 4};
    test t3 = {"RUS", 3};
    add_test_to_student(&t1, &s1);
    add_test_to_student(&t2, &s1);
    add_test_to_student(&t3, &s1);
    add_student(&s1, f);
    Student s2 = {"MIXAIL", "DP", "M", "M102", NULL};
    test t21 = {"MATH", 3};
    test t22 = {"INFA", 5};
    test t23 = {"RUS", 4};
    add_test_to_student(&t21, &s2);
    add_test_to_student(&t22, &s2);
    add_test_to_student(&t23, &s2);
    add_student(&s2, f);
    Student s3 = {"MASHA", "BV", "W", "M105", NULL};
    test t33 = {"RUS", 4};
    test t34 = {"HISTORY", 2};
    add_test_to_student(&t33, &s3);
    add_test_to_student(&t34, &s3);
    add_student(&s3, f);
    Student s5 = {"DASH", "GV", "W", "M108", NULL};
    test t53 = {"OFP", 5};
    test t54 = {"TRMX", 4};
    add_test_to_student(&t53, &s5);
    add_test_to_student(&t54, &s5);
    add_student(&s5, f);
    Student s6 = {"BASH", "GV", "W", "M108", NULL};
    test t63 = {"OFP", 5};
    test t64 = {"TRMX", 5};
    add_test_to_student(&t63, &s6);
    add_test_to_student(&t64, &s6);
    add_student(&s6, f);
    fclose(f);
    
    //вывод
    f = fopen("//Users//denisfadeev//Documents//LabsMAI//KP6//KP6//BD.bin", "rb");
    char p[MAXCHAR] = "";
    bool fflag = false;
    for(int i = 1; i< argc; i++) {
        if(strcmp(argv[i], "-f") == 0) fflag = true;
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
                if(s.tests[i]->score == 5) five_count+=1;
            }
            if(five_count == 1) count+=1;
        }
    }
    fprintf(stdout, "Count of females with one five score in tests or exams: %d\n", count);
   
    
    
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
