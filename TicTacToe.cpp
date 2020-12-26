#include <iostream>
#include "Board.h"

using namespace std;

int main() {
    string menuInput;
    Board gameBoard;
    do {
        //makesure that board is reset
        gameBoard.resetBoard();
        menuInput = "";
        //display menu
        cout << "\n\tMenu\n";
        cout << "1. Player vs Player" << endl;
        cout << "2. Player vs Computer" << endl;
        cout << "3. Exit\n" << endl;
        cout << "User input: ";
        cin >> menuInput;

        //options
        if(menuInput == "1") {
            //Player vs Player
            while (gameBoard.getState() == false) {
                //display board
                gameBoard.drawPlayer();

                //TEMP
                gameBoard.setStateWin();
            }
        }
        else if(menuInput == "2") {
            //Player vs Computer
            while (gameBoard.getState() == false) {
                //display board
                gameBoard.drawComp();

                //TEMP
                gameBoard.setStateWin();
            }
        }

    
    } 
    while (menuInput != "3");

    return 0;
} 