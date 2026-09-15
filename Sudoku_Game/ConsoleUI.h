#pragma once

#include "GameController.h"

/**
 * Text-based presentation layer: shows the board/menus and reads input.
 * Related SRS sections: 3.5 (FR-19, FR-20), 5.3 (could later implement a
 * shared IRenderer interface alongside a GUI class, to practice polymorphism).
 */
class ConsoleUI {
public:
    ConsoleUI();

    // Main application loop: shows the main menu and dispatches to
    // new game / load game / instructions / exit (FR-19).
    void run();

private:
    GameController controller;

    void showMainMenu();
    void showInstructions();

    // TODO: print the 9x9 board with clear 3x3 box separators (FR-5).
    void showBoard() const;

    // TODO: the in-game loop -- read a command (move / undo / redo / hint /
    // solve / save / menu) each turn and call the matching GameController method.
    void playGameLoop();
};

