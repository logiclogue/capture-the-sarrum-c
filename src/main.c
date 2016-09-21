#include <stdio.h>
#include "Game.h"


int main()
{
    Game game = Game_main(8);
    game.board[7][7] = 'J';
    
    printf("This: %c\n", game.board[7][7]);

    return 0;
}
