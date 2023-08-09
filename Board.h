#ifndef BOARD_H
#define BOARD_H

#include <sstream>

using namespace std;

class Board {
public:
    Board(int rows, int colummns);
    ~Board();

    void printBoard();

    int getRows();
    int getColummns();
    char** getBoard();

private:
    int _rows, _colummns;
    char** _board;
    stringstream _firstLine, _rowDivider;
};

#endif // BOARD_H
