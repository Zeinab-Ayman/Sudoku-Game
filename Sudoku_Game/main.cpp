#include "ConsoleUI.h"

//#include<iostream>
//#include "Board.h"
//#include "SudokuSolver.h"
//#include "SudokuGenerator.h"
//#include "MoveHistory.h"

using namespace std;
int main() {
     ConsoleUI ui;
     ui.run();

    //test Board class
    /*Board b;
    cout << "Is row 0 valid for value 5? " << b.isRowValid(0, 5) << endl;
        if (b.isRowValid(0, 5)) {
            cout << "Board is complete" << endl;
        }
        else {
            cout << "Board is not complete" << endl;

        }*/


     //test SudokuSolver class
     /*Board b;
     SudokuSolver solver;
     bool ok = solver.solve(b);*/

	 //test SudokuGenerator class
    /*SudokuGenerator generator;
    Board board = generator.generate(Difficulty::EASY);
    board.print();*/

	//test MoveHistory class
    /*MoveHistory h;
    h.recordMove({ 0, 0, 5, 7 });
    Move m;
    h.undo(m);
    cout << h.canRedo();*/
            
    return 0;
}




