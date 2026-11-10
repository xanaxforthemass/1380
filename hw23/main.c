/*
 * Demonstrates struct usage using player helper functions that represent
 * players in an intramural league.
 * David Ross
 */

#include <stdio.h>
#include "player.h"

int main(void) {

    struct Player p1;
    init_player(&p1, "Captain American", 23, 10);

    struct Player p2;
    init_player(&p2, "The Hulg", 45, 15);

    printf("Player 1:\n");
    print_player(&p1);
    printf("Player 2:\n");
    print_player(&p2);

    printf("Player 1 points: %d\n", get_points(&p1));
    printf("Adding 5 points to Player 1...\n");
    add_points(&p1, 5);
    printf("Player 1 points: %d\n", get_points(&p1));

    printf("Do Player 1 and Player 2 have the same jersey number? %s\n",
        same_jersey(&p1, &p2) ? "Yes" : "No");

    printf("Changing Player 2's jersey number to 23...\n");

    init_player(&p2, "The Hulg", 23, 15);

    printf("Do Player 1 and Player 2 have the same jersey number? %s\n",
        same_jersey(&p1, &p2) ? "Yes" : "No");

    printf("Performing NULL check...\n");
    print_player(NULL);
    printf("Program did not crash!\n");

    struct Player p3;
    init_player(&p3, "Stinky", 99, 0);

    struct Player *players[] = {&p1, &p2, &p3};

    for (int i = 0; i < 3; i++) {
        printf("Player %d:\n", i + 1);
        print_player(players[i]);
    }
    return 0;
}
