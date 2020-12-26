#ifndef BOARD_H
#define BOARD_H
#include <iostream>
using namespace std;

class Board {
public:
    Board() {
        one = '1';
        two = '2';
        three = '3';
        four = '4';
        five = '5';
        six = '6';
        seven = '7';
        eight = '8';
        nine = '9';
        playerOneWin = false;
        playerTwoWin = false;
    }
    void drawBoard() {
        cout << "\n\n\tTic-Tac-Toe\n\n";
        cout << "Player 1 (X) -- Player 2 (O)\n\n";
        //draw board
        //first row
        cout << "     |     |     " << endl;
        cout << "  " << one << "  |  " << two << "  |  " << three << "  " << endl;
        cout << "_____|_____|_____" << endl;

        //second row
        cout << "     |     |     " << endl;
        cout << "  " << four << "  |  " << five << "  |  " << six << "  " << endl;
        cout << "_____|_____|_____" << endl;

        //third row
        cout << "     |     |     " << endl;
        cout << "  " << seven << "  |  " << eight << "  |  " << nine << "  " << endl;
        cout << "     |     |     " << endl;
    }
    
private:
    char one;
    char two;
    char three;
    char four;
    char five;
    char six;
    char seven;
    char eight;
    char nine;
    bool playerOneWin;
    bool playerTwoWin;
};

#endif