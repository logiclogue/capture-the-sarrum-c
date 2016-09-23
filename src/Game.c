#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "Piece.h"
#include "Board.h"


Game *Game_main(void)
{
    Game *self = malloc(sizeof(Game));
    Board board = Board_main();

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

    return 0;
}
