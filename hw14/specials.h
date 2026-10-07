#ifndef SPECIALS_H
#define SPECIALS_H


int sum_order(const int prices[], int n);
int factorial(int n);
int power(int base, int exp);

typedef int (*price_op)(int, int);
int add_cents(int a, int b); 
int percent_off_amount(int price_cents, int percent);
int apply_op(int a, int b, price_op op);

#endif /* SPECIALS_H */