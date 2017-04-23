#include "chessPieces.h"

chessPiece *new_pawn(int x, int y, colour allegiance) {

	chessPiece* tempPiece; //Pointer to a new piece struct
	tempPiece = malloc(sizeof(chessPiece)); //Dynamic memory allocation

	/* Setting Initial Location */
	tempPiece->xPos = x;
	tempPiece->yPos = y;

	/* Setting Piece Type */
	tempPiece->type = PAWN;

	/* Setting Legal MoveS */
	tempPiece->xMoves[0] = 0; // Two steps forward
	tempPiece->xMoves[1] = 0; // One step forward
	tempPiece->xMoves[2] = 1; //	Right diagonal
	tempPiece->xMoves[3] = -1; // Left diagonal

	tempPiece->yMoves[0] = 2;
	tempPiece->yMoves[1] = 1;
	tempPiece->yMoves[2] = 1;
	tempPiece->yMoves[3] = 1;

	/* Setting hasMoved */
	tempPiece->hasMoved = 0;

	/* Setting Colour */
	tempPiece->allegiance = allegiance;

	return tempPiece;
}

chessPiece *new_knight(int x, int y, colour allegiance) {

	chessPiece* tempPiece; //Pointer to a new piece struct
	tempPiece = malloc(sizeof(chessPiece)); //Dynamic memory allocation

	/* Setting Initial Location */
	tempPiece->xPos = x;
	tempPiece->yPos = y;

	/* Setting Piece Type */
	tempPiece->type = KNIGHT;

	/* Setting Legal MoveS */
	tempPiece->xMoves[0] = 1; // Up right
	tempPiece->xMoves[1] = 1; // Down right
	tempPiece->xMoves[2] = -1; // Up left
	tempPiece->xMoves[3] = -1; // Down left

	tempPiece->yMoves[0] = 2;
	tempPiece->yMoves[1] = -2;
	tempPiece->yMoves[2] = 2;
	tempPiece->yMoves[3] = -2;

	/* Setting Colour */
	tempPiece->allegiance = allegiance;

	return tempPiece;
}

chessPiece *new_rook(int x, int y, colour allegiance) {

	chessPiece* tempPiece; //Pointer to a new piece struct
	tempPiece = malloc(sizeof(chessPiece)); //Dynamic memory allocation

	/* Setting Initial Location */
	tempPiece->xPos = x;
	tempPiece->yPos = y;

	/* Setting Piece Type */
	tempPiece->type = ROOK;

	/* Setting Colour */
	tempPiece->allegiance = allegiance;

	return tempPiece;
}

chessPiece *new_bishop(int x, int y, colour allegiance) {

	chessPiece* tempPiece; //Pointer to a new piece struct
	tempPiece = malloc(sizeof(chessPiece)); //Dynamic memory allocation

	/* Setting Initial Location */
	tempPiece->xPos = x;
	tempPiece->yPos = y;

	/* Setting Piece Type */
	tempPiece->type = BISHOP;

	/* Setting Colour */
	tempPiece->allegiance = allegiance;

	return tempPiece;
}

chessPiece *new_queen(int x, int y, colour allegiance) {

	chessPiece* tempPiece; //Pointer to a new piece struct
	tempPiece = malloc(sizeof(chessPiece)); //Dynamic memory allocation

	/* Setting Initial Location */
	tempPiece->xPos = x;
	tempPiece->yPos = y;

	/* Setting Piece Type */
	tempPiece->type = QUEEN;

	/* Setting Colour */
	tempPiece->allegiance = allegiance;

	return tempPiece;
}

chessPiece *new_king(int x, int y, colour allegiance) {

	chessPiece* tempPiece; //Pointer to a new piece struct
	tempPiece = malloc(sizeof(chessPiece)); //Dynamic memory allocation

	/* Setting Initial Location */
	tempPiece->xPos = x;
	tempPiece->yPos = y;

	/* Setting Piece Type */
	tempPiece->type = KING;

	/* Setting hasMoved */
	tempPiece->hasMoved = 0;

	/* Setting isInCheck */
	tempPiece->isInCheck = 0;

	/* Setting Colour */
	tempPiece->allegiance = allegiance;
	
	return tempPiece;
}

int calculate_diagonals(int currentX, int currentY, int destX, int destY) {

	int tempX;
	int tempY;

	/* Top Right Diagonal */ 
	if(destX > currentX && destY > currentY) {

		for(int i = 1; i <= 7; i++) {

			tempX = currentX + i;
			tempY = currentY + i;

			/* If wasn't the user's move */
			if((tempX > 8) || (tempY > 8))
				return 0;

			/* If it is the user's move */
			if(tempX == destX && tempY == destY) {

				for(int iter = 1; iter <= i; iter++) {
					//If currentX/Y + i has a piece, return false [Adjust for further methods]
				}

				return 1;
			}
		}
	} 

	/* Top Left Diagonal */ 
	else if(destX < currentX && destY > currentY) {
		for(int i = 1; i <= 7; i++) {

			tempX = currentX - i;
			tempY = currentY + i;

			/* If wasn't the user's move */
			if((tempX > 8) || (tempY > 8))
				return 0;

			/* If it is the user's move */
			if(tempX == destX && tempY == destY)
				return 1;
		}
	}

	/* Bottom Right Diagonal */
	else if(destX > currentX && destY < currentY) {
		for(int i = 1; i <= 7; i++) {

			tempX = currentX + i;
			tempY = currentY - i;

			/* If wasn't the user's move */
			if((tempX < 1) || (tempY < 1))
				return 0;

			/* If it is the user's move */
			if(tempX == destX && tempY == destY)
				return 1;
		}
	}

	/* Bottom Left Diagonal */
	else if(destX < currentX && destY < currentY) {
		for(int i = 1; i <= 7; i++) {

			tempX = currentX - i;
			tempY = currentY - i;

			/* If wasn't the user's move */
			if((tempX < 1) || (tempY < 1))
				return 0;

			/* If it is the user's move */
			if(tempX == destX && tempY == destY)
				return 1;
		}
	}

	return 0;
}

int calculate_horizontals(int currentX, int currentY, int destX, int destY) {

	int tempX;
	int tempY;

	/* Straight Up */
	if(destX == currentX && destY > currentY) {
		
		for (int i = 1; i <= 7; i++) {
			tempY = currentY + i;

			if(tempY > 8)
				return 0;

			if(tempY == destY)
				return 1;

		}
	
	} 

	/* Straight Down */
	else if (destX == currentX && destY < currentY) {

		for (int i = 1; i <= 7; i++) {
			tempY = currentY - i;

			if(tempY > 1)
				return 0;

			if(tempY == destY)
				return 1;

		}

	}

	/* Right Across */
	else if (destX > currentX && destY == currentY) {

		for (int i = 1; i <= 7; i++) {
			tempX = currentX + i;

			if(tempX > 8)
				return 0;

			if(tempX == destX)
				return 1;

		}

	}

	/* Left Across */
	else if (destX < currentX && destY == currentY) {

		for (int i = 1; i <= 7; i++) {
			tempX = currentX - i;

			if(tempX < 1)
				return 0;

			if(tempX == destX)
				return 1;

		}

	}

	return 0;
}

int isLegalMove(chessPiece piece, int x, int y) {

	/* TODO: 
		- Check if pieces are in the way (Both friendly and enemy & !king)

	*/

	if(piece.type == PAWN) {

		int currentX = piece.xPos;
		int currentY = piece.yPos;
		int tempX, tempY;
		int i;

		i = (piece.hasMoved == 0)? 0 : 1;
		
		/* Checks all possible legal moves */
		for(i; i < 4; i++) {
			
			tempX = currentX + piece.xMoves[i]; 
			tempY = currentY + piece.yMoves[i];

			if((tempX == x) && (tempY == y)) {
					 
				/* Checking for any obstructing pieces */
				if(i == 0) { //Two moves forward
					 
				} else if (i == 1) { //One move forward

				} else if (i == 2) { //Right Diagonal Take

				} else if (i == 3) { //Left Diagonal Take

				}
				return 1;
			}
		
		}
	
	} else if (piece.type == KNIGHT) {

		int currentX = piece.xPos;
		int currentY = piece.yPos;
		int tempX, tempY;
		int i = 0;
		
		for(i; i < 4; i++) {

			tempX = currentX + piece.xMoves[i]; 
			tempY = currentY + piece.yMoves[i];

			if((tempX == x) && (tempY == y)) { /* TO DO: Add condition to check that the piece at that location is different colour and !king */
				return 1;
			}
		}		
	
	} else if (piece.type == BISHOP) {
	
		return calculate_diagonals(piece.xPos, piece.yPos, x, y);
	
	} else if (piece.type == QUEEN) {

		return (calculate_diagonals(piece.xPos, piece.yPos, x, y) == 1)? 1 : calculate_horizontals(piece.xPos, piece.yPos, x, y);
	
	} else if (piece.type == ROOK) {

		return calculate_horizontals(piece.xPos, piece.yPos, x, y);

	}

	return 0;
}

char *get_piece_type(chessPiece piece) {

	int type = piece.type;

	switch(type) {

		case 4:
			return "PAWN";
			break;

		case 5:
			return "KNIGHT";
			break;

		case 2:
			return "BISHOP";
			break;

		case 3:
			return "ROOK";
			break;
		
		case 1:
			return "QUEEN";
			break;
		
		case 0:
			return "KING";
			break;

		default:
			return "NOTHING";

	}
}

char *get_piece_colour(chessPiece piece) {

	int colour = piece.allegiance;

	return colour == 0? "WHITE" : "BLACK";
}