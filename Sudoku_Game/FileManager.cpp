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

    // TODO: write board values, fixed-cell flags, and the stats above.
    // Keep the format simple and human-readable, e.g.:
    //   line 1-9   : board values (space separated, 0 = empty)
    //   line 10-18 : fixed flags (0/1, space separated)
    //   line 19    : elapsedSeconds moveCount mistakeCount hintCount

    (void)board;
    (void)elapsedSeconds;
    (void)moveCount;
    (void)mistakeCount;
    (void)hintCount;

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

    // TODO: parse the same format written by saveToFile, in the same order.

    (void)board;
    elapsedSeconds = 0;
    moveCount = 0;
    mistakeCount = 0;
    hintCount = 0;

    return true;
}
