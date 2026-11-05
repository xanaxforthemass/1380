/*
 * Demonstrates string manipulation using lineup helper functions.
 * David Ross
 */
#include <stdio.h>
#include <string.h>
#include "lineup.h"

int main(void) {

    char label[] = "Super Mario Smashers";

    print_label(label);
    printf("Length of label: %d\n", label_len(label));

    char dest[30];
    safe_copy(dest, sizeof(dest), label);
    printf("Copied label: %s\n", dest);

    safe_join(dest, sizeof(dest), " 2");
    printf("Joined label: %s\n", dest);

    printf("labels_match on Matching labels: %d\n", labels_match(label, "Super Mario Smashers"));
    printf("labels_match on Different labels: %d\n", labels_match(label, dest));

    printf("Position of 'Mario' in label: %d\n", find_text(label, "Mario"));
    printf("Position of 'Zelda' in label: %d\n", find_text(label, "Zelda"));

    printf("Performing NULL check...\n");
    print_label(NULL);
    printf("Program did not crash!\n");

    return 0;
}