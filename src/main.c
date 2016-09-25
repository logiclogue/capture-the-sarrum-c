#include <stdio.h>
#include "Game.h"
#include "Piece.h"
#include "Board.h"
#include "dialog.h"


int main(void)
{
    Game *game = Game_main();
    game->board[6][6] = Piece_main('M', 'W');
    game->board[5][5] = Piece_main('R', 'B');
    game->board[6][5] = Piece_main('S', 'B');
    game->board[5][6] = Piece_main('G', 'B');
    
    Board_draw(game->board);

    dialog_sample_game();
    dialog_play_again();
    game->start_square = dialog_get_piece_coords();
    game->finish_square = dialog_get_move_coords();

    printf("%d, %d\n", game->start_square[0], game->start_square[1]);
    printf("%d, %d\n", game->finish_square[0], game->finish_square[1]);

    game->whose_turn = 'B';

    Game_make_move(game);
    Board_draw(game->board);


    return 0;
}
