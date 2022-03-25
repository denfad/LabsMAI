//
//  main.c
//  BeenTree
//
//  Created by Денис Фадеев on 3/19/22.
//

#include "tree.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"

int main() {
    // insert code here...
    unit *tree = NULL;
    bool working = true;
    while(working) {
        int input = 0;
        char h[] = "";
        while(input == 0){
            printf("Working with tree. Enter code of command.\n\tCode 1: Create tree\n\t\tCode 2: Add unit\n\t\t\tCode 3: Delete unit\n\t\t\t\tCode 4: Print tree\n\t\t\t\t\tCode 5: Special function\n\t\t\t\t\t\tCode 6: Exit programm\nEnter: ");
            scanf("%s", h);
            if(!strcmp("1",h)){
                input = 1;
            }
            else if(!strcmp("2",h)) {
                input = 2;
            }
            else if(!strcmp("3",h)) {
                input = 3;
            }
            else if(!strcmp("4",h)) {
                input = 4;
            }else if(!strcmp("5",h)) {
                input = 5;
            }else if(!strcmp("6",h)) {
                input = 6;
            }else {
                printf("Incomprehensible input\n");
            }
        }
        switch(input){
            case 1:
            {
                if(tree != NULL)
                    printf("Tree already exists\n");
                else {
                    int key = 0;
                    printf("Enter key of first unit:");
                    scanf("%d", &key);
                    tree = makeTree(key);
                    printf("Tree created\n");
                }
                break;
            }
            case 2:
            {
                if(tree != NULL){
                int key = 0;
                int parentKey = 0;
                printf("Enter parent key: ");
                scanf("%d", &parentKey);
                printf("Enter key of unit: ");
                scanf("%d", &key);
                addUnit(tree, parentKey, key);
                printf("Unit with key %d created\n", key);
                }
                else printf("Tree not exists\n");
                break;
            }
            case 3:
            {
                if(tree != NULL) {
                int key = 0;
                printf("Enter key of unit for deliting: ");
                scanf("%d", &key);
                if(findUnit(tree, key) != NULL) {
                    unit *p = findUnit(tree, key);
                    removeUnit(tree, p);
                    printf("Unit removed\n");
                }
                else {
                    printf("Unit not found\n");
                }
                }
                else {
                    printf("Tree not exists\n");
                }
                break;
            }
            case 4: {
                if(tree != NULL) {
                    printTree(tree);
                }
                else {
                    printf("Tree not exists\n");
                }
                break;
            }
            case 5:
                printf("Key of special unit %d\n", specFunc(tree)->key);
                break;
            case 6:
                printf("End program\n");
                working = false;
                break;
                
        }
    }
    return 0;
}
