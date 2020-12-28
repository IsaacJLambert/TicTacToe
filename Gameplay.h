#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include <iostream>
#include "Board.h"
#include "Computer.h"

using namespace std;

bool alreadyTaken(Board gameBoard, int move) {
    char quadrant = gameBoard.getQuadrant(move);
    if((quadrant == 'X') || (quadrant == 'O')) {
        return true;
    }
    else{
        return false;
    }
}

int difficultyLevelSelection() {
    int difficultyLevel;
    bool badInput;
    do{
        badInput = false;
        cout << "\tSelect difficulty level: " << endl;
        cout << "1. Easy\n2. Medium\n3. Hard\n";
        cin >> difficultyLevel;
        if((cin.fail()) || (difficultyLevel > 3) || (difficultyLevel < 1)) {
            cin.clear();
            cin.ignore();
            cout << "Invalid option" << endl;
            badInput = true;
        }
    }
    while(badInput);
    return difficultyLevel;
}

void playerVsPlayer(Board gameBoard) {
    while (gameBoard.getState() == false) {
                int playerOneInput;
                int playerTwoInput;
                bool error = false;
                //display board
                gameBoard.drawPlayer();
                //player 1 input
                cout << "Player 1 selection: ";
                do{
                    error = false;
                    try {
                        cin >> playerOneInput;
                        if(alreadyTaken(gameBoard, playerOneInput)) {
                            throw true;
                        }
                        else {
                            gameBoard.updateMove1(playerOneInput);
                        }
                    }
                    catch(bool invalidInput){
                        cin.clear();
                        cin.ignore();
                        cout << "Invalid input\n";
                        cout << "Player 1 selection: ";
                        error = true;
                    }
                }
                while(error);
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
                    error = false;
                    try {
                        cin >> playerTwoInput;
                        if(alreadyTaken(gameBoard, playerTwoInput)) {
                            throw true;
                        }
                        else {
                            gameBoard.updateMove2(playerTwoInput);
                        }
                    }
                    catch(bool invalidInput){
                        cin.clear();
                        cin.ignore();
                        cout << "Invalid input\n";
                        cout << "Player 2 selection: ";
                        error = true;
                    }
                }
                while(error);
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

void playerVsComputer(Board gameBoard, int difficultyLevel) {
     while (gameBoard.getState() == false) {
        int playerOneInput;
        int playerTwoInput;
        bool error = false;
        Computer computerAI;
        //display board
        gameBoard.drawComp();
        //player 1 input
        cout << "Player selection: ";
        do{
            error = false;
            try {
               cin >> playerOneInput;
                if(alreadyTaken(gameBoard, playerOneInput)) {
                    throw true;
                }
                else {
                    gameBoard.updateMove1(playerOneInput);
                }
            }
            catch(bool invalidInput){
                cin.clear();
                cin.ignore();
                cout << "Invalid input\n";
                cout << "Player selection: ";
                error = true;
            }
        }
        while(error);
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
        gameBoard.drawComp();
        //computer input
        if(difficultyLevel == 1) {
            gameBoard.updateMove2(computerAI.computerMoveEasy(gameBoard));
        }
        else if(difficultyLevel == 2) {
            gameBoard.updateMove2(computerAI.computerMoveMedium(gameBoard));
        }
        else if(difficultyLevel == 3) {
            gameBoard.updateMove2(computerAI.computerMoveHard(gameBoard));
        }
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
        cout << "Player Wins!" << endl;
    }
    else if(gameBoard.getPlayer2Win()){
        cout << "Computer Wins!" << endl;
    }
    else {
        cout << "Tie!" << endl;
    }    
}
#endif