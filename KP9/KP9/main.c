//
//  main.c
//  KP9
//
//  Created by Денис Фадеев on 5/13/22.
//

#include <stdio.h>
#include "map.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    map *m = map_create();
    map_add(m, 4, "sdgsdg");
    map_add(m, 1, "fwefg");
    map_add(m, 8, "sgeg");
    map_print(m);
    map *l = map_create();
    map_generate(l);
    map_print(l);
    map_sort(l);
    map_print(l);
    return 0;
}
