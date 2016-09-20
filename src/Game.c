#include <stdlib.h>
#include "Game.h"


int Game_board_size;


Game Game_main(int board_size)
{
    Game self;
    char *board[board_size][board_size];

    self.board = board;

    return self;
}
