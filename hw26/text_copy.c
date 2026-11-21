#include <stdio.h>

int main(void) {
    FILE *input_file = fopen("sample.txt",  "r");

     if (input_file == NULL) {
        perror("Error opening input file");
        return 1;
    }

    FILE *output_file = fopen("output.txt", "w");

    if (output_file == NULL) {
        perror("Error opening output file");
        fclose(input_file);
        return 1;
    }

    int line_count = 0;
    char line[200];
    while (fgets(line, sizeof(line), input_file) != NULL) {
        fputs(line, output_file);
        line_count++;
    }

    if (fclose(input_file) == EOF) {
        perror("Error closing file");
        return 1;
    }

    if (fclose(output_file) == EOF) {
        perror("Error closing file");
        return 1;
    }

    printf("%d lines successfully copied.\n", line_count);

    return 0;
}