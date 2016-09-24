#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "dialog.h"
#include "Board.h"


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
                    "move (file, rank):";

    return dialog_get_coords(message);
}

int *dialog_get_move_coords(void)
{
    char *message = "Enter coordinates of square to move piece to (file, "
                    "rank):";
    
    return dialog_get_coords(message);
}

/*
 * Gets an array of the coords in format: [file, rank].
 */
int *dialog_get_coords(char *message)
{
    int valid_coords = 0; // boolean
    int *coords = malloc(2 * sizeof(int));

    while (!valid_coords) {
        int file;
        int rank;

        printf("%s ", message);
        fflush(stdin);
        scanf(" %d , %d", &file, &rank);

        coords[0] = file;
        coords[1] = rank;

        if (file > 0 && rank > 0 && file <= BOARD_SIZE && rank <= BOARD_SIZE) {
            valid_coords = 1;
        }
    }

    coords[0] -= 1;
    coords[1] -= 1;

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
