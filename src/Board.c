#include <stdlib.h>
#include "Piece.h"
#include "Board.h"


Board Board_main(int board_size)
{
    Board board = malloc(board_size * sizeof(Piece **));

    for (int x = 0; x < board_size; x++) {
        board[x] = malloc(board_size * sizeof(Piece *));

        for (int y = 0; y < board_size; y++) {
            board[x][y] = malloc(sizeof(Piece));
            board[x][y]->type = 'M';
            board[x][y]->colour = 'W';
        }
    }

    return board;
}
