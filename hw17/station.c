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