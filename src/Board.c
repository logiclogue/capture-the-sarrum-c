#include <stdio.h>
#include <stdlib.h>
#include "Piece.h"
#include "Board.h"


#define BOARD_SIZE 8


/*
 * Board constructor,
 */
Board Board_main(void)
{
    Board board = malloc(BOARD_SIZE * sizeof(Piece **));

    for (int x = 0; x < BOARD_SIZE; x++) {
        board[x] = malloc(BOARD_SIZE * sizeof(Piece *));

        for (int y = 0; y < BOARD_SIZE; y++) {
            board[x][y] = malloc(sizeof(Piece));
            board[x][y]->type = 'M';
            board[x][y]->colour = 'W';
        }
    }

    return board;
}

/*
 * Draws the board to console.
 */
void Board_draw(Board *self)
{
    int line_size = 4 + (3 * BOARD_SIZE);
    char *line = malloc(line_size * sizeof(char));

    sprintf(line, "%s", "    ");

    for (int i = 0; i < BOARD_SIZE; i++) {
        sprintf(line, "  %d", i);
    }
}
