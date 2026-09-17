#include "MoveHistory.h"

void MoveHistory::recordMove(const Move& move) {
    undoStack.push(move);
    clearRedo();
}

bool MoveHistory::undo(Move& outMove) {
    if (undoStack.empty()) {
        return false;
    }
    outMove = undoStack.top();
    undoStack.pop();
    redoStack.push(outMove);
    return true;
}

bool MoveHistory::redo(Move& outMove) {
    if (redoStack.empty()) {
        return false;
    }
    outMove = redoStack.top();
    redoStack.pop();
    undoStack.push(outMove);
    return true;
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
