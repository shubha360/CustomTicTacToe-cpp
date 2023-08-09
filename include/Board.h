#ifndef BOARD_H
#define BOARD_H

#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

class Board {
public:
    Board();
    Board(int rows, int colummns);
    void printBoard();

    int getRows() { return _rows; }
    int getColummns() { return _colummns; }
    vector<string> getBoard() { return _board; }

private:
    int _rows, _colummns;
    vector<string> _board;
    stringstream _firstLine, _rowDivider;
};

#endif // BOARD_H
