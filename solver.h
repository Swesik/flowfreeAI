#include "board.h"

class Solver{
    bool is_valid(const Board& state);
    bool is_solved(const Board& state);
    std::pair<int,int> choose_next_hole(Board state);
    std::pair<int,int> choose_next_pipe(Board state);
    Board solve(Board board);
};