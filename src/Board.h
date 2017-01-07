#ifndef _BOARD_H_
#define _BOARD_H_
#define BOARD_SIZE 8
#define BOARD_LINE_SIZE 6 + (3 * BOARD_SIZE)


typedef struct PieceTag Piece;

typedef Piece ***Board;


Board Board_main(void);
void Board_draw(Board);

#endif
