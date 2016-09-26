#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "Piece.h"
#include "Board.h"
#include "dialog.h"


static int is_off(int);
static void make_move(Game *);
static int is_legal_move(Game *);


Game *Game_main(void)
{
    Game *self = malloc(sizeof(Game));
    Board board = Board_main();

    self->board = board;
    self->game_over = 0;
    self->whose_turn = 'W';

    return self;
}

void Game_query_move(Game *game)
{
    Game_collect_move(game);

    while (!Game_make_move(game)) {
        printf("That is not a legal move - please try again\n");

        Game_collect_move(game);
    }

    Game_switch_turn(game);
}

int Game_make_move(Game *game)
{
    int is_move = is_legal_move(game);

    if (is_move) {
        make_move(game);
    }

    return is_move;
}

void Game_collect_move(Game *game)
{
    game->start_square = dialog_get_piece_coords();
    game->finish_square = dialog_get_move_coords();
}

void Game_print_whose_turn(Game *game)
{
    if (game->whose_turn == 'W') {
        printf("It is White's turn\n");
    } else {
        printf("It is Black's turn\n");
    }
}

void Game_switch_turn(Game *game)
{
    if (game->whose_turn == 'W') {
        game->whose_turn = 'B';
    } else {
        game->whose_turn = 'W';
    }
}


static int is_legal_move(Game *game)
{
    Piece ***board = game->board;
    int start_file = game->start_square[0];
    int start_rank = game->start_square[1];
    int finish_file = game->finish_square[0];
    int finish_rank = game->finish_square[1];
    Piece *piece = board[start_file][start_rank];
    Piece *capture_piece = board[finish_file][finish_rank];

    int is_same_file = start_file == finish_file;
    int is_same_rank = start_rank == finish_rank;
    int is_different_square = !is_same_file || !is_same_rank;
    int is_file_off = is_off(start_file) || is_off(finish_file);
    int is_rank_off = is_off(start_rank) || is_off(finish_rank);
    int is_on_board = !is_file_off && !is_rank_off;
    int is_your_move = piece->colour == game->whose_turn;
    int is_legal = piece->is_move_legal(piece, game);
    int is_capture_piece_yours = capture_piece->colour == game->whose_turn;

    return is_different_square && is_on_board && is_your_move && is_legal &&
           !is_capture_piece_yours;
}

static void make_move(Game *game)
{
    int start_file = game->start_square[0];
    int start_rank = game->start_square[1];
    int finish_file = game->finish_square[0];
    int finish_rank = game->finish_square[1];

    Piece *start_square = game->board[start_file][start_rank];

    game->board[finish_file][finish_rank] = start_square;
    game->board[start_file][start_rank] = Piece_main(' ', ' ');
}

static int is_off(int rank_file)
{
    return rank_file < 0 || rank_file >= BOARD_SIZE;
}
