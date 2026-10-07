#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>

void applyTax(double price);
void applyDiscount(double *price, double discountRate);
double calculateTotal(int count, ...);

int main(void) {
    double price = 100.00;

    printf("Original price (before applyTax): $%.2f\n", price);
    applyTax(price);
    printf("Price variable after function call: $%.2f\n", price);

    applyDiscount(&price, 20); 
    printf("Price variable after applyDiscount: $%.2f\n", price); 

    double total = calculateTotal(3, 10.0, 20.0, 30.0);
    printf("calculateTotal(3, 10.0, 20.0, 30.0): $%.2f\n", total);

    return 0;
}

void applyTax(double price) {
    
    double taxRate = 0.07; // 7% tax rate
    double taxAmount = price * taxRate;
    double totalPrice = price + taxAmount;

    printf("Total price after tax: $%.2f\n", totalPrice);
}

void applyDiscount(double *price, double discountRate) {
    if (price == NULL || discountRate < 0 || discountRate > 100) {
        return; // Handle null pointer and invalid discount rate
    }
    *price = *price - (*price * discountRate / 100);
}

double calculateTotal(int count, ...) {
    va_list arguments;
    va_start(arguments, count);
    double total = 0.0;

    for (int i = 0; i < count; i++) {
        total += va_arg(arguments, double);
    }

    va_end(arguments);
    return total;
}