#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "Piece.h"


Game *Game_main(int board_size)
{
    Game *self = malloc(sizeof(Game));
    Piece ***board = malloc(board_size * sizeof(Piece **));

    for (int x = 0; x < board_size; x++) {
        board[x] = malloc(board_size * sizeof(Piece *));

        for (int y = 0; y < board_size; y++) {
            board[x][y] = malloc(sizeof(Piece));
            board[x][y]->type = 'M';
            board[x][y]->colour = 'W';
        }
    }

    self->board = board;

    return self;
}

int Game_make_move(Game *game)
{
    Piece ***board = game->board;
    int start_file = game->start_square[0];
    int start_rank = game->start_square[1];
    int finish_file = game->finish_square[0];
    int finish_rank = game->finish_square[1];
    Piece *piece = board[start_file][start_rank];

    printf("%d, %d\n", start_file, start_rank);
    printf("%s\n", board[start_file][start_rank]);
    
    return 0;
}
