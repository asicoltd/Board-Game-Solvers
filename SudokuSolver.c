#include <stdio.h>

int check(int sud[9][9], int row, int col, int num) {
    // Check the row
    for (int i = 0; i < 9; i++) {
        if (sud[row][i] == num) return 0;
    }
    // Check the column
    for (int i = 0; i < 9; i++) {
        if (sud[i][col] == num) return 0;
    }
    // Check the 3x3 sub-grid
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sud[i + startRow][j + startCol] == num) return 0;
        }
    }
    return 1;
}

int solveSudoku(int sud[9][9]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (sud[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (check(sud, row, col, num)) {
                        sud[row][col] = num;
                        if (solveSudoku(sud)) return 1;  // Recursively solve
                        sud[row][col] = 0;  // Backtrack if solution not found
                    }
                }
                return 0;  // No valid number found, backtrack
            }
        }
    }
    return 1;  // Puzzle solved
}

int main() {
    printf("\nGive Sudoku 9x9 Problem like this ( 0 means blank):\n");
    printf("0 0 1 0 0 0 0 0 0\n3 0 7 6 0 5 1 0 9\n0 5 0 0 1 0 0 8 0\n0 7 0 4 0 3 0 1 0\n0 0 9 0 0 0 5 0 0\n0 1 0 9 0 8 0 7 0\n0 4 0 0 2 0 0 6 0\n1 0 8 5 0 6 3 0 7\n0 0 0 0 0 0 0 0 0\n");
    int sud[9][9];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &sud[i][j]);
        }
    }

    if (solveSudoku(sud)) {
        printf("\nSolved Sudoku:\n");
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                printf("%d ", sud[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No solution exists\n");
    }
    return 0;
}

/*
HARDEST SAMPLE:

0 0 1 0 0 0 0 0 0
3 0 7 6 0 5 1 0 9
0 5 0 0 1 0 0 8 0
0 7 0 4 0 3 0 1 0
0 0 9 0 0 0 5 0 0
0 1 0 9 0 8 0 7 0
0 4 0 0 2 0 0 6 0
1 0 8 5 0 6 3 0 7
0 0 0 0 0 0 0 0 0
*/
