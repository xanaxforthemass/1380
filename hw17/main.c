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

    printf("Reading at index 2: %d\n", reading_at(arr, n, 2));
    printf("Reading at index 4: %d\n", reading_at(arr, n, 4));
    printf("Max Reading: %d\n", max_reading(arr, n));

    printf("Making zero log...\n");
    int *zero_arr = make_zero_log(n);
    print_log(zero_arr, n);

    printf("Testing null value...\n");
    printf("Reading_at(NULL, 5, 0): %d\n", reading_at(NULL, 5, 0));

    free_log(&arr);
    printf("After free_log, pointer is %s", arr == NULL ? "NULL\n" : "Not NULL\n");

    free_log(&zero_arr);

    return 0;
}