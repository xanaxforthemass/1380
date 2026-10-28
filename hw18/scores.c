/*
 * Implements helper functions for working with scores and a 2d scoreboard.
 * David Ross
 */

#include <stdio.h>

#include "scores.h"

void print_scores(const int scores[], int n) {
    if (scores == NULL || n <= 0) {
        return;
    }
    for (int i = 0; i  < n; i++)  {
        printf("Score: %d\n", scores[i]);
    }
}

int score_at(const int scores[], int n, int index) {
    if (scores == NULL || n <= 0 || index < 0 || index >= n) {
        return 0;
    }

    return scores[index];
}

int sum_scores(const int scores[], int n) {
    if (scores == NULL || n <= 0) {
        return 0;
    }

    int total = 0;

    for (int i = 0; i  < n; i++)  {
        total += scores[i];
    }
    
    return total;
}

int max_score(const int scores[], int n) {
    if (scores == NULL || n <= 0) {
        return 0;
    }
    int max = scores[0];
    for (int i = 1; i  < n; i++)  {
        if (scores[i] > max)  {
            max = scores[i];
        }
    }
    
    return max;
}

int count_at_least(const int scores[], int n, int threshold) {
    if (scores == NULL || n <= 0) {
        return 0;
    }
    int count = 0;
    for (int i = 0; i  < n; i++)  {
        if (scores[i]  >= threshold) {
            count++;
        }
    }
    return count;
}

void print_board(const int board[][GAMES], int nteams) {
    if (board == NULL || nteams <= 0) {
        return;
    }
    printf("Board:\n");
    for (int i = 0; i  < nteams; i++)  {
        for (int j = 0; j < GAMES; j++)  {
            printf("%-3d", board[i][j]);
        }
        printf("\n");
    }

}

int board_sum(const int board[][GAMES], int nteams) {
    if (board == NULL || nteams <= 0) {
        return 0;
    }
    int total = 0;

    for (int i = 0; i  < nteams; i++)  {
        for (int j = 0; j < GAMES; j++)  {
            total += board[i][j];
        }
        
    }

    return total;
}