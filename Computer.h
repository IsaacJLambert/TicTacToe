#ifndef COMPUTER_H
#define COMPUTER_H
#include "Board.h"
#include <ctime>
using namespace std;

class Computer{
public:
    Computer() {
        playerHasWinMove = false;
        compHasWinMove = false;
    }
    int computerMoveEasy(Board gameBoard) {
        //random moves
        int move;
        bool rollAgain;
        srand(time(NULL));
        do{
            rollAgain = false;
            //get a number 1-9
            move = rand() % 9 + 1;
            //verify that someone hasn't gone there yet
            rollAgain = repeatMoveCheck(gameBoard, move);
        }
        while(rollAgain);
        return move;
    }
    int computerMoveMedium(Board gameBoard) {
        //Randomly switches between smart moves and random moves
        srand(time(NULL));
        int smartOrRandom = rand() % 2;
        if(smartOrRandom == 0) {
            return computerMoveEasy(gameBoard);
        }
        else {
            return computerMoveHard(gameBoard);
        }
    }
    int computerMoveHard(Board gameBoard) {
        //only "smart" moves
        int move;
        move = smartLogic(gameBoard);
        return move;
    }
    bool repeatMoveCheck(Board gameBoard, int move) {
        char quadrant = gameBoard.getQuadrant(move);
        if((quadrant == 'X') || (quadrant == 'O')) {
            return true;
        }
        else{
            return false;
        }
    }
    int smartLogic(Board gameBoard) {
        int move;
        if((gameBoard.getQuadrant(1) == 'O') && (gameBoard.getQuadrant(2) == 'O')){
        return 3;
        }
        return 1;
    }
    int playerWinMove(Board gameBoard) {
        //determine if player has a winning move
        
        return 5;
    }
    int compWinMove(Board gameBoard) {
        //determine if comp has a winning move

        return 5;
    }
private:
    bool playerHasWinMove;
    bool compHasWinMove;
};


#endif
