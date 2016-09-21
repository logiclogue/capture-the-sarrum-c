#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "dialog.h"


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
 * Gets the start coords.
 */
int *dialog_get_piece_coords(void)
{
    char *message = "Enter coordinates of square containing piece to "
                    "move (file first):";

    return dialog_get_coords(message);
}

int *dialog_get_move_coords(void)
{
    char *message = "Enter coordinates of square to move piece to (file "
                    "first):";
    
    return dialog_get_coords(message);
}

/*
 * Gets an array of the coords in format: [file, rank].
 */
int *dialog_get_coords(char *message)
{
    int file;
    int rank;
    int *coords = malloc(2 * sizeof(int));

    printf("%s ", message);
    fflush(stdin);
    scanf(" %d , %d", &file, &rank);

    coords[0] = file;
    coords[1] = rank;

    return coords;
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
