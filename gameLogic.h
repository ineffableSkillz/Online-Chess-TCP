#ifndef __GAMELOGIC_H__
#define __GAMELOGIC_H__

#include "chessPieces.h"

#define TOTAL_SQUARES 64
#define TOTAL_COLUMNS 8

typedef enum turn {WHITE, BLACK} turn;

struct chessPiecePlace {

	int isFree;
	chessPiece *piece; // Malloc'd/Free'd after checking isFree status
}; 
typedef struct chessPiecePlace chessPiecePlace;

struct board {

	turn playerColour;

	chessPiecePlace *tiles;
	
	turn playerTurn;

	int isWhiteInCheck;
	int isBlackInCheck;
}; 
typedef struct board board;

void board_setup(board *table, int isWhite);

void update_king_status(chessPiece *king);

int is_my_turn(turn playerTurn);

int is_king_in_check(chessPiece *king);

chessPiecePlace new_chess_piece_place();

#endif