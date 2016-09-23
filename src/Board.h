#ifndef _BOARD_H_
#define _BOARD_H_

#include "Piece.h"


typedef struct PieceTag Piece;

typedef Piece ***Board;


Board Board_main(void);
void Board_draw(Board *);

#endif
