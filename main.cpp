#include <iostream>
#include "board.h"
using namespace std;

int main(){
    Board board(5,5);
    board.add_hole(0,0,'r');
    board.add_hole(1,4,'r');
    board.add_hole(2,0,'g');
    board.add_hole(1,3,'g');
    board.add_hole(4,0,'y');
    board.add_hole(3,3,'y');
    board.add_hole(2,1,'b');
    board.add_hole(2,4,'b');
    board.add_hole(3,4,'o');
    board.add_hole(4,1,'o');
    cout << board.to_string() << endl;
}