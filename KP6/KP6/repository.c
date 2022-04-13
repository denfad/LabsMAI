//
//  repository.c
//  KP6
//
//  Created by Денис Фадеев on 4/12/22.
//

#include "repository.h"

int str_write(char *s, FILE *f) {
    if(fwrite(s, sizeof(s[0]), MAXCHAR, f) != MAXCHAR) {
        printf("ERROR");
        return 1;
    }
    return 0;
}

int int_write(int *i, FILE *f) {
    if(fwrite(i, sizeof(int), 1, f) != 1) {
        printf("ERROR");
        return 1;
    }
    return 0;
}

int str_read(char *s, FILE *f) {
    if(fread(s, sizeof(s[0]), MAXCHAR, f) != MAXCHAR) {
        return 1;
    }
    return 0;
}

int int_read(int *i, FILE *f) {
    if(fread(i, sizeof(*i), 1, f) != 1) {
        return 1;
    }
    return 0;
}

int add_student(Student *s, FILE *f) {
    int i = 0;
    i += str_write(s->surname, f);
    i += str_write(s->initials, f);
    i += str_write(s->sex, f);
    i += str_write(s->group, f);
    if(s->tests != NULL) {
        for(int j = 0; j < s->count; j++) {
            i+=add_test(s->tests[j], f);
        }
    }
    char str[MAXCHAR] = ";";
    i += str_write(str, f);
    if (i > 0) return 1;
    else return 0;
}

int add_test(test *t, FILE *f) {
    int i = 0;
    i += str_write(t -> name, f);
    i += int_write(&t -> score, f);
    if (i > 0) return 1;
    else return 0;
}

int get_student(Student *s, FILE *f) {
    int i = 0;
    i += str_read(s->surname, f);
    i += str_read(s->initials, f);
    i += str_read(s->sex, f);
    i += str_read(s->group, f);
    int j = 0;

    test *t = malloc(sizeof(test));
    s->tests = NULL;
    while(get_test(t, f) != 1) {
        if(j == 0) s->tests = (test**) malloc(sizeof(test*));
        else s->tests = (test**) realloc(s->tests, sizeof(test*) * (j + 1));
        test *k = malloc(sizeof(test));
        strcpy(k->name,t->name);
        k->score = t->score;
        s->tests[j] = k;
        j++;
        s->count = j;
    }
    if (i > 0) return 1;
    else return 0;
}

int get_test(test *t, FILE *f) {
    int i = 0;
    char str[MAXCHAR] = "";
    i += str_read(str, f);
    if(strcmp(str, ";") == 0) return 1;
    else {
        strcpy(t->name, str);
        i += int_read(&t->score, f);
    }
    if (i > 0) return 1;
    else return 0;
}

void add_test_to_student(test *t, Student *s) {
    if(s -> tests == NULL) {
        s->tests = (test**) malloc(sizeof(test*));
        s->tests[0] = t;
        s->count = 1;
    }
    else  {
        s->tests = (test **) realloc(s->tests, sizeof(test *) * (s->count + 1));
        s->tests[s->count] = t;
        s->count += 1;
    }
   
}



