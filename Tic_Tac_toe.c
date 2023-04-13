#include<stdio.h>
#include<stdlib.h>
#define ROWS 3
#define COLS 3

char board[ROWS][COLS];
int currentPlayer = 1;

void initialize_board() {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }
}

void print_board() {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        printf("\n| ");
        for(j = 0; j < COLS; j++) {
            printf("%c | ", board[i][j]);
        }
    }
    printf("\n");
}

int check_win() {
    int i;
    for(i = 0; i < ROWS; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return 1;
        }
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return 1;
        }
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return 1;
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return 1;
    }
    return 0;
}

int check_tie() {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            if(board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

void switch_player() {
    if(currentPlayer == 1) {
        currentPlayer = 2;
    }
    else {
        currentPlayer = 1;
    }
}

void make_move() {
    int row, col;
    printf("\nPlayer %d's turn: ", currentPlayer);
    printf("\nEnter row number (0-2): ");
    scanf("%d", &row);
    printf("\nEnter column number (0-2): ");
    scanf("%d", &col);
    if(row < 0 || row >= ROWS || col < 0 || col >= COLS || board[row][col] != ' ') {
        printf("\nInvalid move. Try again.\n");
        make_move();
    }
    else {
        if(currentPlayer == 1) {
            board[row][col] = 'X';
        }
        else {
            board[row][col] = 'O';
        }
    }
}

int main() {
    int gameEnd = 0;
    int winner = 0;
    initialize_board();
    while(!gameEnd) {
        print_board();
        make_move();
        winner = check_win();
        if(winner) {
            printf("\nPlayer %d wins!\n", currentPlayer);
            gameEnd = 1;
        }
        else if(check_tie()) {
            printf("\nIt's a tie!\n");
            gameEnd = 1;
        }
        else {
            switch_player();
        }
    }
    printf("\nThanks for playing!\n");
return 0;
}
