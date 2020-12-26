#include <iostream>
#include "Board.h"

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
            while (gameBoard.getState() == false) {
                int playerOneInput;
                int playerTwoInput;
                //display board
                gameBoard.drawPlayer();
                //player 1 input
                cout << "Player 1 selection: ";
                do{
                    try {
                        cin >> playerOneInput;
                        gameBoard.updateMove1(playerOneInput);
                    }
                    catch(bool invalidInput){
                        cout << "\nInvalid input\n";
                    }
                }
                while(invalidInput);
                //increment moves
                ++gameBoard;
                //verify win conditions
                gameBoard.verifyWin();
                if(gameBoard.getState() == true) {
                    break;
                }
                else if(gameBoard.getTie() == true) {
                    break;
                }
                //display new board
                gameBoard.drawPlayer();
                //player 2 input
                cout << "Player 2 selection: ";
                do{
                    try {
                        cin >> playerTwoInput;
                        gameBoard.updateMove2(playerTwoInput);
                    }
                    catch(bool invalidInput){
                        cout << "\nInvalid input\n";
                    }
                }
                while(invalidInput);
                //increment moves
                ++gameBoard;
                //verify win conditions
                gameBoard.verifyWin();
                if(gameBoard.getState() == true) {
                    break;
                }
                else if(gameBoard.getTie() == true){
                    break;
                }
            }
            //present winner
            gameBoard.drawPlayer();
            if(gameBoard.getPlayer1Win()){
                cout << "Player 1 Wins!" << endl;
            }
            else if(gameBoard.getPlayer2Win()){
                cout << "Player 2 Wins!" << endl;
            }
            else {
                cout << "Tie!" << endl;
            }
        }
        else if(menuInput == "2") {
            //Player vs Computer
            while (gameBoard.getState() == false) {
                //display board
                gameBoard.drawComp();

                //TEMP
                //gameBoard.setStateWin();
            }
             //present winner
            gameBoard.drawPlayer();
            if(gameBoard.getPlayer1Win()){
                cout << "Player Wins!" << endl;
            }
            else if(gameBoard.getPlayer2Win()){
                cout << "Computer Wins!" << endl;
            }
            else {
                cout << "Tie!" << endl;
            }
        }

    
    } 
    while (menuInput != "3");

    return 0;
} 