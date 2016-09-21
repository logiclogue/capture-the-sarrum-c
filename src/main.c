#include <stdio.h>
#include "Game.h"
#include "dialog.h"


int main()
{
    int *coords;
    Game game = Game_main(8);
    game.board[7][7] = 'J';
    
    printf("This: %c\n", game.board[7][7]);
    dialog_sample_game();
    dialog_play_again();
    coords = dialog_get_piece_coords();
    coords = dialog_get_move_coords();

    printf("%d, %d\n", coords[0], coords[1]);

    return 0;
}
