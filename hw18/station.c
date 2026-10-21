/*
 * Library of functions for reading indices in a weather log, including functions for
 * creating logs that dynamically allocate memory or modify dynamic arrays.
 * David Ross
 * main.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "station.h"

int *make_log(int n) {
    if (n <= 0 ) {
        printf("n must be greater than 0\n");
        return NULL;
    }
    int *arr = malloc(n * sizeof *arr);

    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    return arr;
}

int *make_zero_log(int n) {
    if (n <= 0 ) {
        printf("n must be greater than 0\n");
        return NULL;
    }

    int *arr = calloc(n, sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    return arr;
}

int *grow_log(int *log, int old_n, int new_n) {

    if (new_n <= old_n) {
        return log;
    }

    if (log == NULL && new_n > 0) {
        return make_log(new_n);
    }

    int *temp = realloc(log, new_n * sizeof(*log));
        if (temp == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    return temp;
    
}

int *append_reading(int *log, int *n, int value) {

    if (n == NULL) {
        return NULL;
    }
    
    // No additional logic needed for if log is null and n == 0, that case is covered in grow_log.
    int *temp = grow_log(log, *n, *n + 1);
    if (temp == NULL) {
        return NULL;
    }

    temp[*n] = value;

    (*n)++;

    return temp;

}

void print_log(const int *log, int n) {
    if (log == NULL || n <= 0) {
        return;
    }
    for (int i = 0; i < n; i ++) {
        printf("%d\n", log[i]);
    }
}

int reading_at(const int *log, int n, int index) {
    if (log == NULL || n <= 0 || index >= n || index < 0) {
        return 0;
    }
    return log[index];
}

int max_reading(const int *log, int n) {
    if (log == NULL || n <= 0) {
        return 0;
    }

    int max = log[0];

    for (int i = 1; i < n; i ++) {
        if (log[i] > max) {
            max = log[i];
        }
    }
    return max;
}

void free_log(int **log) {
    if (log ==  NULL || *log == NULL) {
        return;
    }

    free(*log);
    *log = NULL;
}