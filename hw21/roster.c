/*
 * Implements helper functions for printing and manipulating team names
 * David Ross
 */
#include <stdio.h>
#include "roster.h"

void print_team(const char name[]) {

    if (name == NULL ) {
        return;
    }
    printf("%s\n", name);
}

int team_len(const char name[]) {

    if (name == NULL) {
        return 0;
    }

    int count = 0;
    while (name[count] != '\0') {
        count++;
    }
    return count;
}

void team_copy(char dest[], int dest_size, const char src[])  {

    if  (dest == NULL || dest_size <= 0) {
        return;
    }

    // Already checked for dest_size > 0.
    if (src == NULL) {
        dest[0] = '\0';
        return;
    }

    int last_index = dest_size - 1;
    int i = 0;

    while (i < last_index && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';
}

int team_same(const char a[], const char b[]) {
    
    if (a == NULL || b == NULL) {
        return 0;
    }

    while (*a != '\0' && *b != '\0') {
        if (*a != *b) {
            return 0;
        }
        a++;
        b++;
    }
    return *a == '\0' && *b == '\0';
}

void shout(char name[])  {

    if (name == NULL) {
        return;
    }

    int capital_diff = 'a' - 'A';

    for (int i = 0; name[i] != '\0'; i++) {
        if (name[i] >= 'a' && name[i] <= 'z') {
            name[i] -= capital_diff;
        }
    }

}