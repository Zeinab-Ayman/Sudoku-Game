#pragma once

#include <string>
#include "Board.h"

/**
 * Saves/loads game state to/from a plain text file.
 * Related SRS sections: 3.4 (FR-15, FR-16).
 */
class FileManager {
public:
    // TODO: write, per line, enough info to fully restore the game:
    //   - 9 lines for the board values (e.g. space-separated digits, 0 = empty)
    //   - 9 lines (or a bitmask) marking which cells are fixed
    //   - elapsed seconds, move count, mistake count, hint count
    // Return false if the file could not be opened for writing.
    static bool saveToFile(const string& filename,
                            const Board& board,
                            int elapsedSeconds,
                            int moveCount,
                            int mistakeCount,
                            int hintCount);

    // TODO: read back exactly what saveToFile wrote, in the same order,
    // and populate `board` plus the out-parameters below.
    // Return false if the file could not be opened or was malformed.
    static bool loadFromFile(const string& filename,
                              Board& board,
                              int& elapsedSeconds,
                              int& moveCount,
                              int& mistakeCount,
                              int& hintCount);
};
