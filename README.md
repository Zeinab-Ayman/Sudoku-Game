# 🧩 Sudoku Game (C++)

A robust, console-based Sudoku puzzle game implemented in C++ following Object-Oriented Programming (OOP) principles and clean software architecture. The game features procedural puzzle generation across multiple difficulties, an automated recursive backtracking solver, an undo/redo move history system, and persistent save/load functionality.

---

## 🌟 Key Features

- **🎮 Interactive Console UI:** Clean, responsive 9x9 board rendering with coordinate labels and clear block separation.
- **⚙️ Dynamic Puzzle Generation:** Generates unique Sudoku puzzles with guaranteed single solutions for three difficulty levels:
  - **Easy:** 35 clues removed.
  - **Medium:** 45 clues removed.
  - **Hard:** 55 clues removed.
- **🤖 Recursive Backtracking Solver:** Rapidly validates puzzles, finds solutions, and verifies solution uniqueness.
- **🔄 Undo / Redo Move History:** Stack-based command history allowing players to reverse or re-apply moves seamlessly.
- **💡 Smart Hints:** Instantly reveals the correct value for any selected empty cell directly from the precomputed solution matrix.
- **💾 Save & Load Support:** Persists board states, fixed cells, and session statistics (`moves`, `mistakes`, `hints`) to text files.
- **🚫 Clue Protection:** Initial clues are marked as fixed and cannot be overwritten or deleted by mistake.

---

## 🧱 Project Architecture

| Module / Class | Responsibility |
| :--- | :--- |
| **`ConsoleUI`** | Renders menus, displays formatted boards, and manages console input/output cycles. |
| **`GameController`** | Central orchestrator coordinating game state, rules, move validation, and metrics. |
| **`Board`** & **`Cell`** | Represents the 9x9 grid, individual cell values, fixed flags, and rule constraints. |
| **`SudokuGenerator`** | Generates valid boards by filling diagonal blocks, completing grids, and removing cells. |
| **`SudokuSolver`** | Implements the backtracking search to solve boards and count unique solutions. |
| **`MoveHistory`** | Maintains `undo` and `redo` stacks tracking cell coordinates and value deltas. |
| **`FileManager`** | Handles serialization and deserialization of board layouts and player statistics. |

---

## 🚀 Getting Started

### Prerequisites
- A C++ compiler supporting **C++14** or later (MSVC, GCC, MinGW, or Clang).
- Visual Studio (2019/2022) or any standard terminal environment.

### Building with Visual Studio
1. Clone the repository:
   ```bash
   git clone https://github.com/Zeinab-Ayman/Sudoku-Game.git
   ```
2. Open `Sudoku_Game.sln` in Visual Studio.
3. Set build configuration to **Release** or **Debug** (x64 / x86).
4. Press `Ctrl + Shift + B` to build, and `F5` to start debugging.

### Building via Terminal (g++ / MinGW)
```bash
cd Sudoku_Game
g++ -std=c++17 *.cpp -o SudokuGame
./SudokuGame
```

---

## 🎮 How to Play

1. Start the executable and select **(1) New Game** from the main menu.
2. Choose a difficulty level (**1: Easy**, **2: Medium**, **3: Hard**).
3. Use the in-game action menu:
   - `[1] Enter Move`: Input `row (1-9)`, `col (1-9)`, and `value (1-9)`.
   - `[2] Clear Cell`: Clear a non-fixed cell.
   - `[3] Undo` / `[4] Redo`: Step back and forth through previous moves.
   - `[5] Hint`: Uncover the solution value for an empty coordinate.
   - `[6] Save`: Save the current game session to a file.
   - `[7] Give Up`: Automatically solve and display the completed grid.
   - `[8] Exit to Menu`: Exit to the main menu screen.

---

## 👥 Contributors

Developed collaboratively by:
- **Zeinab Ayman** ([@Zeinab-Ayman](https://github.com/Zeinab-Ayman))
- **Wafaa Elmanzalawy** ([@elmanzalawyfofa-png](https://github.com/elmanzalawyfofa-png))