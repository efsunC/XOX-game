#include <stdio.h>

//invoked to create the game board.
void initialize_Game_Board(char board[][3]) {
    char count = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = count;
            count++;
        }
    }
}

// Update the game board.
int update_Game_Board(char board[][3], int player, int position) {
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    
	//This statement checks the suitability of the desired position.
    if (board[row][col] == 'X' || board[row][col] == 'O') {
        printf("That position is already occupied. Please try again.\n");
        return 0;
    }

    // Update the board with player's mark.
    char mark = (player == 1) ? 'X' : 'O';
    board[row][col] = mark;
    return 1;
}

void show_Game_Board(char board[][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) {
                printf("|");
            }
        }
        printf("\n");
        if (i < 2) {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

int check_for_Win(char board[][3]) {
    int i, j;

    // Check rows
    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }

    // Check columns
    for (j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return board[0][j];
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }

    // If no winner, return 0
    return 0;
}

// Start the game
void start_Game() {
    char board[3][3];
    int player = 1;
    int position;
    int game_over = 0;
	char mark;
    initialize_Game_Board(board);

    while (!game_over) {
        // Show the board
        show_Game_Board(board);
		mark = (player == 1) ? 'X' : 'O';
        // Get player's move
        printf("Player %d's turn. Enter a position (%c): ", player,mark);
        scanf("%d", &position);

        // Update the board
        int result = update_Game_Board(board, player, position);
        if (!result) {
            continue;
        }

        int winner = check_for_Win(board);
		if (winner == 'X') {
			printf("Player 1 wins!\n");
			game_over = 1;
		} else if (winner == 'O') {
			printf("Player 2 wins!\n");
			game_over = 1;
		} else {
		// Check for a draw
			int count = 0;
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						if (board[i][j] == 'X' || board[i][j] == 'O') {
						count++;
						}
					}
				}
			if (count == 9) {
				printf("It's a draw!\n");
				game_over = 1;
			} else {
		// Switch to the other player
			player = (player == 1) ? 2 : 1;
			}
		}
	}
}
