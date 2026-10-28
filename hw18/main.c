/*
 * Demo functions for reading indices in a weather log, including functions for
 * creating logs that dynamically allocate memory or modify dynamic arrays.
 * David Ross
 * main.c
 */

#include <stdlib.h>
#include <stdio.h>
#include "station.h"

int main(void) {
    int n = 5;
    printf("Making log...\n");
    int *arr = make_log(n);

    for (int i = 0; i < n; i++) {
        arr[i] = i * 3 + 70;
    }

    print_log(arr, n);

    printf("Growing log...\n");

    int larger_n = 10;
    int * temp = grow_log(arr, n, larger_n);

    if (temp == NULL) {
        free_log(&arr);
        return 1;
    }

    arr = temp;

    for (int i = n; i < larger_n; i++) {
        arr[i] = i * 3 + 70;
    }

    n = larger_n;

    print_log(arr, n);
    printf("Max Reading: %d\n", max_reading(arr, n));

    printf("Appending 99 and 101...\n");

    temp = append_reading(arr, &n, 99);

    if (temp == NULL) {
        free_log(&arr);
        return 1;
    }
    arr = temp;

    temp = append_reading(arr, &n, 101);

    if (temp == NULL) {
        free_log(&arr);
        return 1;
    }
    arr = temp;

    print_log(arr, n);

    printf("Reading at index 2: %d\n", reading_at(arr, n, 2));
    printf("Reading at index 4: %d\n", reading_at(arr, n, 4));

    printf("Making zero log...\n");
    int *zero_arr = make_zero_log(n);
    print_log(zero_arr, n);

    printf("Testing null value...\n");
    printf("max_reading(NULL, 5): %d\n", max_reading(NULL, 5));

    free_log(&arr);
    printf("After free_log, pointer is %s", arr == NULL ? "NULL\n" : "Not NULL\n");

    free_log(&zero_arr);

    return 0;
}