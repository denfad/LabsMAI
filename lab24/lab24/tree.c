//
//  tree.c
//  lab24
//
//  Created by Денис Фадеев on 5/19/22.
//

#include "tree.h"

bool is_op(char a) {
    if(a == '*' || a == '^' || a == '/' || a == '+' || a == '-') return true;
    else return false;
}

int define_priority (char a) {
       switch (a){
               case '-':
                       case '+':
                               return 1;
               case '*':
                       return 2;
               case '/':
                       return 3;
               case '^':
                       return 4;
               default:
                       return 100;
       }
}

unit * make_tree(char expr[], int first, int last) {
       int prior, min_prior = 100, k, depth = 0;
       unit *tree = malloc(sizeof(unit));
       for (int i = first; i <= last; ++i) {
               if (expr[i] == '(') {
                       depth++;
                       continue;
               }
               if (expr[i] == ')') {
                       depth--;
                       continue;
               }
               if (depth>0){
                       continue;
               }
               prior = define_priority(expr[i]);
               if (prior <= min_prior) {
                       min_prior = prior;
                       k = i;
               }
       }
       if (depth !=0) {
               printf("Wrong expression!\n");
               exit (1);
       }
       int l;
       if (min_prior == 100) {
               if (expr[first] == '(' && expr[last] == ')') {
                       free(tree);
                       return make_tree(expr, first +1, last - 1);
               }
               else {
                       l = last - first + 1;
                       for (int i = 0; i < l; i++ ) {
                               tree->data[i] = expr[first+i];
                       }
                       tree->data[l] = '\n';
                       tree->left = NULL;
                       tree->right = NULL;
                       return tree;
               }
       }
       tree->data[0] = expr[k];
       tree->data[1] = '\n';
       tree->left = make_tree(expr, first, k-1);
       tree->right = make_tree(expr, k+1, last);
       return tree;
}

void print_tree(unit *u, int l) {
       if (u->right != NULL) print_tree(u->right, l+1);
       for(int i = 0; i < l; ++i) {
               printf("   ");
       }
       printf("%5s", u->data);
       if (u->left != NULL) print_tree(u->left, l+1);
}

void print_expression(unit *u) {
       if (u==NULL) {
               return;
       }
       if (define_priority(u->data[0])!=100 && define_priority(u->left->data[0])!=100 && define_priority(u->data[0])
> define_priority(u->left->data[0])  || u->data[0] == '^' && u->left->data[0] == '^'   ){
               printf("(");
               print_expression(u->left);
               printf(")");
       } else print_expression(u->left);
       for (int i = 0; i < 50; ++i) {
               if (u->data[i] == '\n') {
                       break;
               }
               printf("%c", u->data[i]);
       }
       if (define_priority(u->data[0])!=100 && define_priority(u->right->data[0])!=100 && define_priority(u->data[0]
) > define_priority(u->right->data[0])  || u->data[0] == '^' && u->right->data[0] == '^'   ){
               printf("(");
               print_expression(u->right);
               printf(")");
       } else print_expression(u->right);
}



unit * spec_func(unit *u) {
    if (u == NULL) {
            return NULL;
    }
    if(is_op(u->data[0])) {
        spec_func(u->left);
        spec_func(u->right);
    }
    if(u->data[0] == '*' && !is_op(u->left->data[0]) && u->right->data[0] == '+'){
        u->data[0] = '+';
        unit *left = u->left;
        unit *right = u->right;
        u->left = make_tree("*", 0, 1);
        u->left->left = left;
        u->left->right = right->left;
        u->right = make_tree("*", 0, 1);
        u->right->left = left;
        u->right->right = right->right;
        
    }
    else if(u->data[0] == '*' && !is_op(u->right->data[0]) && u->left->data[0] == '+'){
        u->data[0] = '+';
        unit *left = u->left;
        unit *right = u->right;
        u->left = make_tree("*", 0, 1);
        u->left->left = right;
        u->left->right = left->left;
        u->right = make_tree("*", 0, 1);
        u->right->left = right;
        u->right->right = left->right;
    }
    return u;
}

