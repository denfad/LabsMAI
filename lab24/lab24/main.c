#include "tree.h"

int main(void) {
       unit *t = NULL;
       int opt = -1;
       while (opt!=5) {
               printf("Choose code of action:\n1. Enter an expression and create tree.\t2. Transforn expression.\n3. Print tree.\t\t4. Print expression.\t5. Exit\n");
               scanf("%d", &opt);
               switch (opt) {
                       case 1: {
                               printf("Please, enter an expression: ");
                               char expression[1000];
                               scanf("%s", expression);
                               int n = 0;
                               while (expression[n] != '\0') {
                                        n++;
                               }
                               t = make_tree(expression, 0, n-1);
                               break;
                       }
                       case 2: {
                               t = spec_func(t);
                               break;
                       }
                       case 3: {
                               printf("\n");
                               print_tree(t, 0);
                               break;
                       }
                       case 4: {
                               printf("\n");
                               print_expression(t);
                               printf("\n");
                               break;
                       }
               }
       }
       return 0;
}
