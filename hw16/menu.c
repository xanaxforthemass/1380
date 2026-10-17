/*
* Function library for manipulating prices (in cents) on a menu using pointers.
* David Ross
* menu.c
*/

#include "menu.h"
#include <stdio.h>
#include <string.h>

void print_menu(const int *prices, int n) {

    if (prices == NULL || n <= 0) {
        return; 
    }

    printf("Menu: \n");
    for (const int *p = prices; p < prices + n; p++) {
        printf("%d cents\n", *p);
    }
}
int price_at(const int *prices, int n, int index) {
    if (prices == NULL || index < 0 || index >= n  || n <= 0) {
        return 0; 
    }

    return *(prices + index);
}
int max_price(const int *prices, int n) {
    if (prices == NULL || n <= 0) {
        return  0;
    }

    // Initialize a const int pointer to point at the first element
    const int *max  = prices;

    for (const int *p = prices + 1; p < prices + n; p++) {
        if (*p > *max) {
            max =  p;  
        }
    }
    return *max;
    }

void reverse_menu(int *prices, int n) {
    if (prices == NULL || n <= 1) {
        return;
    }
    int *start = prices;
    int *end = prices + n - 1;

    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }

    
}
int items_between(const int *start, const int *end) {
    if (start == NULL  || end == NULL)  {
        return 0;
    }
    return  end - start;
}

int drink_length(const char *name) {
    if (name == NULL) {
        return 0;
    }

    const char *char_ptr =  name;
    while (*char_ptr != '\0') {
        char_ptr++;
    }
    return char_ptr - name;
}