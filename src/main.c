#include <stdio.h>
#include "Game.h"
#include "Piece.h"
#include "dialog.h"


int main()
{
    Game *game = Game_main(8);
    Piece piece = {'M', 'W'};
    *game->board[7][7] = piece;
    
    printf("This: %c\n", game->board[7][7]->type);
    dialog_sample_game();
    dialog_play_again();
    game->start_square = dialog_get_piece_coords();
    game->finish_square = dialog_get_move_coords();

    printf("%d, %d\n", game->start_square[0], game->start_square[1]);
    printf("%d, %d\n", game->finish_square[0], game->finish_square[1]);

    Game_make_move(game);

    return 0;
}
