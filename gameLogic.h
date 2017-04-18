#ifndef __GAMELOGIC_H__
#define __GAMELOGIC_H__

#include "chessPieces.h"

#define TOTAL_SQUARES 64

typedef enum turn {WHITE, BLACK} turn;

struct board {

	turn playerColour;

	piece *tiles;
	
	turn playerTurn;

	int isWhiteInCheck;
	int isBlackInCheck;
}
typedef struct board board;

void board_setup(board *table);

void update_king_status(chessPiece *king);

int is_my_turn(turn playerTurn)

int is_king_in_check(chessPiece *king);

#endif