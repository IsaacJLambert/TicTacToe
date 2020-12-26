#ifndef BOARD_H
#define BOARD_H
#include <iostream>
using namespace std;

class Board {
public:
    Board() { resetBoard(); }
    bool getState() { return gameState; }
    void setStateWin() { gameState = true; }
    void resetBoard() {
        one = '1';
        two = '2';
        three = '3';
        four = '4';
        five = '5';
        six = '6';
        seven = '7';
        eight = '8';
        nine = '9';
        moves = 0;
        playerOneWin = false;
        playerTwoWin = false;
        tie = false;
        gameState = false;
        }
    void drawComp() {
        cout << "\n\n\tTic-Tac-Toe\n\n";
        cout << "Player (X) -- Computer (O)\n\n";
        drawBoard();
    }
    void drawPlayer() {
        cout << "\n\n\tTic-Tac-Toe\n\n";
        cout << "Player 1 (X) -- Player 2 (O)\n\n";
        drawBoard();
    }
    void player1Win(){ playerOneWin == true;}
    void player2Win(){ playerTwoWin == true;}
    void updateMove1(int input){
        switch (input) {
        case 1:
            one = 'X';
            break;
        case 2:
            two = 'X';
            break;
        case 3:
            three = 'X';
            break;
        case 4:
            four = 'X';
            break;
        case 5:
            five = 'X';
            break;
        case 6:
            six = 'X';
            break;
        case 7:
            seven = 'X';
            break;
        case 8:
            eight = 'X';
            break;
        case 9:
            nine = 'X';
            break;
        default:
            throw true;
            break;
        }
    }
    void updateMove2(int input){
        switch (input) {
        case 1:
            one = 'O';
            break;
        case 2:
            two = 'O';
            break;
        case 3:
            three = 'O';
            break;
        case 4:
            four = 'O';
            break;
        case 5:
            five = 'O';
            break;
        case 6:
            six = 'O';
            break;
        case 7:
            seven = 'O';
            break;
        case 8:
            eight = 'O';
            break;
        case 9:
            nine = 'O';
            break;
        default:
            throw true;
            break;
        }
    }
    bool getPlayer1Win() { return playerOneWin;}
    bool getPlayer2Win() { return playerTwoWin;}
    void drawBoard() {
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
    void verifyWin() {
        //123
        if((one == two) && (two == three)) {
            if(one == 'X') {
                playerOneWin = true;
            }
            if(one == 'O') {
                playerTwoWin = true;
            }
        }
        //456
        else if((four == five) && (five == six)) {
            if(four == 'X') {
                playerOneWin = true;
            }
            if(four == 'O') {
                playerTwoWin = true;
            }
        }
        //789
        else if((seven == eight) && (eight == nine)) {
            if(seven == 'X') {
                playerOneWin = true;
            }
            if(seven == 'O') {
                playerTwoWin = true;
            }
        }
        //147
        else if((one == four) && (four == seven)) {
            if(four == 'X') {
                playerOneWin = true;
            }
            if(four == 'O') {
                playerTwoWin = true;
            }
        }
        //258
        else if((two == five) && (five == eight)) {
            if(two == 'X') {
                playerOneWin = true;
            }
            if(two == 'O') {
                playerTwoWin = true;
            }
        }
        //369
        else if((three == six) && (six == nine)) {
            if(three == 'X') {
                playerOneWin = true;
            }
            if(three == 'O') {
                playerTwoWin = true;
            }
        }
        //159
        else if((one == five) && (five == nine)) {
            if(one == 'X') {
                playerOneWin = true;
            }
            if(one == 'O') {
                playerTwoWin = true;
            }
        }
        //357
        else if((three == five) && (five == seven)) {
            if(three == 'X') {
                playerOneWin = true;
            }
            if(three == 'O') {
                playerTwoWin = true;
            }
        }
        //tie?
        else if(checkTie()) {
            tie = true;
        }
    }
    bool checkTie() {
        if(moves == 9){
            return true;
        }
        else{
            return false;
        }
    }
    bool getTie() {return tie;}
    void operator++(){
        moves++;
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
    bool tie;
    int moves;
    bool gameState;
};

#endif