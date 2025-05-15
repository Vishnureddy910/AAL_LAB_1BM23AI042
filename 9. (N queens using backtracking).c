#include <stdio.h>
#include <stdbool.h>
#define MAX 20

int board[MAX][MAX];

bool isSafe(int row, int col, int n) {
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
    for (int i = row, j = col; j >=0 && i < n; i++, j--)
        if (board[i][j])
            return false;
    return true;
}

bool solveNQueens(int col, int n) {
    if (col >= n)
        return true;
    for (int i = 0; i < n; i++) {
        if (isSafe(i, col, n)) {
            board[i][col] = 1;
            if (solveNQueens(col + 1, n))
                return true;
            board[i][col] = 0;
        }
    }
    return false;
}

void printBoard(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter number of queens: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = 0;
    if (solveNQueens(0, n))
        printBoard(n);
    else
        printf("No solution exists\n");
    return 0;
}
