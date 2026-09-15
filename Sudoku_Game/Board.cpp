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
    
    return true;
}

bool Board::isColValid(int col, int value) const {
    // TODO (FR-9): return false if `value` already exists anywhere in `col`.
    
    return true;
}

bool Board::isBoxValid(int row, int col, int value) const {
    // TODO (FR-9): compute the top-left corner of the 3x3 box containing (row, col)
    // then check all 9 cells in that box for `value`.

    return true;
}

bool Board::isPlacementValid(int row, int col, int value) const {
	// TODO (FR-9): return true if `value` can be placed at (row, col) without
	// violating any Sudoku rules (row, column, box). Use the three methods above.

    return true;
}

bool Board::isComplete() const {
    // TODO (FR-10): every cell must be non-empty AND every row/col/box must satisfy
    // Sudoku rules. A simple approach: loop over all cells, return false if any is empty;
    // then re-validate every row/column/box.
    return false;
}

void Board::reset() {
    
}

void Board::markFilledCellsAsFixed() {
    
}
