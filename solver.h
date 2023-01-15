#ifndef SOLVER_H
#define SOLVER_H
#include "board.h"

class Solver{
public:
    bool is_valid(const Board& state) const;
    bool is_solved(const Board& state) const;
    Board solve(Board board);
};

#endif