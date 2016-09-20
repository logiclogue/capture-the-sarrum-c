int Game_board_size;


typedef struct GameTag {
    char **board;
    int game_over;
    int start_square;
    int finish_square;
    int start_rank;
    int start_file;
    int finish_rank;
    int finish_file;
    int move_is_legal;
    char play_again;
    char sample_game;
    char whose_turn;
} Game;


Game Game_main(int);
