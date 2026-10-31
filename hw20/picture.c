/*
 * Implements helper functions for printing 2d arrays using ASCII characters
 * David Ross
 */

#include <stdio.h>
#include "picture.h"

void print_picture(const int pic[][COLS], int nrows) {
    if (pic == NULL || nrows  <= 0) {
        return;
    }

    for (int i = 0; i < nrows; i++)  {
        for (int j = 0; j < COLS; j++) {
            if (pic[i][j] == 0) {
                printf(".");
            } else if (pic[i][j] == 1) {
                printf("█");
            } else  {
                printf("?");
            }
        }
        printf("\n");
    }
    return;
}

int find_code(const int pic[][COLS], int nrows, int target) {
    if (pic == NULL || nrows  <= 0) {
        return -1;
    }

    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < COLS; j++) {
            if (pic[i][j] == target) {
                return i * COLS + j;
            }
        }
    }
    return -1;
}
void set_cell(int pic[][COLS], int nrows, int row, int col, int value) {
    if (pic == NULL || nrows < 0) {
        return;
    }

    if (row < 0 || row >= nrows || col < 0 || col >= COLS) {
        return;
    }

    pic[row][col] = value;
}