#include "SudokuGenerator.h"
#include<vector>
#include<random>
#include<algorithm>
using namespace std;
Board SudokuGenerator::generate(Difficulty difficulty) {
    Board board;

    fillDiagonalBoxes(board);
    fillRemaining(board);
    int toRemove = cellsToRemove(difficulty);
    removeCells(board, toRemove);

    board.markFilledCellsAsFixed();
    return board;
}

void SudokuGenerator::fillDiagonalBoxes(Board& board) {
    // TODO: for box index 0, 1, 2 (top-left, middle, bottom-right diagonal boxes),
    // fill each 3x3 box with a random shuffle of 1-9.
	random_device rd;
    mt19937 rng(rd());
    vector<int> values{ 1,2,3,4,5,6,7,8,9 };
	for ( int box = 0; box < 3; box++) {
        shuffle(values.begin(), values.end(), rng);
		int startRow = box * Board::BOX_SIZE;
		int startCol = box * Board::BOX_SIZE;
		int index = 0;
        for (int row = startRow; row < startRow + Board::BOX_SIZE; row++) {
			for (int col = startCol; col < startCol + Board::BOX_SIZE; col++) {
				board.at(row, col).setValue(values[index]);
                index++;
			}
		}
	}
}

 bool SudokuGenerator::fillRemaining(Board& board) {
    // TODO: run a backtracking fill (similar to SudokuSolver::solveRecursive)
    // over the remaining empty cells, trying values in randomized order so
    // each generated puzzle is different.
     int row=-1, col=-1;
	 for (int r = 0; r < Board::SIZE; r++) {
		 for (int c = 0; c < Board::SIZE; c++) {
			 if (board.at(r, c).isEmpty()) {
				 row = r;
				 col = c;
				 break;
			 }
		 }
		 if (row != -1) 
             break;
	 }
	 if (row == -1)
		 return true; // All cells filled
	 vector<int> values{ 1,2,3,4,5,6,7,8,9 };
     random_device rd;
     mt19937 rng(rd());
     shuffle(values.begin(), values.end(), rng);
	 for (int value : values) {
		 if (board.isPlacementValid(row, col, value)) {
			 board.at(row, col).setValue(value);
			 if (fillRemaining(board)) {
				 return true;
			 }
			 board.at(row, col).clear();
		 }
	 }
	 return false;
}

void SudokuGenerator::removeCells(Board& board, int countToRemove) {
    // TODO: see header comment above.
  random_device rd;
  mt19937 rng(rd());
  int  removed = 0;
  while (removed < countToRemove)
  {
	  int row = rng() % Board::SIZE;
	  int col = rng() % Board::SIZE;
	  if (!board.at(row, col).isEmpty())
	  {
		  int backup = board.at(row, col).getValue();
		  board.at(row, col).clear();
		  int  solutions = solver.countSolutions(board,2);
		  if (solutions == 1)
		  {
			  removed++;
		  }
		  else
		  {
			  board.at(row, col).setValue(backup);
		  }
		
  }
}

int SudokuGenerator::cellsToRemove(Difficulty difficulty) const {
    switch (difficulty) {
        case Difficulty::EASY:   return 35; // TODO: tune these numbers
        case Difficulty::MEDIUM: return 45;
        case Difficulty::HARD:   return 55;
    }
    return 45;
}
