/*
 * Implements helper functions for printing and manipulating team names
 * David Ross
 */
#include <stdio.h>
#include "roster.h"

int main(void) {
    char team1_name[] = "Stinky Beans";
    char team2_name[] = "Princess Pineapple";

    print_team(team1_name);
    print_team(team2_name);

    printf("First letter of team 1: %c\n", team1_name[0]);

    printf("Length of team 1: %d\n", team_len(team1_name));
    printf("Length of team 2: %d\n", team_len(team2_name));

    char team1_copy[20];

    printf("Copying team 1 name to team1_copy[20]...\n");
    team_copy(team1_copy, 20, team1_name);
    print_team(team1_copy);

    char team2_copy[4];

    printf("Copying team 2 name to team2_copy[4]...\n");
    team_copy(team2_copy, 4, team2_name);
    print_team(team2_copy);

    printf("Comparing team 1 and team1_copy: %d\n", team_same(team1_name, team1_copy));
    printf("Comparing team 2 and team2_copy: %d\n", team_same(team2_name, team2_copy));

    shout(team1_copy);
    printf("Shouting team 1 copy: %s\n", team1_copy);

    printf("Null check using print_team(NULL):\n");
    print_team(NULL);
    printf("Program did not crash! :D\n");

    return 0;
}