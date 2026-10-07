#include <stdio.h>
#include "specials.h"

int main(void) {

    int prices[] = {100, 200, 300, 400, 500};
    int n = 5;

    int total = sum_order(prices, n);
    printf("Sum of first %d prices in [100, 200, 300, 400, 500]: %d\n", n, total);

    int fact = factorial(5);
    printf("Factorial of 5: %d\n", fact);

    int factorial_of_0 = factorial(0);
    printf("Factorial of 0: %d\n", factorial_of_0);

    int power_result = power(2, 8);
    printf("2 raised to the power of 8: %d\n", power_result);

    int power_of_0 = power(5, 0);
    printf("5 raised to the power of 0: %d\n", power_of_0);

    int sum = apply_op(100, 200, add_cents);
    printf("Sum of 100 and 200 using apply_op: %d\n", sum);

    int percent_off = apply_op(1000, 20, percent_off_amount);
    printf("20%% discount amount on 1000 cents using apply_op: %d cents\n", percent_off);

    return 0;
}