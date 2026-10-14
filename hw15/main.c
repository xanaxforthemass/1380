/*
 * Demo functions for the prices library for setting and swapping prices on drinks
 * David Ross
 * main.c
 */

#include <stdio.h>  

#include "prices.h"

int main(void) {
    int latte_price = 400;
    int *latte_tag = &latte_price;
    
    printf("Latte price: %d cents \n", latte_price);
    printf("&latte_price: %p \n", (void *) &latte_price);
    printf("Latte tag: %d cents \n", *latte_tag);
    printf("Latte tag address: %p \n", (void *) latte_tag);

    int vanilla_price = 600;
    printf("Vanilla price: %d cents \n", vanilla_price);
    
    set_price(&vanilla_price, 650);
    
    printf("Vanilla price after set_price(650): %d cents \n", vanilla_price);

    int mocha_price = 500;
    printf("Mocha price before swap: %d cents \n", mocha_price);
    printf("Latte price before swap: %d cents \n", latte_price);
    
    swap_cents(&latte_price, &mocha_price);
    
    printf("Mocha price after swap: %d cents \n", mocha_price);
    printf("Latte price after swap: %d cents \n", latte_price);

    int *espresso_price = NULL;
    print_price("Espresso price variable with null value", espresso_price);

    int *mocha_tag = &mocha_price;
    printf("Mocha tag before retarget: %d cents \n", *mocha_tag);

    retarget(&mocha_tag, &vanilla_price);
    printf("Mocha tag after retarget to vanilla price: %d cents \n", *mocha_tag);

    int prices [] = {vanilla_price, latte_price, mocha_price};
    int *p = prices;

    printf("*(p + 0): %d cents \n", *(p + 0));
    printf("*(p + 1): %d cents \n", *(p + 1));
    printf("*(p + 2): %d cents \n", *(p + 2));

    return 0;

}