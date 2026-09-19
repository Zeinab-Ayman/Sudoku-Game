#include "GameController.h"
#include "FileManager.h"

GameController::GameController()
    : moveCount(0), mistakeCount(0), hintCount(0) {}

void GameController::startNewGame(Difficulty difficulty) {
    board = generator.generate(difficulty);

    solution = board;
    solver.solve(solution);

    moveCount = 0;
    mistakeCount = 0;
    hintCount = 0;
}

bool GameController::makeMove(int row, int col, int value) {
    if (board.at(row, col).isFixed()) {
        return false;
    }
    int oldValue = board.at(row, col).getValue();
    board.at(row, col).setValue(value);
    history.recordMove({ row, col, oldValue, value });
    moveCount++;
    if (solution.at(row, col).getValue() != value) {
        mistakeCount++;
    }
    return true;
}

bool GameController::clearCell(int row, int col) {
    if (board.at(row, col).isFixed()) {
        return false;
    }
    int oldValue = board.at(row, col).getValue();
    board.at(row, col).clearValue();
    history.recordMove({ row, col, oldValue, 0 });
    return true;
}

bool GameController::undo() {
    Move move;
    if (!history.undo(move)) {
        return false;
    }
    board.at(move.row, move.col).setValue(move.previousValue);
    return true;
}

bool GameController::redo() {
    Move move;
    if (!history.redo(move)) {
        return false;
    }
	 board.at(move.row, move.col).setValue(move.newValue);
    return true;
}

bool GameController::giveHint(int row, int col) {
    
	if(board.at(row, col).isFixed() || !board.at(row, col).isEmpty()) {
		return false;
	}
	 int hintValue = solution.at(row, col).getValue();
	 board.at(row, col).setValue(hintValue);
    hintCount++;
    return true;
}

void GameController::solvePuzzle() {
    
	for (int row = 0; row < Board::SIZE; ++row) {
		for (int col = 0; col < Board::SIZE; ++col) {
			if (board.at(row, col).isEmpty()) {
				int solutionValue = solution.at(row, col).getValue();
				board.at(row, col).setValue(solutionValue);
			}
		}
	}
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
