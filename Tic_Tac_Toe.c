#include <stdio.h>
#include <stdlib.h>

#define SIZE 3
char board[SIZE][SIZE];

void initializeBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

int makeMove(int player) {
    int row, col;
    char symbol = (player == 1) ? 'X' : 'O';

    printf("Player %d (%c), enter your move (row[1-3] and column[1-3]): ", player, symbol);
    scanf("%d %d", &row, &col);
    row--;
    col--;
    if(board[row][col] != ' ')
    {
        printf("Invalid Move. You can't place Here.");
    }

    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE ) {
        printf("Invalid Position. Try again.\n");
        return 0;
    }

    board[row][col] = symbol;
    printBoard();
    return 1;
}
int checkWin() {
   
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return (board[i][0] == 'X') ? 1 : 2;
        }
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return (board[0][i] == 'X') ? 1 : 2;
        }
    }

    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return (board[0][0] == 'X') ? 1 : 2;
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return (board[0][2] == 'X') ? 1 : 2;
    }

    return 0;
}

int main() {
    int currentPlayer = 1;
    int moves = 0;
    int winner = 0;

    initializeBoard();

    printf("Welcome to Tic-Tac-Toe!\n");
    printBoard();

    while (moves < SIZE * SIZE && winner == 0) {
        if (makeMove(currentPlayer)) {
            moves++;
            winner = checkWin();
            currentPlayer = (currentPlayer == 1) ? 2 : 1;
        }
    }

    printBoard();

    if (winner) {
        printf("Player %d wins!\n", winner);
    } else {
        printf("It's a draw!\n");
    }

    return 0;
}