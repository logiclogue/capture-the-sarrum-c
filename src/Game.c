#include <stdio.h>
#include <stdlib.h>
#include "Game.h"


Game Game_main(int board_size)
{
    Game self;
    char **board = malloc(board_size);

    for (int x = 0; x < board_size; x++) {
        board[x] = malloc(board_size * sizeof(char));

        for (int y = 0; y < board_size; y++) {
            board[x][y] = '#';
        }
    }

    self.board = board;

    return self;
}
