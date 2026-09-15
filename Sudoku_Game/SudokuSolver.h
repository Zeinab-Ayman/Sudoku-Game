#pragma once

#include "Board.h"

/**
 * Solves a Sudoku board using backtracking, and can count solutions
 * (used to verify a generated puzzle has a unique solution).
 * Related SRS sections: 5.2.1, 5.2.2 (FR-1, FR-2, FR-14).
 */
class SudokuSolver {
public:
    // Fills `board` in place with a valid solution, if one exists.
    // Returns true if solved successfully.
    bool solve(Board& board);

    // Counts how many solutions exist, stopping early once `limit` is reached.
    // Used to confirm a puzzle has exactly one solution (FR-2).
    int countSolutions(Board board, int limit = 2);

private:
    // TODO: recursive backtracking helper.
    // 1. Find the next empty cell (row, col).
    // 2. If none found, the board is solved -> return true.
    // 3. Try values 1-9; for each valid one, place it, recurse, and
    //    undo (backtrack) if the recursive call fails.
    bool solveRecursive(Board& board);

    // TODO: find the first empty cell, scanning row by row.
    // Return false if the board has no empty cells left.
    bool findEmptyCell(const Board& board, int& row, int& col) const;

    // TODO: recursive helper for countSolutions (same idea as solveRecursive,
    // but keeps counting instead of stopping at the first solution).
    void countSolutionsRecursive(Board& board, int& count, int limit) const;
};
