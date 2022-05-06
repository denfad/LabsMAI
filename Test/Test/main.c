#include <stdio.h>
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"
#include "deck.h"
#include "time.h"

bool isInt(const char*str) {
    while(*str)  {
        if((*str< '0' || *str > '9') && *str != '-' && *str != '.')
            return false;
        *str++;
    }
    return true;
}


int main(int argc, const char * argv[]) {
    deck *d = NULL;
    deck *e = NULL;
    bool working = true;
    while(working) {
        int input = 0;
        char h[] = "";
        while(input == 0){
            printf("Working with deck. Enter code of command.\nCode 1: Create deck\t\tCode 2: Push unit to front\t\tCode 3: Push unit to back\nCode 4: Pop unit from front\t\tCode 5: Pop unit from back\t\tCode 6: Show deck\nCode 7: Sort deck\tCode 8: Is deck empty\tCode 9: Deck size\nCode 10: Exit\nEnter: ");
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
            }else if(!strcmp("7",h)) {
                input = 7;
            }else if(!strcmp("8",h)) {
                input = 8;
            }else if(!strcmp("9",h)) {
                input = 9;
            }else if(!strcmp("10",h)) {
                input = 10;
            }else if(!strcmp("11",h)) {
                input = 11;
            }else {
                printf("Incomprehensible input\n");
            }
        }
        switch(input){
            case 1:
            {
                if(d != NULL)
                    printf("Deck already exists\n");
                else {
                    char c[] = "";
                    int key = 0;
                    printf("Enter key of first unit: ");
                    scanf("%s", c);
                    if(isInt(c)){
                        key = atoi(c);
                        
                        d = deck_create();
                        deck_push_front(d, key);
                        printf("Deck created\n");
                    }
                    else {
                        printf("Not a number\n");
                    }
                   
                }
                break;
            }
            case 2:
            {
                if(d != NULL){
                    char f[100] = "";
                    int key = 0;
                    printf("Enter key of unit: ");
                    scanf("%s", f);
                    if(isInt(f)){
                        key = atoi(f);
                        deck_push_front(d, key);
                    } else printf("Not a number\n");
                    
                }
                else printf("Deck not exists\n");
                break;
            }
            case 3:
            {
                if(d != NULL){
                    char f[100] = "";
                    int key = 0;
                    printf("Enter key of unit: ");
                    scanf("%s", f);
                    if(isInt(f)){
                        key = atoi(f);
                        deck_push_back(d, key);
                    } else printf("Not a number\n");
                    
                }
                else printf("Deck not exists\n");
                break;
            }
            case 4:
            {
                if(d != NULL){
                    printf("Key of front unit: %d", deck_pop_front(d) -> value);
                }
                else printf("Deck not exists\n");
                break;
            }
            case 5: {
                if(d != NULL){
                    printf("Key of back unit: %d", deck_pop_back(d) -> value);
                }
                else printf("Deck not exists\n");
                break;
            }
            case 6:
                if(d != NULL) {
                    deck_print(d);
                }
                else printf("Deck not exists\n");
                break;
            case 7:
                if(d != NULL) {
                    d = merge_sort(d);
                    printf("Deck sorted\n");
                }
                else printf("Deck not exists\n");
                break;
            case 8:
                if(d != NULL) {
                    printf("Deck is empty: %d\n", deck_is_empty(d));
                }
                else printf("Deck not exists\n");
                break;
            case 9:
                if(d != NULL) {
                    printf("Deck size: %zu\n", deck_size(d));
                }
                else printf("Deck not exists\n");
                break;
            case 10:
                printf("Stop program\n");
                working = false;
                break;
            case 11:
                e = deck_create();
                d = deck_create();
                for(int i = 0; i < 1000000; i++) {
                    int a = rand();
                    deck_push_back(e, a);
                    deck_push_back(d, a);
                }
                
                clock_t time_d = clock();
                d = merge_sort(d);
                clock_t d_end = clock() - time_d;
                
                clock_t time_e = clock();
                e = deck_sort(e);
                clock_t e_end = clock() - time_e;
              
                
                
                printf("Time of own function %f, time of usual %f\n", (double) e_end / CLOCKS_PER_SEC, (double) d_end / CLOCKS_PER_SEC);
                
                break;
                
        }
    }
    return 0;
}

