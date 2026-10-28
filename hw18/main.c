#include <stdio.h>
#include <stdlib.h>
#include "scores.h"

int main(void) {
    
    int scores[] = {67, 77, 71, 52, 63};
    int size = sizeof(scores) / sizeof(scores[0]);
    printf("Size of scores[]: %d\n", size);
    print_scores(scores, size);


    printf("score_at(scores, size, 3): %d\n", score_at(scores, size, 3));
    printf("score_at(scores, size, 5): %d\n", score_at(scores, size, 5));

    printf("Sum of scores: %d\n", sum_scores(scores, size));
    printf("Max score: %d\n", max_score(scores, size));

    printf("Number of scores in array that are at least 67: %d\n", count_at_least(scores, size, 67));

    int board[3][GAMES] = {
        {55, 66, 77, 88},
        {64, 73, 84, 67},
        {75, 67, 82, 83}
    };

    print_board(board, 3);
    printf("Sum of scores on board: %d\n", board_sum(board, 3));
    
    printf("Testing print_scores(NULL, 5):\n");
    print_scores(NULL, 5);
    printf("Done (should have printed nothing).\n");
}