//
//  tree.h
//  BeenTree
//
//  Created by Денис Фадеев on 3/19/22.
//

#ifndef tree_h
#define tree_h
#include <stdio.h>
#include "stdlib.h"
typedef struct unit {
    struct unit ** sons;
    int key;
    int count;
} unit;
unit * makeTree(int key);
void clearTree(unit * u);
void printParent (unit *u, int deep);
void printSons (unit *u, int deep);
void printTree (unit *u);
unit * findUnit (unit *u, int key);
void addUnit(unit * u, int parentKey, int key);
unit *findParent (unit *f, unit *p);
void removeUnit(unit *u, unit *f);
unit * findMCTU(unit *u, int iter);
unit * specFunc(unit *u);
#endif /* tree_h */
