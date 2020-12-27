#ifndef COMPUTER_H
#define COMPUTER_H
#include "Board.h"
#include <ctime>
using namespace std;

class Computer{
public:
int computerMoveEasy(Board gameBoard) {
    int move;
    bool rollAgain;
    char quadrant;
    srand(time(NULL));
    do{
        rollAgain = false;
        //get a number 1-9
        move = rand() % 9 + 1;
        //verify that someone hasn't gone there yet
        quadrant = gameBoard.getQuadrant(move);
        if((quadrant == 'X') || (quadrant == 'O')) {
            rollAgain = true;
        }
    }
    while(rollAgain);
    return move;
}
int computerMoveMedum() {
    //TO DO
    return 0;
}
int computerMoveHard() {
    //TO DO
    return 0;
}
};


#endif