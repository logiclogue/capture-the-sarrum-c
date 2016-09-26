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
    } else {
        game_type_normal(game);
    }

    Board_draw(game->board);

    while (!game->game_over) {
        Game_print_whose_turn(game);

        Game_query_move(game);
        Board_draw(game->board);
    }

    return 0;
}
