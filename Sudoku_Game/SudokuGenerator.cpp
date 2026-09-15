#include "SudokuGenerator.h"

Board SudokuGenerator::generate(Difficulty difficulty) {
    Board board;

    fillDiagonalBoxes(board);
    fillRemaining(board);

    int toRemove = cellsToRemove(difficulty);
    removeCells(board, toRemove);

    board.markFilledCellsAsFixed();
    return board;
}

void SudokuGenerator::fillDiagonalBoxes(Board& board) {
    // TODO: for box index 0, 1, 2 (top-left, middle, bottom-right diagonal boxes),
    // fill each 3x3 box with a random shuffle of 1-9.
}

void SudokuGenerator::fillRemaining(Board& board) {
    // TODO: run a backtracking fill (similar to SudokuSolver::solveRecursive)
    // over the remaining empty cells, trying values in randomized order so
    // each generated puzzle is different.
}

void SudokuGenerator::removeCells(Board& board, int countToRemove) {
    // TODO: see header comment above.
    (void)board;
    (void)countToRemove;
}

int SudokuGenerator::cellsToRemove(Difficulty difficulty) const {
    switch (difficulty) {
        case Difficulty::EASY:   return 35; // TODO: tune these numbers
        case Difficulty::MEDIUM: return 45;
        case Difficulty::HARD:   return 55;
    }
    return 45;
}
