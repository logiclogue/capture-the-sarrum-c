#include <stdio.h>
#include "Game.h"
#include "Piece.h"
#include "Board.h"
#include "dialog.h"


int main(void)
{
    Game *game = Game_main();
    game->board[7][7] = Piece_main('M', 'W');
    
    Board_draw(game->board);

    dialog_sample_game();
    dialog_play_again();
    game->start_square = dialog_get_piece_coords();
    game->finish_square = dialog_get_move_coords();

    printf("%d, %d\n", game->start_square[0], game->start_square[1]);
    printf("%d, %d\n", game->finish_square[0], game->finish_square[1]);

    game->whose_turn = 'W';

    Game_make_move(game);
    Board_draw(game->board);


    return 0;
}
