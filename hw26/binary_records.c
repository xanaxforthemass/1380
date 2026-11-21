#include <stdio.h>

struct Player {
    int id;
    int score;
};

int main(void) {

    struct Player players[] = {{1, 5}, {2, 88}, {3, 87}, {4, 90}};

    FILE *file = fopen ("players.bin", "wb");

    if (file == NULL) {
        perror("Error opening binary file");
        return 1;
    }

    size_t player_count = sizeof(players) / sizeof(players[0]);
    size_t write_count = fwrite(players, sizeof(struct Player), player_count, file);

    if (write_count != player_count) {
        perror("Error writing binary record");
        fclose(file);
        return 1;
    }

    if (fclose(file) == EOF) {
        perror("Error closing binary file");
        return 1;
    }

    struct Player players2[player_count];

    file = fopen("players.bin", "rb");

    if (file == NULL) {
        perror("Error opening binary file");
        return 1;
    }

    size_t read_count = fread(players2, sizeof(struct Player), player_count, file);

    /* WHY: A short read means that some records might
        not get initialized. I verify the count to prevent that. */
    if (read_count != player_count) {
        if (feof(file)) {
            printf("End of file reached.\n");
        } else if (ferror(file)) {
            perror("Error reading file");
        } 
        
        fclose(file);
        return 1;
    }

    // Commented out error check so program would run
    // printf("Performing error check...");

    // size_t silly_count = fread(players2, sizeof(struct Player), 5, file);
    // if (silly_count != player_count) {
    //     if (feof(file)) {
    //         printf("End of file reached.\n");
    //     } else if (ferror(file)) {
    //         perror("Error reading file");
    //     } 
        
    //     fclose(file);
    //     return 1;
    // }


    for (size_t i = 0; i < player_count; i++) {
        printf("Player ID: %d, Score: %d\n", players2[i].id, players2[i].score);
    }    

    if (fclose(file) == EOF) {
        perror("Error closing binary file");
        return 1;
    }

    return 0;

}