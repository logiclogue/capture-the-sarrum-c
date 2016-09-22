typedef struct PieceTag Piece;

typedef struct GameTag {
    Piece ***board; // 2d array
    int game_over;
    int *start_square; // array
    int *finish_square; // array
    int move_is_legal;
    char play_again;
    char sample_game;
    char whose_turn;
} Game;


Game *Game_main(int);
int Game_make_move(Game *);
