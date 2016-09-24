#include <stdio.h>
#include <stdlib.h>
#include "Piece.h"
#include "Board.h"


#define BOARD_SIZE 8
#define BOARD_LINE_SIZE 4 + (3 * BOARD_SIZE)


static char *draw_header(void);
static char *draw_line(void);
static void draw_pieces(Board, int);
static char *allocate_line(void);


/*
 * Board constructor,
 */
Board Board_main(void)
{
    Board board = malloc(BOARD_SIZE * sizeof(Piece **));

    for (int x = 0; x < BOARD_SIZE; x++) {
        board[x] = malloc(BOARD_SIZE * sizeof(Piece *));

        for (int y = 0; y < BOARD_SIZE; y++) {
            board[x][y] = malloc(sizeof(Piece));
            board[x][y]->type = 'M';
            board[x][y]->colour = 'W';
        }
    }

    return board;
}

/*
 * Draws the board to console.
 */
void Board_draw(Board self)
{
    char *line = draw_line();
    char *header = draw_header();

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%s", line);
        draw_pieces(self, i);
    }

    printf("%s\n%s", line, header);

    free(line);
    free(header);
}


static char *draw_header(void)
{
    char *line = allocate_line();

    sprintf(line, "%s", "   ");

    for (int i = 0; i < BOARD_SIZE; i++) {
        sprintf(line, "%s  %d", line, i);
    }

    sprintf(line, "%s\n", line);

    return line;
}

static char *draw_line(void)
{
    char *line = allocate_line();

    sprintf(line, "%s", "   ");

    for (int i = 0; i < BOARD_SIZE; i++) {
        sprintf(line, "%s___", line);
    }

    sprintf(line, "%s_\n", line);

    return line;
}

static void draw_pieces(Board self, int rank)
{
    char *line = allocate_line();

    sprintf(line, "%d  ", rank);

    for (int i = 0; i < BOARD_SIZE; i++) {
        Piece *piece = self[i][rank];

        sprintf(line, "%s|%c%c", line, piece->type, piece->colour);
    }

    printf("%s|\n", line);
    free(line);
}

static char *allocate_line(void)
{
    return malloc(BOARD_LINE_SIZE * sizeof(char));
}
