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

	for(int row = 0; row < TOTAL_ROWS; row++) 
		for(int col = 0; col < TOTAL_COLUMNS; col++)
			table->tiles[get_array_position(row,col)] = new_chess_piece_place();

	if(isWhite)
		table->playerColour = WHITE;
	else 
		table->playerColour = BLACK;

	/* Adding Pawns */
	for(int column = 0; column < 8; column++) {
		place_piece(table, new_pawn(column, 1, WHITE), 1, column);
		place_piece(table, new_pawn(column, 6, BLACK), 6, column);
	}

	/* Adding Rooks */ 
	place_piece(table, new_rook(0, 0, WHITE), 0, 0);
	place_piece(table, new_rook(0, 7, WHITE), 0, 7);

	place_piece(table, new_rook(7, 0, BLACK), 7, 0);
	place_piece(table, new_rook(7, 7, BLACK), 7, 7);

	/* Adding Knights */
	place_piece(table, new_knight(0, 1, WHITE), 0, 1);
	place_piece(table, new_knight(0, 6, WHITE), 0, 6);

	place_piece(table, new_knight(7, 1, WHITE), 7, 1);
	place_piece(table, new_knight(7, 6, WHITE), 7, 6);
	
	/* Adding Bishop */
	place_piece(table, new_bishop(0, 2, WHITE), 0, 2);
	place_piece(table, new_bishop(0, 5, WHITE), 0, 5);

	place_piece(table, new_bishop(7, 2, BLACK), 7, 2);
	place_piece(table, new_bishop(7, 5, BLACK), 7, 5);

	/* Adding Queens */
	place_piece(table, new_queen(0, 3, WHITE), 0, 3);
	place_piece(table, new_queen(7, 3, BLACK), 7, 3);

	/* Adding Kings */
	place_piece(table, new_king(0, 4, WHITE), 0, 4);
	place_piece(table, new_king(7, 4, BLACK), 7, 4);

}

void place_piece(board *table, chessPiece *piece, int row, int column) {

	table->tiles[get_array_position]
}

chessPiecePlace new_chess_piece_place() {

	/* Dynamically Allocating Memory for Struct */
	chessPiecePlace *temp;
	temp = malloc(sizeof(chessPiecePlace));

	/* Setting isFree status to true */
	temp->isFree = 1;

	return *temp;
}