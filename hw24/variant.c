/*
 * Implements helper functions for printing and manipulating unions
 * David Ross
 */

 #include <stdio.h>
 #include "variant.h"

void print_stat(const struct Stat *s)  {

    if (s  == NULL) {
        return;
    }
    if (s->kind == STAT_SCORE)  {
        printf("Score: %d\n", s->value.score);
    } else if (s->kind  == STAT_AVERAGE) {
        printf("Average: %.2f\n", s->value.average);
    } else {
        printf("Unknown StatKind\n");
    }
}

void set_score(struct Stat *s, int score) {

    if (s == NULL) {
        return;
    }
    s->kind = STAT_SCORE;
    s->value.score = score;
}

void set_average(struct Stat *s, float average) {

    if (s == NULL) {
        return;
    }
    s->kind = STAT_AVERAGE;
    s->value.average = average;
}

int get_score(const struct Stat *s) {

    if  (s == NULL || s->kind !=  STAT_SCORE)  {
        return 0;
    }
    return s->value.score;
}

float get_average(const struct Stat *s) {

    if (s == NULL || s->kind != STAT_AVERAGE) {
        return 0.0f;
    }
    return s->value.average;
}

void print_sizes(void) {

    printf("Size of union StatValue: %zu bytes\n", sizeof(union StatValue));
    printf("Size of struct { int score; float average; }: %zu bytes\n",
         sizeof(struct { int score; float average; }));
}