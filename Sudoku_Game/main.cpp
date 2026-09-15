#include "ConsoleUI.h"
#include<iostream>
#include "Board.h"
using namespace std;
int main() {
    /* ConsoleUI ui;
     ui.run();*/
    Board b;
    cout << "Is row 0 valid for value 5? " << b.isRowValid(0, 5) << endl;
        if (b.isRowValid(0, 5)) {
            cout << "Board is complete" << endl;
        }
        else {
            cout << "Board is not complete" << endl;

        }
            
    return 0;
}




