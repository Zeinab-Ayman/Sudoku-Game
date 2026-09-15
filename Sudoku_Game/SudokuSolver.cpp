#include "SudokuSolver.h"

bool SudokuSolver::solve(Board& board) {
    return solveRecursive(board);
}

bool SudokuSolver::solveRecursive(Board& board) {
    int row = -1, col = -1;
    if (!findEmptyCell(board, row, col)) {
        return true; // no empty cells left -> solved
    }

    for (int value = 1; value <= 9; ++value) {
        // TODO: check board.isPlacementValid(row, col, value)
        // TODO: if valid -> place it, recurse, and return true if the recursion succeeds
        // TODO: otherwise -> undo the placement (backtrack) and try the next value
    }

    return false; // no value worked here -> trigger backtracking in the caller
}

bool SudokuSolver::findEmptyCell(const Board& board, int& row, int& col) const {
    for (int r = 0; r < Board::SIZE; ++r) {
        for (int c = 0; c < Board::SIZE; ++c) {
            // TODO: if board.at(r, c).isEmpty() -> set row = r, col = c, return true
        }
    }
    return false;
}

int SudokuSolver::countSolutions(Board board, int limit) {
    int count = 0;
    countSolutionsRecursive(board, count, limit);
    return count;
}

void SudokuSolver::countSolutionsRecursive(Board& board, int& count, int limit) const {
    if (count >= limit) {
        return; // early exit once we've proven "more than one solution"
    }

    int row = -1, col = -1;
    if (!findEmptyCell(board, row, col)) {
        ++count;
        return;
    }

    for (int value = 1; value <= 9; ++value) {
        // TODO: same idea as solveRecursive, but don't stop at the first success --
        // keep exploring so `count` reflects the true number of solutions (up to `limit`).
    }
}
