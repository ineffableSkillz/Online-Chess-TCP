#include "gameLogic.h"

int main() {

	board chessTable;
	board_setup(&chessTable, 1);

}

int get_array_position(unsigned row, unsigned col) {
	
	return (TOTAL_COLUMNS * row) + col;
}

void board_setup(board *table, int isWhite) {

	/* Creates 64 Board Pieces */
	table->tiles = malloc(TOTAL_SQUARES * sizeof(chessPiecePlace));

	for(int row = 0; row < TOTAL_COLUMNS; row++) 
		for(int col = 0; col < TOTAL_COLUMNS; col++)
			table->tiles[get_array_position(row,col)] = new_chess_piece_place();

	if(isWhite)
		table->playerColour = WHITE;
	else 
		table->playerColour = BLACK;
}

chessPiecePlace new_chess_piece_place() {

	/* Dynamically Allocating Memory for Struct */
	chessPiecePlace *temp;
	temp = malloc(sizeof(chessPiecePlace));

	/* Setting isFree status to true */
	temp->isFree = 1;

	return *temp;
}