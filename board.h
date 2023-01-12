#ifndef BOARD_H
#define BOARD_H
#include <string>
#include <vector>

class Board
{
private:
    char **board;
    vector<pair<int,int>> holes;
public:
    const int width, height;

    Board(int w, int h);

    void add_hole(int col, int row, char color);

    void add_pipe(int col, int row, char color);

    bool is_pipe(int col, int row) const;
    bool is_hole(int col, int row) const;

    char get_color(int col, int row) const;
    vector<pair<int,int>> get_holes() const;

    std::string to_string();

    ~Board();
};

#endif