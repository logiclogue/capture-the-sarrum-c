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
    int start_file = game->start_square[0];
    int start_rank = game->start_square[1];
    int finish_file = game->finish_square[0];
    int finish_rank = game->finish_square[1];

    int squares_vertical = abs(finish_file - start_file);
    int squares_horizontal = abs(finish_rank - start_rank);

    return squares_vertical <= 1 && squares_horizontal <= 1;
}

int Piece_is_gisgigir_move_legal(Piece *self, Game *game)
{
    int start_file = game->start_square[0];
    int start_rank = game->start_square[1];
    int finish_file = game->finish_square[0];
    int finish_rank = game->finish_square[1];

    int is_move_legal = 0;
    int count = 0;
    int rank_difference = finish_rank - start_rank;
    int file_difference = finish_file - start_file;
    Piece *piece;

    if (rank_difference == 0) { // is moving horizontal
        if (file_difference >= 1) {
            is_move_legal = 1;
            
            for (count = 1; count < file_difference; count++) {
                piece = game->board[start_file + count][start_rank];

                if (!is_empty_square(piece)) {
                    is_move_legal = 0;
                }
            }
        } else if (file_difference <= -1) {
            is_move_legal = 1;

            for (count = -1; count > file_difference; count--) {
                piece = game->board[start_file + count][start_rank];

                if (!is_empty_square(piece)) {
                    is_move_legal = 0;
                }
            }
        }
    } else if (file_difference == 0) { // is moving vertical
        if (rank_difference >= 1) {
            is_move_legal = 1;

            for (count = 1; count < rank_difference; count++) {
                piece = game->board[start_file][start_rank + count];

                if (!is_empty_square(piece)) {
                    is_move_legal = 0;
                }
            }
        } else if (rank_difference <= -1) {
            is_move_legal = 1;

            for (count = -1; count > rank_difference; count--) {
                piece = game->board[start_file][start_rank + count];

                if (!is_empty_square(piece)) {
                    is_move_legal = 0;
                }
            }
        }
    }

    return is_move_legal;
}

int Piece_is_nabu_move_legal(Piece *self, Game *game)
{
    int file_difference = game->finish_square[0] - game->start_square[0];
    int rank_difference = game->finish_square[1] - game->start_square[1];

    return abs(file_difference) == 1 && abs(rank_difference) == 1;
}

int Piece_is_marzaz_pani_move_legal(Piece *self, Game *game)
{
    int file_difference = game->finish_square[0] - game->start_square[0];
    int rank_difference = game->finish_square[1] - game->start_square[1];

    int abs_file_difference = abs(file_difference);
    int abs_rank_difference = abs(rank_difference);

    return (abs_file_difference == 1 && abs_rank_difference == 0) ||
           (abs_file_difference == 0 && abs_rank_difference == 1);
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
