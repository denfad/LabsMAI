//
//  vector.c
//  KP7
//
//  Created by Денис Фадеев on 4/27/22.
//

#include "vector.h"


int v_width(vector *v) {
    vector *f = v;
    int max = 0;
    while (f->next->next != NULL) {
        if(f->value > max) max = f->value;
        f = f->next->next;
    }
    return max;
}

int v_height(vector *v) {
    vector *f = v;
    int max = 0;
    while (f->next->next != NULL) {
        if(f->value == 0 && f->next->value > max) max = f->next->value;
        f = f->next;
    }
    return max;
}

vector * get_unit(vector *v, int row, int column) {
    vector *f = find_row_start(v, row);
    if(f->value == 0) return f;
    else {
        f = f->next;
        while(f->value!=0) {
            if(f->value == column) {
                return f->next;
            }
            else f = f->next->next;
        }
        return f;
    }
}

vector * trans_norm(vector *v){
    vector *f = create_vector();
    int height = v_height(v);
    int width = v_width(v);
   
    for(int i = 1; i < height+1; i++) {
        for(int j = 1; j < width+1; j++)  {
            //print_sch(f);
         
            if(get_unit(v, i, j)->value != 0) add_unit(f, j, i, get_unit(v, i, j)->value);
        }
    }
    return f;
}

vector * create_vector() {
    vector *v = malloc(sizeof(vector));
    v->value = 0;
    v->prev = NULL;
    vector *v_end = malloc(sizeof(vector));
    v_end->value = 0;
    v_end->prev = v;
    v_end->next = NULL;
    v->next = v_end;
    return v;
}

vector * create_from_file(FILE *f) {
    vector *v = create_vector();
    char c =' ';
    char d[MAXNUM] = "";
    char di = 0;
    int i = 1;
    int j = 1;
    while(true) {
        c = getc(f);
        if(c == EOF) {
            double value = atof(d);
            if(value != 0) {
                add_unit(v, i, j, value);
                print_normal(v);
                printf("===\n");
            }
            break;
        }
        else if(c == '\n') {
            
            di = 0;
            double value = atof(d);
            memset(d, 0, MAXNUM);
            if(value != 0) {
                add_unit(v, i, j, value);
                print_normal(v);
                printf("===\n");
            }
            
            i++;
            j = 1;
        } else if(c == ' ') {
            di = 0;
            double value = atof(d);
            memset(d, 0, MAXNUM);
            if(value != 0) {
                add_unit(v, i, j, value);
                print_normal(v);
                printf("===\n");
            }
            j++;
        } else {
            d[di] = c;
            di++;
        }
    }
    fclose(f);
    return v;
}

void add_unit(vector *v, int row, int column, double value) {
    vector *f = find_row_start(v, row);
    if(f->value == 0) {
        vector *row_v = malloc(sizeof(vector));
        row_v->value = row;
        add_unit_to_start(row_v, f);
        vector *column_v = malloc(sizeof(vector));
        column_v -> value = column;
        add_unit_to_start(column_v, row_v);
        vector *value_v = malloc(sizeof(vector));
        value_v -> value = value;
        add_unit_to_start(value_v, column_v);
        vector *end_v = malloc(sizeof(vector));
        end_v -> value = 0;
        add_unit_to_start(end_v, value_v);
    }
    else {
        vector *d = f->next;
        while(d->value != 0) {
            if(d->value > column) {
                break;
            }
            d = d->next->next;
        }
        d = d->prev;
        vector *column_v = malloc(sizeof(vector));
        column_v -> value = column;
        add_unit_to_start(column_v, d);
        vector *value_v = malloc(sizeof(vector));
        value_v -> value = value;
        add_unit_to_start(value_v, column_v);
    }
}

vector * find_row_start(vector *v, int row) {
    vector *f = v;
    vector *start = v;
    while (f->next!=NULL) {
        if (f->value == 0 & f->next->value == row) {
            start = f->next;
            return start;
        }
        else if(f->value == 0 & f->next->value > row){
            start = f;
            return start;
        }
        else if(f->value == 0 & f->next->value == 0){
            start = f;
            return start;
        }
        else f = f->next;
    }
    return v;
}

void add_unit_to_start(vector *v, vector *start){
    v->next = start->next;
    v->prev = start;
    start -> next -> prev = v;
    start -> next = v;
}

void print_normal(vector *v) {
    int height = v_height(v);
    int width = v_width(v);
    for(int i = 1; i < height+1; i++) {
        printf("|\t\t");
        for(int j = 1; j < width+1; j++)  {
            printf("%.2f\t\t", get_unit(v, i, j)->value);
        }
        printf("|\n");
    }
}

void print_sch(vector *v) {
    vector *f = v;
    int count = 0;
    printf("||");
    while(f->next != NULL) {
        printf("\t%.2f\t|", f->value);
        count ++;
        if(count == 2) {
            printf("|");
            count = 0;
        }
       
        f = f->next;
    }
    printf("\t%.2f\t||", f->value);
    printf("\n");
}

vector * trans(vector *v){
    vector *f = create_vector();
    int height = v_height(v);
    int width = v_width(v);
   
    for(int i = 1; i < height+1; i++) {
        for(int j = 1; j < width+1; j++)  {
            //print_sch(f);
         
            if(get_unit(v, i, j)->value != 0) add_unit(f, width + 1 - j, height + 1 - i, get_unit(v, i, j)->value);
        }
    }
    return f;
}

bool is_cososim(vector *v) {
    int width = v_width(v);
    int height = v_height(v);
    if(width != height) return false;
    else {
        vector *f = trans_norm(v);
        for(int i = 1; i < height+1; i++) {
            for(int j = 1; j < width+1; j++)  {
                if(-get_unit(v, i, j)->value != get_unit(f, i, j)->value) return false;;
            }
        }
        return true;
    }
}
