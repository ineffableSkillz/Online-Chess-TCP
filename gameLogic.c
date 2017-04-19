#include "gameLogic.h"

int main() {

	board chessTable;
	board_setup(&chessTable);

}

int get_array_position(unsigned x, unsigned y) {
	
	return ((COLUMN + 1) * x) + y;
}

void board_setup(board *table) {

	/* Creates 64 Board Pieces */
	table = malloc(TOTAL_SQUARES * sizeof(board));

	for(int x = 0; x < COLUMN; x++) 
		for(int y = 0; y < COLUMN; y++)
			table[get_array_position(x,y)] = NULL;

}