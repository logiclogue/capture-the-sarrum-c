#include <stdio.h>
#include "Game.h"
#include "Piece.h"
#include "Board.h"
#include "dialog.h"
#include "game_type.h"


int main(void)
{
    Game *game = Game_main();
    game->whose_turn = 'W';
    
    if (dialog_sample_game()) {
        game_type_sample(game);
    } else {
        game_type_normal(game);
    }

    Board_draw(game->board);

    while (1) {
        Game_print_whose_turn(game);

        game->start_square = dialog_get_piece_coords();
        game->finish_square = dialog_get_move_coords();

        Game_make_move(game);
        Board_draw(game->board);

        if (Game_make_move(game)) {
            Game_switch_turn(game);
        }
    }

    return 0;
}
