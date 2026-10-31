/*
 * Demonstrates function library by manipulating a hard-coded 2d array
 * David Ross
 */

#include <stdio.h>
#include "picture.h"

int main(void) {
    int pic[][COLS] = {
        {0, 1, 1, 1, 0},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1}
    };

    int nrows = sizeof(pic) / sizeof(pic[0]);

    print_picture(pic, nrows);
    printf("Trying to find '2' with find_code(pic, nrows, 2): %d\n", find_code(pic, nrows, 2));
    printf("Trying to find '1' with find_code(pic, nrows, 1): %d\n", find_code(pic, nrows, 1));

    printf("Setting pic[0][2] to '2'...\n");
    set_cell(pic, nrows, 0, 2, 2);
    print_picture(pic, nrows);
    
    printf("Running set_cell out of bounds check...\n");
    set_cell(pic, nrows, -1, 5, 2);
    printf("No crash. Picture:\n");
    print_picture(pic, nrows);


    printf("Running find_code null check...\n");
    find_code(nullptr, nrows, 1);
    printf("Check successful\n");

    return 0;
}