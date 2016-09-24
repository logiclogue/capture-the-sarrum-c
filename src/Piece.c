#include "stdlib.h"
#include "Game.h"
#include "Piece.h"


static int return_false(Piece *, Game *);


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
    return 0;
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
