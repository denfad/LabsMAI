//
//  repository.h
//  KP6
//
//  Created by Денис Фадеев on 4/12/22.
//

#ifndef repository_h
#define repository_h
#include <stdio.h>
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"
#define MAXCHAR 128

typedef struct test {
    char name[MAXCHAR];
    int score;
}test;

typedef struct Student{
    char surname[MAXCHAR];
    char initials[MAXCHAR];
    char sex[MAXCHAR];
    char group[MAXCHAR];
    struct test ** tests;
    int count;
}Student;

int str_write(char * s, FILE *f);
int int_write(int * i, FILE *f);
int str_read(char * s, FILE *f);
int int_read(int *i, FILE *f);
int add_student(Student *s, FILE *f);
int add_test(test*t, FILE *f);
int get_student(Student *s, FILE *f);
int get_test(test *t, FILE *f);
void add_test_to_student(test *t, Student *s);

#endif /* repository_h */
