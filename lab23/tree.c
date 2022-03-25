//
//  tree.c
//  BeenTree
//
//  Created by Денис Фадеев on 3/19/22.
//
#include "tree.h"


unit * makeTree(int key) {
    unit *u = malloc(sizeof(unit));
    u -> key = key;
    u -> count = 0;
    u -> sons = NULL;
    return u;
}

unit * findUnit(unit * u, int key) {
    if(u -> key == key){
        return u;
    }
    if(u -> count > 0){
        for(int i = 0; i < u->count; i++) {
            unit *p = findUnit(u->sons[i], key);
            if(p!=NULL) return p;
        }
        return NULL;
    } else {
        return NULL;
    }
}

void addUnit(unit *u, int parentKey, int key) {
    if(findUnit(u, key) != NULL) printf("UNIT EXISTS\n");
    else {
        unit *f = findUnit(u, parentKey);
        if(f!=NULL) {
            if(f->count > 0){
                f -> sons = (unit **)realloc(f->sons, sizeof(unit *) * (f->count + 1));
                f -> sons[f->count] = makeTree(key);
                f->count ++;
            } else if(f->count == 0){
                f->sons = (unit**)malloc(sizeof(unit*));
                f -> sons[0] = makeTree(key);
                f->count = 1;
                
            }
            
        }
        else {
            printf("PARENT NOT FOUND\n");
        }
    }
}

void clearTree(unit *u) {
    for(int i = 0; i < u -> count; i++) {
        if(u -> sons[i] != NULL) {
            clearTree(u -> sons[i]);
        }
    }
    free(u -> sons);
    u -> sons = NULL;
    free(u);
    u = NULL;
}

unit* findParent(unit *f, unit *p){
    if(f->count>0){
        for(int i = 0; i<f->count; i++){
            if(f->sons[i]->key == p->key){
                return f;
            }
            else{
                unit* s = findParent(f->sons[i], p);
                if(s!=NULL) return s;
            }
        }
        return NULL;
    }
    else return NULL;
}

void removeUnit(unit *u, unit *f) {
    if(findUnit(u, f->key) == NULL){
        printf("UNIT NOT FOUND");
    }
    else {
        unit *p = findParent(u, f);
        int rmv = 0;
        for(int i = 0; i<p->count; i++){
            if(p->sons[i]->key == f->key){
                rmv = i;
                break;
            }
        }
        clearTree(f);
        for(int i = rmv; i<p->count-1; i++){
            p->sons[i] = p->sons[i+1];
        }
        p->count --;
        
    }
}

void printSons(unit *u, int deep){
    for(int i = 0; i < deep-1; i++)
        printf("| ");
    if(deep != 0)
        printf("|");
    printParent(u, deep);
    printf("\n");
    for(int i = 0; i < u->count; i++){
        printSons(u->sons[i], deep+1);
    }
    
}

void printParent(unit *u, int deep){
    if(deep != 0)
        printf(">%d", u->key);
    else
        printf("%d", u->key);
}

void printTree(unit *u){
    printSons(u, 0);
}

unit * findMCNTU(unit *u, int iter) {
    unit *p = NULL;
    int max = 0;
    if(u -> count < 1 && iter == 0){
        return NULL;
    }
    else if(u ->count < 1){
        unit *s = malloc(sizeof(unit));
        s -> key = u -> key;
        s -> count = iter;
        s -> sons = NULL;
        return s;
    }
    else{
        for(int i = 0; i < u->count; i++){
            if(findMCNTU(u->sons[i], iter+1)->count > max){
                p = findMCNTU(u->sons[i], iter+1);
                max = p->count;
            }
        }
        return p;
    }
}

unit * specFunc(unit * u){
    unit *p = findMCNTU(u, 0);
    if(p == NULL){
        return NULL;
    }
    else {
        unit *s = findUnit(u, p->key);
        unit *f = findParent(u, s);
        return f;
    }
    
}





