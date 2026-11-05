/*
 * Implements helper functions for printing and manipulating strings
 * David Ross
 */

#include <stdio.h>
#include <string.h>
#include "lineup.h"

void print_label(const char label[]) {

    if (label == NULL) {
        return;
    }
    printf("%s\n", label);
}

int label_len(const char label[]) {

    if (label == NULL) {
        return 0;
    }
    return (int)strlen(label);
}

void safe_copy(char dest[], int dest_size, const char src[]) {

    if (dest == NULL || dest_size <= 0) {
        return;
    }

    if (src == NULL) {
        dest[0] = '\0';
        return;
    }
    

    int last_index = dest_size - 1;

    strncpy(dest, src, last_index);
    dest[last_index] = '\0';

}

void safe_join(char dest[], int dest_size, const char extra[]) {
    
    if  (dest == NULL || dest_size <= 0 || extra == NULL) {
        return;
    }

    size_t dest_len = strlen(dest);

    if (dest_len >= (size_t)dest_size) {
        return;
    }

    int remaining_space = dest_size - dest_len - 1;
    strncat(dest, extra, remaining_space);
}

int labels_match(const char a[], const char b[]) {
    if (a == NULL || b == NULL) {
        return 0;
    }
    if (strcmp(a, b) == 0) {
        return 1;
    } else {
        return 0;
    }
}

int find_text(const char label[], const char needle[]) {
    if (label == NULL || needle == NULL) {
        return -1;
    }

    const char *found = strstr(label, needle);

    if (found != NULL) {
        return found - label;
    } else {
        return -1;
    }
}