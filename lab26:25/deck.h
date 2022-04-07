#ifndef deck_h
#define deck_h
#include <stdio.h>
#include "stdlib.h"
#include <stdbool.h>

typedef struct unit{
    int value;
    struct unit *next;
}unit;

typedef struct {
    unit *left;
    unit *right;
} deck;

deck * deck_create(void);
bool deck_is_empty(deck *d);
void deck_push_front(deck *d, int value);
void deck_push_back(deck *d, int velue);
unit * deck_pop_front(deck *d);
unit * deck_pop_back(deck *d);
unit * deck_find_prev(unit *front, unit *f);
void deck_print(deck *d);
size_t deck_size(deck *d);
deck * deck_sort(deck *d);

#endif
