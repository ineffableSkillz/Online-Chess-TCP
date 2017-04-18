#ifndef __CHESSPIECES_H__
#define __CHESSPIECES_H__

#include <stdlib.h>

typedef enum pieceType {KING, QUEEN, BISHOP, ROOK, PAWN, KNIGHT} pieceType;

struct piece {

	/* Stores the type of pieve */	
	pieceType type;

	/* Current Position */
	int xPos;
	int yPos;

	/* Possible Moves - Initialised in method [Pawn & Knight]*/
	int xMoves[4];
	int yMoves[4];

	/* Piece's First Move */
	int hasMoved;

	/* Is piece in check - Only for king */
	int isInCheck;

};
typedef struct piece chessPiece;

chessPiece new_pawn(int x, int y);

chessPiece new_knight(int x, int y);

chessPiece new_rook(int x, int y);

chessPiece new_bishop(int x, int y);

chessPiece new_queen(int x, int y);

chessPiece new_king(int x, int y); 	

/* int x, int y - Chosen place to move to */
/* int x, int y - Are checked to be valid bored move */
int isLegalMove(chessPiece piece, int x, int y); //Passing byVal as not changing any information

/* int x, int y - Goal */
int calculate_diagonals(int currentX, int currentY, int x, int y);

int calculate_horizontals(int currentX, int currentY, int x , int y);

#endif