#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "Piece.h"
#include "Board.h"
#include "dialog.h"
#include "game_type.h"


static void play(Game *);


int main(void)
{
    Game *game = Game_main();
    
    play(game);

    return 0;
}


static void play(Game *game)
{
    if (dialog_sample_game()) {
        game_type_sample(game);
    } else {
        game_type_normal(game);
    }

    Board_draw(game->board);

    while (!game->game_over) {
        Game_print_whose_turn(game);
        Game_query_move(game);

        if (!game->game_over) {
            Board_draw(game->board);
        } else if (dialog_play_again()) {
            free(game);
            play(Game_main());
        }
    }
}
