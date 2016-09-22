typedef struct GameTag Game;

typedef struct PieceTag {
    char type;
    char colour;
} Piece;


int Piece_is_move_legal(Piece *, Game *);
int Piece_is_on_board(Piece *, Game *);
int Piece_is_redum_move_legal(Piece *, Game *);
int Piece_is_sarrum_move_legal(Piece *, Game *);
int Piece_is_gisgigir_move_legal(Piece *, Game *);
int Piece_is_nabu_move_legal(Piece *, Game *);
int Piece_is_marzaz_pani_move_legal(Piece *, Game *);
int Piece_is_etlu_move_legal(Piece *, Game *);
