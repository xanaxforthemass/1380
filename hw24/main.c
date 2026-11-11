/*
 * Demonstrates unions using variant helper functions that represent
 * players in an intramural league.
 * David Ross
 */

 #include <stdio.h>
 #include "variant.h"

 int main(void)  {

    struct Stat stat;
    set_score(&stat, 100);

    print_stat(&stat);
    printf("get_score -> %d\n", get_score(&stat));

    set_average(&stat, 95.5f);

    print_stat(&stat);
    printf("get_average -> %.2f\n", get_average(&stat));

    set_score(&stat, 69);
    printf("Wrong kind get_average -> %.2f\n", get_average(&stat));

    set_average(&stat, 42.0f);
    printf("Wrong kind get_score -> %d\n", get_score(&stat));

    print_sizes();

    printf("NULL test for print_stat:\n");
    print_stat(NULL);
    printf("Program did not crash!\n");

    return 0;
 }