//
//  map.h
//  KP9
//
//  Created by Денис Фадеев on 5/13/22.
//

#ifndef map_h
#define map_h

#include <stdio.h>
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"

#define MAXLEN 1024

typedef struct unit {
    int k;
    char v[MAXLEN];
}unit;

typedef struct map{
    int max_size;
    int size;
    struct unit **units;
}map;

map * map_create();
void map_add(map *m, int k, char *v);
void map_sort(map *m);
void map_generate(map *m);
void map_print(map *m);



#endif /* map_h */
