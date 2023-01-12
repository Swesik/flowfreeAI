#ifndef BOARD_H
#define BOARD_H
#include <string>

class Board
{
private:
    char **board;
public:
    const int width, height;

    Board(int w, int h);

    void add_hole(int col, int row, char color);

    void add_pipe(int col, int row, char color);

    bool is_pipe(int col, int row) const;
    bool is_hole(int col, int row) const;

    char get_color(int col, int row) const;

    std::string to_string();

    ~Board();
};

#endif