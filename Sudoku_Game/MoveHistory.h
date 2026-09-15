#pragma once

#include <stack>
using namespace std;

/**
 * A single player move, used for undo/redo.
 */
struct Move {
    int row;
    int col;
    int previousValue;
    int newValue;
};

/**
 * Tracks moves using two stacks so the player can undo/redo.
 * Related SRS sections: 3.3 (FR-12, FR-13), 5.2.3.
 */
class MoveHistory {
public:
    void recordMove(const Move& move);

    // TODO: pop from undoStack_, push it onto redoStack_, and output it via outMove.
    // Return false if there is nothing to undo.
    bool undo(Move& outMove);

    // TODO: pop from redoStack_, push it back onto undoStack_, and output it via outMove.
    // Return false if there is nothing to redo.
    bool redo(Move& outMove);

    // Call this whenever a *new* move is made after an undo (FR-13 rule:
    // redo history is invalidated once the player makes a new move).
    void clearRedo();

    bool canUndo() const;
    bool canRedo() const;

private:
    stack<Move> undoStack;
    stack<Move> redoStack;
};
