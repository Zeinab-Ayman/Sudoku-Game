#include "GameController.h"
#include "FileManager.h"

GameController::GameController()
    : moveCount(0), mistakeCount(0), hintCount(0) {}

void GameController::startNewGame(Difficulty difficulty) {
    board = generator.generate(difficulty);

    // TODO: also compute/store the full solution in solution_, e.g. by
    // copying board_ and running solver_.solve(solution_) before any
    // cells are removed -- or have SudokuGenerator return both boards.

    moveCount = 0;
    mistakeCount = 0;
    hintCount = 0;
}

bool GameController::makeMove(int row, int col, int value) {
    // TODO: see header comment.
    return false;
}

bool GameController::clearCell(int row, int col) {
    // TODO: see header comment.
    return false;
}

bool GameController::undo() {
    Move move;
    if (!history.undo(move)) {
        return false;
    }
    // TODO: apply move.previousValue back onto board.at(move.row, move.col).
    return true;
}

bool GameController::redo() {
    Move move;
    if (!history.redo(move)) {
        return false;
    }
    // TODO: apply move.newValue onto board.at(move.row, move.col).
    return true;
}

bool GameController::giveHint(int row, int col) {
    // TODO: see header comment.
    return false;
}

void GameController::solvePuzzle() {
    // TODO: see header comment.
}

bool GameController::isSolved() const {
    return board.isComplete();
}

bool GameController::saveGame(const std::string& filename) {
    // TODO: pass elapsed time once you add a timer; 0 for now.
    return FileManager::saveToFile(filename, board, 0, moveCount, mistakeCount, hintCount);
}

bool GameController::loadGame(const std::string& filename) {
    int elapsedSeconds = 0;
    return FileManager::loadFromFile(filename, board, elapsedSeconds, moveCount, mistakeCount, hintCount);
}

Board& GameController::getBoard() {
    return board;
}

const Board& GameController::getBoard() const {
    return board;
}

int GameController::getMoveCount() const {
    return moveCount;
}

int GameController::getMistakeCount() const {
    return mistakeCount;
}

int GameController::getHintCount() const {
    return hintCount;
}
