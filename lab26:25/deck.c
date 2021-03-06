#include "deck.h"

deck * deck_create() {
    deck *d = malloc(sizeof(deck));
    d->left = NULL;
    d->right = NULL;
    return d;
}

bool deck_is_empty(deck *d) {
    if(d == NULL) return true;
    bool empty;
    empty = (d->left == NULL) ? true : false;
    return empty;
}

void deck_push_front(deck *d, int value) {
    if(deck_is_empty(d)) {
        unit *u = (unit *)malloc(sizeof(unit));
        u->value = value;
        u->next = NULL;
        d->left = u;
        d->right = u;
    }
    else {
        unit *u = (unit *)malloc(sizeof(unit));
        u->value = value;
        u->next = d->left;
        d->left = u;
    }
}

void deck_push_back(deck *d, int value) {
    if(deck_is_empty(d)) {
        unit *u = (unit *)malloc(sizeof(unit));
        u->value = value;
        u->next = NULL;
        d->left = u;
        d->right = u;
    }
    else {
        unit *u = (unit *)malloc(sizeof(unit));
        u->value = value;
        u->next = NULL;
        d->right->next = u;
        d->right = u;
    }
}

unit * deck_pop_front(deck *d) {
    if(deck_is_empty(d)) {
        printf("Deck is empty\n");
        return NULL;
    }
    else if(d->left->next != NULL) {
        unit *u = d->left;
        d->left = u->next;
        u->next = NULL;
        return u;
    }
    else {
        unit *u = d->left;
        d->left = NULL;
        d->right = NULL;
        u->next = NULL;
        return u;
    }
    
}

unit * deck_pop_back(deck *d) {
    if(deck_is_empty(d)) {
        printf("Deck is empty\n");
        return NULL;
    }
    else if(d->left->next != NULL) {
        unit *u = d->right;
        d->right = deck_find_prev(d->left, u);
        d->right->next = NULL;
        u->next = NULL;
        return u;
    }
    else {
        unit *u = d->right;
        d->left = NULL;
        d->right = NULL;
        u->next = NULL;
        return u;
    }
}

unit * deck_find_prev(unit *front, unit *f) {
    if(front->next == f) return front;
    else return deck_find_prev(front->next, f);
}

void deck_print(deck *d) {
    unit *u = d->left;
    if(deck_is_empty(d)) {
        printf("Deck is empty\n");
    }
    else {
        printf("Deck: ");
        while(u != NULL) {
            printf("%d ", u->value);
            u = u->next;
        }
        printf("\n");
    }
}

size_t deck_size(deck *d) {
    size_t s = 0;
    if(d == NULL) return 0;
    else {
    unit *u = d->left;
    while(u != NULL) {
        u = u->next;
        s++;
    }
    return s;
    }
}

deck * deck_sort(deck *d) {
    int step = 2;
    int n =(int)deck_size(d);
    deck **t = malloc(sizeof(deck) * n);
    for(int i = 0; i<n; i++) {
        deck *f = deck_create();
        deck_push_front(f, deck_pop_front(d) -> value);
        t[i] = f;
    }
    int b = n;
    printf("Sorting =======\n");
    while(b > 1) {
        int i = 0;
        int k = 0;
        while(i < b) {
            deck *f = deck_create();
            int count = (int)deck_size(t[i]) + (int)deck_size(t[i+1]);
            for(int j = 0; j<count; j++) {
                if(deck_is_empty(t[i])) {
                    unit *u = deck_pop_front(t[i+1]);
                    deck_push_back(f, u->value);
                    free(u);
                }
                else if (deck_is_empty(t[i+1])) {
                    unit *u = deck_pop_front(t[i]);
                    deck_push_back(f, u->value);
                    free(u);
                }
                else if(t[i]->left->value > t[i+1]->left->value) {
                    unit *u = deck_pop_front(t[i+1]);
                    deck_push_back(f, u->value);
                    free(u);
                }
                else {
                    unit *u = deck_pop_front(t[i]);
                    deck_push_back(f, u->value);
                    free(u);
                }
            }
            deck_print(f);
            t[k] = f;
            k++;
            i+=step;
        }
        b = b / step + (b % step);
        printf("============\n");
    }
    return t[0];
}
