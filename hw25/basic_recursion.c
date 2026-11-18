#include <stdio.h>

long long factorial(int n);
long long fib(int n);
int max_in_array(const int *a, int n);
int is_palindrome(const char *s, int i, int j);

int main(void) {

    printf("Factorial(0) = %lld\n", factorial(0));
    printf("Factorial(5) = %lld\n", factorial(5));

    printf("fib(0) = %lld\n", fib(0));
    printf("fib(10) = %lld\n", fib(10));

    int silly_array[] =  {1, 2, 3, 4, 5};
    char pallydrome[] = "racecar";

    char non_pallydrome[] = "gracecar";

    printf("Maximum of {1, 2, 3, 4, 5}: %d\n", max_in_array(silly_array, 5));

    // Could have used strlen to assign string length to a variable.
    printf("is_palindrome on \"racecar\": %d\n", is_palindrome(pallydrome, 0, 6));
    printf("is_palindrome on \"gracecar\": %d\n", is_palindrome(non_pallydrome, 0, 7));

    printf("NULL check on is_palindrome: %d\n", is_palindrome(NULL, 0, 7));
    
    return 0;
}

long long factorial(int n) {

    // Precondition: n >= 0
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

long long fib(int n)  {

    // Precondition: n >= 0
    if (n < 2) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int max_in_array(const int *a, int n) {

    if (n <= 0 || a == NULL) {
        return 0;
    }
    
    /* WHY I wrote made the base case return the first index: If you were to plug in an array with only negative values, the
    *  returning 0 or 1 would make the maximum that is ultimately returned an inaccurate one.
    */
    if (n == 1) {
        return a[0];
    }

    int max = max_in_array(a + 1, n - 1);

    if (a[0] > max) {
        return a[0];
    } else {
        return max;
    }
}

int is_palindrome(const char *s, int i, int j) {

    if (s == NULL) {
        return 0;
    }
    if (i >= j) {
        return 1;
    }
    if (s[i] !=  s[j]) {
        return 0;
    }
    return is_palindrome(s, i + 1, j - 1);
}