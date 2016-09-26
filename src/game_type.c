#include "Game.h"
#include "Piece.h"
#include "Board.h"
#include "game_type.h"


void game_type_normal(Game *game)
{
    Board board = game->board;
    
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i][1] = Piece_main('R', 'B');
        board[i][6] = Piece_main('R', 'W');
    }

    board[0][0] = Piece_main('G', 'B');
    board[7][0] = Piece_main('G', 'B');
    board[0][7] = Piece_main('G', 'W');
    board[7][7] = Piece_main('G', 'W');

    board[1][0] = Piece_main('E', 'B');
    board[6][0] = Piece_main('E', 'B');
    board[1][7] = Piece_main('E', 'W');
    board[6][7] = Piece_main('E', 'W');

    board[2][0] = Piece_main('N', 'B');
    board[5][0] = Piece_main('N', 'B');
    board[2][7] = Piece_main('N', 'W');
    board[5][7] = Piece_main('N', 'W');

    board[3][0] = Piece_main('M', 'B');
    board[3][7] = Piece_main('M', 'W');

    board[4][0] = Piece_main('S', 'B');
    board[4][7] = Piece_main('S', 'W');
}

void game_type_sample(Game *game)
{
    Board board = game->board;
    board[1][0] = Piece_main('G', 'B');
    board[3][0] = Piece_main('S', 'B');
    board[7][0] = Piece_main('G', 'W');
    board[0][1] = Piece_main('R', 'W');
    board[0][2] = Piece_main('S', 'W');
    board[1][2] = Piece_main('E', 'B');
    board[7][2] = Piece_main('E', 'B');
    board[7][5] = Piece_main('R', 'B');
}
