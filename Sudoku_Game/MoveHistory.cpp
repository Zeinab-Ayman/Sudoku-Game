#include "MoveHistory.h"

void MoveHistory::recordMove(const Move& move) {
    undoStack.push(move);
    clearRedo();
}

bool MoveHistory::undo(Move& outMove) {
    // TODO: implement using undoStack_ / redoStack_ (see header comment).
    return false;
}

bool MoveHistory::redo(Move& outMove) {
    // TODO: implement using undoStack_ / redoStack_ (see header comment).
    return false;
}

void MoveHistory::clearRedo() {
    while (!redoStack.empty()) {
        redoStack.pop();
    }
}

bool MoveHistory::canUndo() const {
    return !undoStack.empty();
}

bool MoveHistory::canRedo() const {
    return !redoStack.empty();
}
