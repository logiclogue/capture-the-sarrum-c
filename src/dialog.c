#include <stdio.h>
#include <ctype.h>


static int yes_or_no(void);


/*
 * Asks whether wanted to play the sample game.
 * Boolean, whether selects to play the sample game.
 */
int dialog_sample_game(void)
{
    printf("Do you want to play the sample game (enter Y for Yes)? ");

    return yes_or_no();
}

/*
 * Asks whether the user wants to play again.
 * Boolean, whether selects to play again.
 */
int dialog_play_again(void)
{
    printf("Do you want to play again (enter Y for Yes)? ");

    return yes_or_no();
}


/*
 * Simple yes or no. Confirm by 'Y'.
 */
static int yes_or_no(void)
{
    char selection;

    fflush(stdin);
    scanf(" %c", &selection);

    if (selection == 'Y' || selection - 32 == 'Y') {
        return 1;
    }
    
    return 0;
}
