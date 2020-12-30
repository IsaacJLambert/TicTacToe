#ifndef BOARD_H
#define BOARD_H
#include <iostream>
using namespace std;

class Board {
public:
    Board() { resetBoard(); }
    bool getState() { return gameState; }
    void resetBoard() {
        board[0] = '1';
        board[1] = '2';
        board[2] = '3';
        board[3] = '4';
        board[4] = '5';
        board[5] = '6';
        board[6] = '7';
        board[7] = '8';
        board[8] = '9';
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
            board[0] = 'X';
            break;
        case 2:
            board[1] = 'X';
            break;
        case 3:
            board[2] = 'X';
            break;
        case 4:
            board[3] = 'X';
            break;
        case 5:
            board[4] = 'X';
            break;
        case 6:
            board[5] = 'X';
            break;
        case 7:
            board[6] = 'X';
            break;
        case 8:
            board[7] = 'X';
            break;
        case 9:
            board[8] = 'X';
            break;
        default:
        //invalid input
            throw true;
            break;
        }
    }
    void updateMove2(int input){
        switch (input) {
        case 1:
            board[0] = 'O';
            break;
        case 2:
            board[1] = 'O';
            break;
        case 3:
            board[2] = 'O';
            break;
        case 4:
            board[3] = 'O';
            break;
        case 5:
            board[4] = 'O';
            break;
        case 6:
            board[5] = 'O';
            break;
        case 7:
            board[6] = 'O';
            break;
        case 8:
            board[7] = 'O';
            break;
        case 9:
            board[8] = 'O';
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
        cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "  " << endl;
        cout << "_____|_____|_____" << endl;

        //second row
        cout << "     |     |     " << endl;
        cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "  " << endl;
        cout << "_____|_____|_____" << endl;

        //third row
        cout << "     |     |     " << endl;
        cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "  " << endl;
        cout << "     |     |     " << endl;
    }
    void verifyWin() {
        //123
        if((board[0] == board[1]) && (board[1] == board[2])) {
            if(board[0] == 'X') {
                playerOneWin = true;
            }
            if(board[0] == 'O') {
                playerTwoWin = true;
            }
            gameState = true;
        }
        //456
        else if((board[3] == board[4]) && (board[4] == board[5])) {
            if(board[3] == 'X') {
                playerOneWin = true;
            }
            if(board[3] == 'O') {
                playerTwoWin = true;
            }
            gameState = true;
        }
        //789
        else if((board[6] == board[7]) && (board[7] == board[8])) {
            if(board[6] == 'X') {
                playerOneWin = true;
            }
            if(board[6] == 'O') {
                playerTwoWin = true;
            }
            gameState = true;
        }
        //147
        else if((board[0] == board[3]) && (board[3] == board[6])) {
            if(board[3] == 'X') {
                playerOneWin = true;
            }
            if(board[3] == 'O') {
                playerTwoWin = true;
            }
            gameState = true;
        }
        //258
        else if((board[1] == board[4]) && (board[4] == board[7])) {
            if(board[1] == 'X') {
                playerOneWin = true;
            }
            if(board[1] == 'O') {
                playerTwoWin = true;
            }
            gameState = true;
        }
        //369
        else if((board[2] == board[5]) && (board[5] == board[8])) {
            if(board[2] == 'X') {
                playerOneWin = true;
            }
            if(board[2] == 'O') {
                playerTwoWin = true;
            }
            gameState = true;
        }
        //159
        else if((board[0] == board[4]) && (board[4] == board[8])) {
            if(board[0] == 'X') {
                playerOneWin = true;
            }
            if(board[0] == 'O') {
                playerTwoWin = true;
            }
            gameState = true;
        }
        //357
        else if((board[2] == board[4]) && (board[4] == board[6])) {
            if(board[2] == 'X') {
                playerOneWin = true;
            }
            if(board[2] == 'O') {
                playerTwoWin = true;
            }
            gameState = true;
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
    char getQuadrant(int position) {
        switch(position) {
            case 1:
                return board[0]; 
                break;
            case 2:
                return board[1]; 
                break;
            case 3:
                return board[2]; 
                break;
            case 4:
                return board[3]; 
                break;
            case 5:
                return board[4]; 
                break;
            case 6:
                return board[5]; 
                break;
            case 7:
                return board[6]; 
                break;
            case 8:
                return board[7]; 
                break;
            case 9:
                return board[8]; 
                break;
            default:
                return 0;
                break;
        }
    }
    void operator++(){
        moves++;
    }
private:
    char board[9];
    bool playerOneWin;
    bool playerTwoWin;
    bool tie;
    int moves;
    bool gameState;
};

#endif