#include <stdio.h>
#include <stdbool.h>

#define N 10

bool is_safe(int board[N][N], int row, int col) {
    // Check if there is a queen in the same column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // Check upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check upper right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

bool solve_n_queens_util(int board[N][N], int row) {
    if (row >= N) {
        return true;
    }

    for (int col = 0; col < N; col++) {
        if (is_safe(board, row, col)) {
            board[row][col] = 1;
            if (solve_n_queens_util(board, row + 1)) {
                return true;
            }
            board[row][col] = 0;
        }
    }

    return false;
}

bool solve_n_queens(int board[N][N]) {
    if (!solve_n_queens_util(board, 0)) {
        printf("Solution does not exist.\n");
        return false;
    }

    printf("Solution:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    return true;
}

int main() {
    int board[N][N] = {0};

    if (solve_n_queens(board)) {
        printf("Queens can be placed.\n");
    } else {
        printf("Queens cannot be placed.\n");
    }

    return 0;
}

