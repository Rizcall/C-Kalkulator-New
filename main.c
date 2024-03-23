#include <stdio.h>

char board[3][3]; // 3x3 tic-tac-toe board

// Function to initialize the board
void initialize_board() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = '-';
        }
    }
}

// Function to print the board
void print_board() {
    int i, j;
    printf("\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the move is valid
int is_valid_move(int row, int col) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != '-') {
        return 0;
    }
    return 1;
}

// Function to check if there is a winner
char check_winner() {
    int i;

    // Check rows
    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-') {
            return board[i][0];
        }
    }

    // Check columns
    for (i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '-') {
            return board[0][i];
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-') {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '-') {
        return board[0][2];
    }

    // If no winner, return '-'
    return '-';
}

int main() {
    int row, col, player = 1, total_moves = 0;
    char symbol;

    initialize_board();

    while (1) {
        printf("Player %d's turn:\n", player);
        print_board();

        // Get player's move
        printf("Enter row and column (0-2): ");
        scanf("%d %d", &row, &col);

        // Validate move
        if (!is_valid_move(row, col)) {
            printf("Invalid move! Try again.\n");
            continue;
        }

        // Determine player's symbol
        symbol = (player == 1) ? 'X' : 'O';

        // Make the move
        board[row][col] = symbol;
        total_moves++;

        // Check for a winner
        char winner = check_winner();
        if (winner != '-') {
            printf("Player %d wins!\n", player);
            print_board();
            break;
        }

        // If all cells are filled, it's a draw
        if (total_moves == 9) {
            printf("It's a draw!\n");
            print_board();
            break;
        }

        // Switch to the other player
        player = (player == 1) ? 2 : 1;
    }

    return 0;
}
