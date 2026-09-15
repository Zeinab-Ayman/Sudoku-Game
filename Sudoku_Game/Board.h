#pragma once

#include "Cell.h"

/**
 * Owns the 9x9 grid of Cell objects and exposes rule-checking.
 * Related SRS sections: 3.1, 3.2 (FR-5, FR-6, FR-9, FR-10), 5.1.
 */
class Board {
public:
    static const int SIZE = 9;
    static const int BOX_SIZE = 3;

    Board();

    Cell& at(int row, int col);
    const Cell& at(int row, int col) const;

    // Rule checks -- TODO: implement using Sudoku row/column/box rules (FR-9)
    bool isRowValid(int row, int value) const;
    bool isColValid(int col, int value) const;
    bool isBoxValid(int row, int col, int value) const;
    bool isPlacementValid(int row, int col, int value) const;

    // TODO: return true once every cell is filled and every row/col/box is valid (FR-10)
    bool isComplete() const;

    // Resets every cell to empty and not fixed.
    void reset();

    // Marks every currently-filled cell as fixed (used right after generation).
    void markFilledCellsAsFixed();

private:
    Cell grid[SIZE][SIZE];
};
