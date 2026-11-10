/*
 * Implements helper functions for printing and manipulating Player structs
 * David Ross
 */

#include <stdio.h>
#include <string.h>
#include "player.h"


void print_player(const struct Player *p)  {
    if (p == NULL ) {
        return;
    }
    printf("Name: %s\n", p->name);
    printf("Jersey: %d\n", p->jersey);
    printf("Points: %d\n", p->points);

}

void init_player(struct Player *p, const char name[], int jersey, int points) {
    if (p == NULL) {
        return;
    } 
    if (name == NULL) {
        p->name[0] = '\0';
    } else {
        strncpy(p->name, name, sizeof(p->name) - 1);
        p->name[sizeof(p->name) - 1] = '\0';
    }

    p->jersey = jersey;
    p->points = points;
}

int get_points(const struct Player *p) {
    if (p == NULL) {
        return 0;
    }
    return p->points;
}

void add_points(struct Player *p, int more) {
    if (p == NULL) {
        return;
    }
    p->points += more;
}

 
int same_jersey(const struct Player *a, const struct Player *b) { 
    if (a == NULL || b == NULL) {
        return 0;
    }
    // Will return 0 if false.
    return a->jersey == b->jersey;
}