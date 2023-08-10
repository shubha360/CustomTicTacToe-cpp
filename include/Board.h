#ifndef BOARD_H
#define BOARD_H

#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

class Board {
public:
    static const int MINIMUM_PLAYERS;
    static const int MAXIMUM_PLAYERS;

    static const int MINIMUM_ROW_COLUMN;
    static const int MAXIMUM_ROW_COLUMN;

    static const int MINIMUM_WIN_MARKERS;
    static const int MAXIMUM_WIN_MARKERS;

    Board();
    Board(int rows, int colummns, int winMarker);
    void printBoard();
    bool checkWin(int x, int y, char sign); // checks horizontally, vertically, and also diagonally for win

    void setSignAt(int x, int y, char sign) { _board[y][x] = sign; }

    int getRows() { return _rows; }
    int getColumns() { return _columns; }
    int getWinMarker() { return _winMarker; }
    char getSignAt(int x, int y) { return _board[y][x]; }

private:
    int _rows, _columns;
    int _winMarker;
    vector<string> _board;
    stringstream _firstLine, _rowDivider;

    bool checkHorizontalWin(int x, int y, char sign);
    bool checkVerticalWin(int x, int y, char sign);
    bool checkDiagonalWin(int x, int y, char sign);
};

#endif // BOARD_H
