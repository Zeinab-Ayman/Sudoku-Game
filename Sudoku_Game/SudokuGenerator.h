#pragma once

#include "Board.h"
#include "SudokuSolver.h"

enum class Difficulty { EASY, MEDIUM, HARD };

/**
 * Generates a complete valid solution, then removes cells to build a
 * playable puzzle with a unique solution.
 * Related SRS sections: 3.1, 5.2.1, 5.2.2 (FR-1, FR-2, FR-3).
 */
class SudokuGenerator {
public:
    // Returns a ready-to-play puzzle (with `isFixed` set on the given cells).
    Board generate(Difficulty difficulty);
   

private:
    SudokuSolver solver;
    
    // TODO: fill the three diagonal 3x3 boxes with random valid 1-9 permutations
    // (they don't affect each other, so this is safe to do without backtracking).
    void fillDiagonalBoxes(Board& board);

    // TODO: use SudokuSolver-style backtracking (with randomized value order)
    // to fill in the remaining cells and produce one complete solution.
    bool fillRemaining(Board& board);

    // TODO: repeatedly pick a random filled cell, remove its value, and use
    // solver_.countSolutions(board) to confirm the puzzle still has exactly
    // one solution; if not, put the value back and try a different cell.
    void removeCells(Board& board, int countToRemove);

    // TODO: map each Difficulty to a number of cells to remove, e.g.
    // EASY -> ~35 removed, MEDIUM -> ~45 removed, HARD -> ~55 removed (FR-3).
    int cellsToRemove(Difficulty difficulty) const;
};
