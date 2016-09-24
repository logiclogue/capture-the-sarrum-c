#include <stdio.h>
#include <stdlib.h>
#include "Piece.h"
#include "Board.h"


#define BOARD_SIZE 8
#define BOARD_LINE_SIZE 4 + (3 * BOARD_SIZE)


static void draw_header(void);
static void draw_line(void);
static void draw_pieces(Board, int);


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
    draw_header();
    draw_line();
    draw_pieces(self, 0);
}


static void draw_header(void)
{
    char *line = malloc(BOARD_LINE_SIZE * sizeof(char));

    sprintf(line, "%s", "   ");

    for (int i = 0; i < BOARD_SIZE; i++) {
        sprintf(line, "%s  %d", line, i);
    }

    printf("%s\n", line);
    free(line);
}

static void draw_line(void)
{
    char *line = malloc(BOARD_LINE_SIZE * sizeof(char));

    sprintf(line, "%s", "   ");

    for (int i = 0; i < BOARD_SIZE; i++) {
        sprintf(line, "%s___", line);
    }

    printf("%s\n", line);
    free(line);
}

static void draw_pieces(Board self, int rank)
{
    char *line = malloc(BOARD_LINE_SIZE * sizeof(char));

    sprintf(line, "%d  |", rank);

    for (int i = 0; i < BOARD_SIZE; i++) {
        Piece *piece = self[i][rank];

        sprintf(line, "%s%c%c|", line, piece->type, piece->colour);
    }

    printf("%s\n", line);
    free(line);
}
