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
        //see if computer can win in 1 move
        move = compWinMove(gameBoard);
        if(compHasWinMove) {
            return move;
        }
        //block player if they have winning move
        move = playerWinMove(gameBoard);
        if(playerHasWinMove){
            return move;
        }
        //else play near previous play

        return 1;
    }
    int playerWinMove(Board gameBoard) {
        //determine if player has a winning move
        int move;
        return move;
    }
    int compWinMove(Board gameBoard) {
        //determine if comp has a winning move
        int move;
        return move;
    }
private:
    bool playerHasWinMove;
    bool compHasWinMove;
};


#endif
