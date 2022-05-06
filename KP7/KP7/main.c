//
//  main.c
//  KP7
//
//  Created by Денис Фадеев on 4/27/22.
//

#include <stdio.h>
#include "vector.h"

bool isInt(const char*str) {
    while(*str)  {
        if((*str< '0' || *str > '9') && *str != '-')
            return false;
        *str++;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector *v = NULL;
    
    bool working = true;
    while(working) {
        int input = 0;
        char h[] = "";
        while(input == 0){
            printf("Working with matrix. Enter code of command.\nCode 1: Read matrix\t\tCode 2: Add unit\t\tCode 3: Print normal matrix\nCode 4: Print scheme matrix\t\tCode 5: Transport\t\tCode 6: Is cososimetric\nCode 7: Exit\nEnter: ");
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
            }else {
                printf("Incomprehensible input\n");
            }
        }
        switch(input){
            case 1:
            {
                if(v != NULL)
                    printf("Matrix already exists\n");
                else {
                    char filename[100] = "";
                    printf("Enter  filename: ");
                    scanf("%s", filename);
                    
                    FILE *f = fopen(filename, "r");
                    if(f == NULL) {
                        printf("File not found\n");
                    }
                    else {
                        v = create_from_file(f);
                        printf("Matrix created\n");
                    }
                   
                }
                break;
            }
            case 2:
            {
                if(v != NULL){
                    char row[100] = "";
                    char column[100] = "";
                    char value[100] = "";
                    
                    printf("Enter  row: ");
                    scanf("%s", row);
                    
                    printf("Enter column: ");
                    scanf("%s", column);
                    
                    printf("Enter value: ");
                    scanf("%s", value);
                    if(isInt(row) && isInt(column) && isInt(value)){
                        int irow = atoi(row);
                        int icolumn = atoi(column);
                        double dvalue = atof(value);
                        add_unit(v, irow, icolumn, dvalue);
                    } else printf("Not a number\n");
                }
                else printf("Matrix not exists\n");
                break;
            }
            case 3:
            {
                if(v != NULL) {
                    print_normal(v);
                }
                else {
                    printf("Matrix not exists\n");
                }
                break;
            }
            case 4: {
                if(v != NULL) {
                    print_sch(v);
                }
                else {
                    printf("Matrix not exists\n");
                }
                break;
            }
            case 5:
                if(v != NULL) {
                    v = trans(v);
                    printf("Matrix transported\n");
                }
                else {
                    printf("Matrix not exists\n");
                }
                break;
            case 6:
                if(v != NULL) {
                    bool is = is_cososim(v);
                    if(is)   printf("Matrix cososimetric\n");
                    else printf("Matrix is not cososimetric\n");
                  
                }
                else {
                    printf("Matrix not exists\n");
                }
                break;
            case 7:
                printf("End program\n");
                working = false;
                break;
                
        }
    }
    return 0;
}
