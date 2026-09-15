#pragma once

#include <string>
#include "Board.h"
#include "SudokuGenerator.h"
#include "SudokuSolver.h"
#include "MoveHistory.h"

/**
 * Coordinates Board, Generator, Solver, and MoveHistory; enforces game rules.
 * This is the class the UI layer talks to -- it should not need to know
 * anything about backtracking, stacks, or file formats.
 * Related SRS sections: 3.2, 3.3, 3.4, 5.1, 5.3.
 */
class GameController {
public:
    GameController();

    void startNewGame(Difficulty difficulty);

    // TODO (FR-6, FR-7, FR-9): reject the move if the cell is fixed or the
    // value is invalid; otherwise apply it, record it in history_, and
    // update moveCount_ / mistakeCount_. Return true if the move was applied.
    bool makeMove(int row, int col, int value);

    // TODO (FR-8): clear a non-fixed cell's value (still record it as a move).
    bool clearCell(int row, int col);

    // TODO (FR-12): use history_.undo(...) to revert the last move.
    bool undo();

    // TODO (FR-13): use history_.redo(...) to re-apply an undone move.
    bool redo();

    // TODO (FR-11): reveal the correct value (from solution_) for the given
    // cell and increment hintCount_.
    bool giveHint(int row, int col);

    // TODO (FR-14): copy solution_ into board_ for every remaining empty cell.
    void solvePuzzle();

    // TODO (FR-10): delegate to board_.isComplete().
    bool isSolved() const;

    // TODO (FR-15, FR-16): delegate to FileManager, passing current stats.
    bool saveGame(const string& filename);
    bool loadGame(const string& filename);

    Board& getBoard();
    const Board& getBoard() const;

    int getMoveCount() const;
    int getMistakeCount() const;
    int getHintCount() const;

private:
    Board board;       // the puzzle as currently played
    Board solution;     // the full solved board, kept for hints/solve/validation
    SudokuGenerator generator;
    SudokuSolver solver;
    MoveHistory history;

    int moveCount;
    int mistakeCount;
    int hintCount;
};
