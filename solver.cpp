#include <algorithm>
#include "solver.h"

using namespace std;
struct Move
{
    Board state;
    int col, row;
};

class compare_moves{
private:
    int dist_metric(Board state, int col, int row){
        return min(col,state.width-col-1) + min(row,state.height-row-1);
    }
public:
    bool operator()(Move a, Move b){
        return dist_metric(a.state,a.col,a.row) < dist_metric(b.state,b.col,b.row);
    }
};

int count_neighbors(const Board& state,int i,int j){
    int neighbors = 0;
    if(i-1 >=0 && state.get_color(i,j) == state.get_color(i-1,j)){
        neighbors += 1;
    }
    if(i+1 < state.width && state.get_color(i,j) == state.get_color(i+1,j)){
        neighbors += 1;
    }
    if(j-1 >= 0 && state.get_color(i,j) == state.get_color(i,j-1)){
        neighbors += 1;
    }

    if(j+1 < state.height && state.get_color(i,j) == state.get_color(i,j+1)){
        neighbors += 1;
    }
    return neighbors;
}
bool Solver::is_solved(const Board& state) const{
    for(int i = 0; i < state.width; i++){
        for(int j = 0; j< state.height; j++){
            if(state.is_pipe(i,j) && count_neighbors(state,i,j) !=2){
                return false;
            }
            if(state.is_hole(i,j) && count_neighbors(state,i,j) != 1){
                return false;
            }
        }
    }
    return true;
}

//lowest value when closest to a corner