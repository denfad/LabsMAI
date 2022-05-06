//
//  list.h
//  KP8
//
//  Created by Денис Фадеев on 5/4/22.
//

#ifndef list_h
#define list_h

#include <stdio.h>
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"

#define MAXLEN 256
//специальное задание 8
//тип строка
//двусвязный список с границей

typedef struct unit {
    char value[MAXLEN];
    struct unit *next;
    struct unit *prev;
}unit;

typedef struct list {
    struct unit *border;
}list;

list * create_list();
void add_list(list * l, char *value);
void delete_list(list *l, char *value);
int len_list(list *l);
void expand_list(list *l, char *value, int k);
void print_list(list *l);

#endif
