#include "ConsoleUI.h"
#include <iostream>

ConsoleUI::ConsoleUI() {}

void ConsoleUI::run() {
    // TODO: loop showing showMainMenu(), reading the player's choice, and
    // calling controller_.startNewGame(...) / controller_.loadGame(...) /
    // showInstructions() / exiting, per FR-19.
    showMainMenu();
}

void ConsoleUI::showMainMenu() {
    cout << "=== Sudoku ===\n";
    cout << "1. New Game\n";
    cout << "2. Load Game\n";
    cout << "3. Instructions\n";
    cout << "4. Exit\n";
    // TODO: read the player's choice here.
}

void ConsoleUI::showInstructions() {
    cout << "Fill the 9x9 grid so every row, column, and 3x3 box "
                 "contains the digits 1-9 exactly once.\n";
}

void ConsoleUI::showBoard() const {
    // TODO: see header comment. Loop rows 0-8, printing a separator line
    // every 3 rows and a "|" every 3 columns.
}

void ConsoleUI::playGameLoop() {
    // TODO: see header comment.
}
