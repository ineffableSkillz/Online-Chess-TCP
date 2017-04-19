#ifndef __GAMELOGIC_H__
#define __GAMELOGIC_H__

#include "chessPieces.h"

#define TOTAL_SQUARES 64
#define TOTAL_COLUMNS 8
#define TOTAL_ROWS 8

struct chessPiecePlace {

	int isFree;
	chessPiece *piece; // Malloc'd/Free'd after checking isFree status
}; 
typedef struct chessPiecePlace chessPiecePlace;

/* Bottom left is 0,0 */
struct board {

	colour playerColour;

	chessPiecePlace *tiles;
	
	colour playerTurn;

	int isWhiteInCheck;
	int isBlackInCheck;
}; 
typedef struct board board;

void board_setup(board *table, int isWhite);

void update_king_status(chessPiece *king);

void place_piece(board *table, chessPiece *piece, int row, int column);

int is_my_turn(colour playerTurn);

int is_king_in_check(chessPiece *king);

int get_array_position(unsigned row, unsigned col);

chessPiecePlace new_chess_piece_place();

#endif