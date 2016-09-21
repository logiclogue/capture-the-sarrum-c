#include <stdio.h>
#include "Game.h"
#include "dialog.h"


int main()
{
    Game game = Game_main(8);
    game.board[7][7] = 'J';
    
    printf("This: %c\n", game.board[7][7]);
    dialog_sample_game();
    dialog_play_again();

    return 0;
}
