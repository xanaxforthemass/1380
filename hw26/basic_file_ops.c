#include <stdio.h>

int main(void) {

    
    // Part C error test - commented out so program will not exit.
    // printf("Attempting to read missing file... \n");
    // FILE *silly_file = fopen("notThere.txt", "r");
    // if (silly_file == NULL) {
    //     perror("Error opening file");
    //     return 1;
    // }

    FILE *file = fopen("out.txt", "w");

    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }
    printf("File opened successfully\n");

    if (fprintf(file, "I'm doing it-\n") < 0) {
        perror("Error writing to file");
        fclose(file);
        return 1;
    }

    if (fprintf(file, "I'm writing to a file in C!\n") < 0) {
        perror("Error writing to file");
        fclose(file);
        return 1;
    }

    if (fclose(file) == EOF) {
        perror("Error closing file");
        return 1;
    }

    file = fopen("out.txt", "r");
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }

    // I chose a buffer size
    char line[200];
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("Line: %s\n", line);
    }

    if (fclose(file) == EOF) {
        perror("Error closing file");
        return 1;
    }

    return 0;
}