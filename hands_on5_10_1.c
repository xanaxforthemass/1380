#include <stdio.h>

int main(void) {

    int scores[5] = {88, 74, 95, 82, 91};
    int size = sizeof(scores) / sizeof(scores[0]);
    int sum  = 0;

    printf("Scores:\n");

    for (int i = 0; i < size; i++)  {
        printf("%d ", scores[i]);
        sum += scores[i];
    }

    printf("\nSum: %d\n", sum);
    printf("Average: %.2f\n", (float) sum / size);
    printf("Number of scores: %d\n", size);

    int grid[3][3] = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };

    int row_size = sizeof(grid) / sizeof(grid[0]);
    int col_size = sizeof(grid[0]) / sizeof(grid[0][0]);

    printf("Grid dimensions: %d rows x %d columns\n", row_size, col_size);
    printf("Total  elements in grid: %d\n", row_size * col_size);

    for (int i = 0; i < row_size; i++) {
        for (int j = 0; j < col_size; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}