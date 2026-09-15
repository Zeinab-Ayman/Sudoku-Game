#include "Board.h"

Board::Board() {
    reset();
}

Cell& Board::at(int row, int col) {
    return grid[row][col];
}

const Cell& Board::at(int row, int col) const {
    return grid[row][col];
}

bool Board::isRowValid(int row, int value) const {
    // TODO (FR-9): return false if `value` already exists anywhere in `row`.
	for (int col = 0; col < SIZE; col++) {
		if (grid[row][col].getValue() == value) {
			return false;
		}
	}
    return true;
}

bool Board::isColValid(int col, int value) const {
    // TODO (FR-9): return false if `value` already exists anywhere in `col`.
	for (int row = 0; row < SIZE; row++) {
		if (grid[row][col].getValue() == value) {
			return false;
		}
	}
    return true;
}

bool Board::isBoxValid(int row, int col, int value) const {
    // TODO (FR-9): compute the top-left corner of the 3x3 box containing (row, col)
    // then check all 9 cells in that box for `value`.
    int startRow = row - row % BOX_SIZE;
    int startCol = col - col % BOX_SIZE;
	for (int i = startRow; i < startRow + BOX_SIZE; i++) {
		for (int j = startCol; j < startCol + BOX_SIZE; j++) {
			if (grid[i][j].getValue() == value) {
				return false;
			}
		}
	}
    return true;
}

bool Board::isPlacementValid(int row, int col, int value) const {
	// TODO (FR-9): return true if `value` can be placed at (row, col) without
	// violating any Sudoku rules (row, column, box). Use the three methods above.
	if (value < 1 || value > 9) {
		return false; 
	}
	return isRowValid(row, value) && isColValid(col, value) && isBoxValid(row, col, value);
    return true;
}

bool Board::isComplete() const {
	// TODO (FR-10): every cell must be non-empty AND every row/col/box must satisfy
	// Sudoku rules. A simple approach: loop over all cells, return false if any is empty;
	// then re-validate every row/column/box.
	for (int row = 0; row < SIZE; row++) {
		for (int col = 0; col < SIZE; col++) {
			if (grid[row][col].isEmpty()) {
				return false;
			}
		}
	}
	for (int row = 0; row < SIZE; row++) {
		for (int col = 0; col < SIZE; col++) {
			int value = grid[row][col].getValue();
			for (int othercol = col + 1; othercol < SIZE; othercol++) {
				if (grid[row][othercol].getValue() == value) {
					return false;
				}
			}
		}
	}
	for (int col = 0; col < SIZE; col++) {
		for (int row = 0; row < SIZE; row++) {
			int value = grid[row][col].getValue();
			for (int otherrow = row + 1; otherrow < SIZE; otherrow++) {
				if (grid[otherrow][col].getValue() == value) {
					return false;
				}
			}
		}
	}
	for (int startRow = 0; startRow < SIZE; startRow += BOX_SIZE) {
		for (int startCol = 0; startCol < SIZE; startCol += BOX_SIZE) {
			for (int row = startRow; row < startRow + BOX_SIZE; row++) {
				for (int col = startCol; col < startCol + BOX_SIZE; col++) {
					int value = grid[row][col].getValue();
					for (int otherRow = startRow; otherRow < startRow + BOX_SIZE; otherRow++) {
						for (int otherCol = startCol; otherCol < startCol + BOX_SIZE; otherCol++) {
							if ((row != otherRow || col != otherCol) && grid[otherRow][otherCol].getValue() == value) {
								return false;
							}
						}
					}
				}
			}
		}
	}
	return true;
}
void Board::reset() {
	for (int row = 0; row < SIZE; row++) {
		for (int col = 0; col < SIZE; col++) {
			grid[row][col].setValue(0);
		}
	}
    
}

void Board::markFilledCellsAsFixed() {
	for (int row = 0; row < SIZE; row++) {
		for (int col = 0; col < SIZE; col++) {
			if (!grid[row][col].isEmpty()) {
				grid[row][col].setFixed(true);
			}
		}
	}
    
}
