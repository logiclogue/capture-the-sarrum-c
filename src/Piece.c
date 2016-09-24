#include <stdlib.h>
#include "Game.h"
#include "Piece.h"


static int return_false(Piece *, Game *);
static int is_empty_square(Piece *);


Piece *Piece_main(char type, char colour)
{
    Piece *self = malloc(sizeof(Piece));

    self->type = type;
    self->colour = colour;

    switch (self->type) {
    case 'R':
        self->is_move_legal = &Piece_is_redum_move_legal;
        break;
    case 'S':
        self->is_move_legal = &Piece_is_sarrum_move_legal;
        break;
    case 'G':
        self->is_move_legal = &Piece_is_gisgigir_move_legal;
        break;
    case 'N':
        self->is_move_legal = &Piece_is_nabu_move_legal;
        break;
    case 'M':
        self->is_move_legal = &Piece_is_marzaz_pani_move_legal;
        break;
    case 'E':
        self->is_move_legal = &Piece_is_etlu_move_legal;
        break;
    default:
        self->is_move_legal = &return_false;
        break;
    }
    
    return self;
}

int Piece_is_redum_move_legal(Piece *self, Game *game)
{
    char colour = self->colour;
    char opponent_colour;
    int start_file = game->start_square[0];
    int start_rank = game->start_square[1];
    int finish_file = game->finish_square[0];
    int finish_rank = game->finish_square[1];
    int forward_square = 1;
    int does_move_sideways = abs(finish_file - start_file) == 1;
    int does_move_forward;
    int does_move_diagonal;
    int is_same_file = finish_file == start_file;
    Piece *capture_piece = game->board[finish_file][finish_rank];
    int is_empty_capture_piece = is_empty_square(capture_piece);
    int is_capture_piece_opponent;

    if (colour == 'W') {
        forward_square = -1;
        opponent_colour = 'B';
    } else {
        opponent_colour = 'W';
    }

    does_move_forward = finish_rank == start_rank + forward_square;
    is_capture_piece_opponent = capture_piece->colour == opponent_colour;
    does_move_diagonal = does_move_forward && does_move_sideways;

    return (does_move_forward && is_same_file && is_empty_capture_piece) ||
           (does_move_diagonal && is_capture_piece_opponent);
}

int Piece_is_sarrum_move_legal(Piece *self, Game *game)
{
    return 0;
}

int Piece_is_gisgigir_move_legal(Piece *self, Game *game)
{
    return 0;
}

int Piece_is_nabu_move_legal(Piece *self, Game *game)
{
    return 0;
}

int Piece_is_marzaz_pani_move_legal(Piece *self, Game *game)
{
    return 1;
}

int Piece_is_etlu_move_legal(Piece *self, Game *game)
{
    return 0;
}


static int return_false(Piece *self, Game *game)
{
    return 0;
}

static int is_empty_square(Piece *piece)
{
    return piece->type == ' ' && piece->colour == ' ';
}
