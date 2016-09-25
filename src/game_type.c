#include "Game.h"
#include "Piece.h"
#include "Board.h"
#include "game_type.h"


void game_type_normal(Game *game)
{
    
}

void game_type_sample(Game *game)
{
    Board board = game->board;
    board[0][1] = Piece_main('G', 'B');
    board[0][3] = Piece_main('S', 'B');
    board[0][7] = Piece_main('G', 'W');
    board[1][0] = Piece_main('R', 'W');
    board[2][0] = Piece_main('S', 'W');
    board[2][1] = Piece_main('E', 'B');
    board[2][7] = Piece_main('E', 'B');
    board[5][7] = Piece_main('R', 'B');
}
