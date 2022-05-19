//
//  map.c
//  KP9
//
//  Created by Денис Фадеев on 5/13/22.
//

#include "map.h"

void map_sort_xor(map *m, int start, int end) {
    int i = start;
    int j = end;
    int mid = m->units[(start+end)/2]->k;
    
    do {
        while(m->units[i]->k < mid) i++;
        while(m->units[j]->k > mid) j--;
        
        if(i <= j) {
            if (m->units[i]->k > m->units[j]->k) {
                unit *a = m->units[i];
                m->units[i] = m->units[j];
                m->units[j] = a;
            }
            i++;
            j--;
        }
    }while (i <= j);
    
    if( i < end) map_sort_xor(m, i, end);
    if(start < j) map_sort_xor(m, start, j);
}

map * map_create(){
    map *m = malloc(sizeof(map));
    m->max_size = 14;
    m->size = 0;
    m->units = (unit**)malloc(sizeof(unit*) * m->max_size);
    return m;
}

void map_add(map *m, int k, char *v) {
    if(m->size < m->max_size){
        unit *u = malloc(sizeof(unit));
        u->k = k;
        strcpy(u->v, v);
        m->units[m->size] = u;
        m->size++;
    } else {
        printf("Map is full!\n");
    }
}

void map_sort(map *m) {
    map_sort_xor(m, 0, m->size-1);
}

void map_generate(map *m) {
    char surnames[][MAXLEN] = {"Fadeev", "Jilin", "Mamontova", "Ignatyeva", "Subotina", "Gorohova", "Kirilov", "Sokolov", "Basharov", "Makarov", "Ivanov"};
    for(int i = 0; i<m->max_size; i++) {
        map_add(m, rand()%100, surnames[rand()%11]);
    }
}

void map_print(map *m) {
    printf("| ");
    for(int i = 0; i < m->size; i++) printf("%d: %s | ", m->units[i]->k, m->units[i]->v);
    printf("\n");
}
