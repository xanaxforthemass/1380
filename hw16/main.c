/*
 * Demo functions for the prices library for checking and reversing prices on a cafe menu, as well as
 * finding the max price on the menu.
 * David Ross
 * main.c
 */
#include <stdio.h>
#include "menu.h"


int main(void) {
    int prices[10];
    for  (int *p = prices; p < prices + 10; p++) {
        *p = (p - prices + 1) * 100;
    }
        
    print_menu(prices, 10);

    int index1 = 3;
    int index2 = 0;
    printf("Price at index %d: %d cents\n", index1, price_at(prices, 10, index1));
    printf("Price at index %d: %d cents\n", index2, price_at(prices, 10, index2));


    printf("Highest price on the menu: %d cents\n", max_price(prices, 10));

    printf("Address at index 0: %p \n", (void *) prices);
    printf("Address at index 1: %p \n", (void *) (prices + 1));

    printf("Number of items between index 0 and index 4: %d", items_between(&prices[0], &prices[4]));

    printf("\nReversing the menu...\n");
    reverse_menu(prices, 10);
    print_menu(prices, 10);

    const char *latte = "Latte";
    const char *null_example = NULL;

    printf("Length of string \"%s\": %d\n", latte, drink_length(latte));
    printf("Length of NULL: %d\n", drink_length(null_example));

    return 0;
}