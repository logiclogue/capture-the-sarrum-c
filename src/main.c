#include <stdio.h>
#include "Game.h"
#include "Piece.h"
#include "Board.h"
#include "dialog.h"
#include "game_type.h"


int main(void)
{
    Game *game = Game_main();
    
    if (dialog_sample_game()) {
        game_type_sample(game);
        Board_draw(game->board);
    }

    game->whose_turn = 'B';
    game->start_square = dialog_get_piece_coords();
    game->finish_square = dialog_get_move_coords();

    Game_make_move(game);
    Board_draw(game->board);

    return 0;
}
