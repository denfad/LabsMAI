//
//  vector.h
//  KP7
//
//  Created by Денис Фадеев on 4/27/22.
//

#ifndef vector_h
#define vector_h

#include <stdio.h>
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"

#define MAXNUM 15

typedef struct vector {
    double value;
    struct vector *next;
    struct vector *prev;
}vector;

vector * create_vector();
vector * create_from_file(FILE *f);
void add_unit(vector *v, int row, int column, double value);
void add_unit_to_start(vector *v, vector *start);
vector * find_row_start(vector *v, int row);
void print_normal(vector *v);
void print_sch(vector *v);
vector * trans(vector *v);
bool is_cososim(vector *v);


#endif /* vector_h */
