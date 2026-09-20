#include "FileManager.h"
#include <fstream>


bool FileManager::saveToFile(const string& filename,
                              const Board& board,
                              int elapsedSeconds,
                              int moveCount,
                              int mistakeCount,
                              int hintCount) {
    ofstream out(filename);
    if (!out.is_open()) {
        return false;
    }

	for (int row = 0; row < Board::SIZE; ++row) {
		for (int col = 0; col < Board::SIZE; ++col) {
			out << board.at(row, col).getValue() << (col < Board::SIZE - 1 ? " " : "");
		}
		out << "\n";
	}
	for (int row = 0; row < Board::SIZE; ++row) {
		for (int col = 0; col < Board::SIZE; ++col) {
			out << (board.at(row, col).isFixed() ? "1" : "0") << (col < Board::SIZE - 1 ? " " : "");
		}
		out << "\n";
	}
	out << elapsedSeconds << " " << moveCount << " " << mistakeCount << " " << hintCount << "\n";
   

    return true;
}

bool FileManager::loadFromFile(const string& filename,
	Board& board,
	int& elapsedSeconds,
	int& moveCount,
	int& mistakeCount,
	int& hintCount) {
	ifstream in(filename);
	if (!in.is_open()) {
		return false;
	}
	for (int row = 0; row < Board::SIZE; ++ro) {
		for (int col = 0; col < Board::SIZE; ++col) {
			int value;
			in >> value;
			if (!in) {
				return false; // Error reading value
			}
			board.at(row, col).setValue(value);
		}
	}
	for (int row = 0; row < Board::SIZE; ++row) {
		for (int col = 0; col < Board::SIZE; ++col) {
			int fixedFlag;
			in >> fixedFlag;
			if (!in) {
				return false; // Error reading fixed flag
			}
			board.at(row, col).setFixed(fixedFlag == 1);
		}
	}
	in >> elapsedSeconds >> moveCount >> mistakeCount >> hintCount;
	if (!in) {
		return false; // Error reading stats
	}
	return true;
}

    (void)board;
    elapsedSeconds = 0;
    moveCount = 0;
    mistakeCount = 0;
    hintCount = 0;

    return true;
}
