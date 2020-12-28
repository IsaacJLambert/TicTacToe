#include <iostream>
#include "Board.h"
#include "Computer.h"
#include "Gameplay.h"

using namespace std;

int main() {
    string menuInput;
    Board gameBoard;
    bool invalidInput;
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
            playerVsPlayer(gameBoard);
        }
        else if(menuInput == "2") {
            //Player vs Computer
            playerVsComputer(gameBoard, difficultyLevelSelection());
        }
    } 
    while (menuInput != "3");

    return 0;
}

