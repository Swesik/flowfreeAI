#include <iostream>
#include <cctype>
#include <string>
#include <ostream>

#include "board.h"

using namespace std;

Board::Board(int w, int h):width(w),height(h){
    //init variables
        board = new char*[w];
        for (int i = 0; i < w; i++) {
            board[i] = new char[h];
        }
        
        //init the board
        for(int i = 0; i < w; i++){
            for(int j = 0; j < h; j++){
                board[i][j] = '*';
            }
        }
}

void Board::add_hole(int col, int row, char color){
    board[col][row] = toupper(color);
}

void Board::add_pipe(int col, int row, char color){
    board[col][row] = tolower(color);
}

string Board::to_string(){
    string to_ret = "";
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            to_ret += board[j][i];
            to_ret += " ";
        }
        to_ret += "\n";
    }
    return to_ret;
}

bool Board::is_pipe(int col, int row) const{
    return islower(board[col][row]);
}

bool Board::is_hole(int col, int row) const{
    return isupper(board[col][row]);
}

char Board::get_color(int col, int row) const{
    return tolower(board[col][row]);
}

Board::~Board(){
    for(int i = 0; i < width; i++){
        delete[] board[i];
    }
    delete[] board;
}