typedef struct GameTag Game;

typedef struct PieceTag {
    char type;
    char colour;
    int (*is_move_legal)(Piece *, Game *);
} Piece;


Piece *Piece_main(char, char);
int Piece_is_redum_move_legal(Piece *, Game *);
int Piece_is_sarrum_move_legal(Piece *, Game *);
int Piece_is_gisgigir_move_legal(Piece *, Game *);
int Piece_is_nabu_move_legal(Piece *, Game *);
int Piece_is_marzaz_pani_move_legal(Piece *, Game *);
int Piece_is_etlu_move_legal(Piece *, Game *);
