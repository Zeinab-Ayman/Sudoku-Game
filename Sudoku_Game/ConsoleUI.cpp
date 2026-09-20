#include "ConsoleUI.h"
#include <iostream>
using namespace std;

ConsoleUI::ConsoleUI() {}

void ConsoleUI::run() {
    bool exitRequested = false;
    while (!exitRequested) {
        system("cls");
        showMainMenu();
        int choice;
        cout << "  --------------------------------------\n";
        cout << "   Choice >> ";
        cin >> choice;

        if (choice == 1) {
            int diffChoice;
            cout << "\n Select Difficulty Level:";
            cout << " (1) Easy  (2) Medium  (3) Hard:  ";
            cin >> diffChoice;
            Difficulty d;
            switch (diffChoice)
            {
            case 1:
                d = Difficulty::EASY;
                break;
            case 2:
                d = Difficulty::MEDIUM;
                break;
            default:
                d = Difficulty::HARD;
                break;
            }

            controller.startNewGame(d);
            playGameLoop();
        }
        else if (choice == 2) {
            string filename;
            cout << "\n File Name : ";
            cin >> filename;
            if (controller.loadGame(filename)) {
                playGameLoop();
            }
            else {
                cout << "\n [x] Failed to load the game!\n";
				system("pause");
			}
        }
        else if (choice == 3) {
            showInstructions();
			system("pause");
        }
        else if (choice == 4) {
            exitRequested = true;
        }
    }
}

void ConsoleUI::showMainMenu() {
    cout << "=== Sudoku ===\n";
    cout << "1. New Game\n";
    cout << "2. Load Game\n";
    cout << "3. Instructions\n";
    cout << "4. Exit\n";

}

void ConsoleUI::showInstructions() {
    cout << "\n - Fill the 9x9 grid with numbers 1 through 9.  \n";
    cout << " - Each row must contain digits 1-9 once.       \n";
    cout << " - Each column must contain digits 1-9 once.    \n";
    cout << " - Each 3x3 block must contain digits 1-9 once. \n";
}

void ConsoleUI::showBoard() const {
    const Board& board = controller.getBoard();
    cout << "\n      1   2   3     4   5   6     7   8   9\n";
    cout << "    +------------+-------------+-------------+\n";
    for (int row = 0; row < Board::SIZE; ++row) {
        if (row != 0 && row % 3 == 0) {
            cout << "    +------------+-------------+-------------+\n";
        }
        cout << "  " << (row + 1) << " |";

        for (int col = 0; col < Board::SIZE; ++col) {
            if (col != 0 && col % 3 == 0) {
                cout << "| ";
            }
            int v = board.at(row, col).getValue();
            cout << " " << (char)(v == 0 ? '.' : ('0' + v)) << "  ";
        }
        cout << "|\n";
    }

    cout << "    +------------+-------------+-------------+\n";
}

void ConsoleUI::playGameLoop() {

    bool playing = true;
    while (playing && !controller.isSolved()) {
        showBoard();
        cout << "\nMoves: " << controller.getMoveCount()
            << " | Mistakes: " << controller.getMistakeCount()
            << " | Hints: " << controller.getHintCount() << "\n";
        cout << "\n [1] Enter Move\t[2] Clear Cell\n [3] Undo\t[4] Redo\n [5] Hint\t[6] Save\n [7] Give Up\t[8] Exit to Menu\n ";
        cout << " ------------------------------------------\n";
        cout << "   Action >> ";
        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        int r, c, val;
        switch (choice) {
        case 1:
            cout << "\nEnter row (1-9), col (1-9), value (1-9): ";
            if (!(cin >> r >> c >> val)) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "\n [x] Invalid input!\n";
                break;
            }
            if (r >= 1 && r <= 9 && c >= 1 && c <= 9 && val >= 1 && val <= 9) {
                if (!controller.makeMove(r - 1, c - 1, val)) {
                    cout << "\n [x] Cannot modify a fixed cell!\n";
                }
            }
            else {
                cout << "\n [x] Out of range!\n";
            }
            break;
        case 2:
            cout << "\nEnter row (1-9), col (1-9) to clear: ";
            if (!(cin >> r >> c)) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "\n [x] Invalid input!\n";
                break;
            }
            if (r >= 1 && r <= 9 && c >= 1 && c <= 9) {
                if (!controller.clearCell(r - 1, c - 1)) {
                    cout << "\n [x] Cannot clear a fixed cell!\n";
                }
            }
            else {
                cout << "\n [x] Out of range!\n";
            }
            break;
        case 3:
            if (!controller.undo()) cout << "\n [!] Nothing to undo.\n";
            break;
        case 4:
            if (!controller.redo()) cout << "\n [!] Nothing to redo.\n";
            break;
        case 5:
            cout << "\n Enter row (1-9), col (1-9) for hint: ";
            if (!(cin >> r >> c)) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "\n [x] Invalid input!\n";
                break;
            }
            if (r >= 1 && r <= 9 && c >= 1 && c <= 9) {
                if (!controller.giveHint(r - 1, c - 1)) {
                    cout << "\n [x] Cell is not empty!\n";
                }
            }
            else {
                cout << "\n [x] Out of range!\n";
            }
            break;
        case 6: {
            string fname;
            cout << "\n Enter filename to save: ";
            cin >> fname;
            if (!controller.saveGame(fname)) {
                cout << "\n [x] Failed to save the game!\n";
            }
            else {
                cout << "\n [*] Game saved successfully!\n";
            }
            break;
        }
        case 7:
            controller.solvePuzzle();
            break;
        case 8:
            playing = false;
            break;
        }
    }
    if (controller.isSolved()) {
        showBoard();
        cout << "\n\n [*] Congratulations! You solved the Sudoku puzzle!\n\n";
		system("pause");
		return;
    }
}
