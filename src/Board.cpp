#include "../include/Board.h"

const int Board::MINIMUM_PLAYERS = 2;
const int Board::MAXIMUM_PLAYERS = 4;

const int Board::MINIMUM_ROW_COLUMN = 1;
const int Board::MAXIMUM_ROW_COLUMN = 9;

const int Board::MINIMUM_WIN_MARKERS = 3;
const int Board::MAXIMUM_WIN_MARKERS = 9;

Board::Board() {
    _rows = _columns = -1;
    _winMarker = -1;
}

Board::Board(int rows, int columns, int winMarker) {
    _rows = rows;
    _columns = columns;
    _winMarker = winMarker;
    _rowDivider << "    ---";
    _firstLine << "\n      |";

    for (int i = 0; i < rows; i++) {
        _board.push_back(string(columns, ' '));
    }

    // initializes the row divider and first line according to the width of the board
    for (int i = 0; i < columns; i++) {
        _rowDivider << "----";
        _firstLine << " " << i + 1 << " |";
    }
}

void Board::printBoard() {
    for (int i = -1; i < _rows; i++) {

        if (i == -1) {
            cout << _firstLine.str() << endl;
        }
        else {
            stringstream currentRow;
            currentRow << "    ";
            for (int j = -1; j < _columns; j++) {
                if (j == -1) {
                    currentRow << i + 1 << " |";
                } else {
                    currentRow << " " << _board[i][j] << " |";
                }
            }
            cout << currentRow.str() << endl;
        }
        cout << _rowDivider.str() << endl;
    }
}

// checks horizontally, vertically, and also diagonally for win
bool Board::checkWin(int x, int y, char sign) {
    return checkHorizontalWin(x, y, sign) || checkVerticalWin(x, y, sign) || checkDiagonalWin(x, y, sign);
}

/*
How the individual checking functions work -
Take the horizontal one for example,
Suppose the player inputted at (x, y),
The function initializes two pointers,
One at the left (x - 1) and other one at the right (x + 1) of (x, y),
Left one goes to the left and right one goes to the right of (x y) while they are inside the board and mark is the same,
A counter variable counts until desired number of mars are found,
Returns true if found

Functionality of rest of the checking functions are same.
The diagonal one is longer because it has to cover two diagonals (top left to bottom right and top right to bottom left).
*/

bool Board::checkHorizontalWin(int x, int y, char sign) {

    int markerCount = 1;

    int left = x - 1;
    while (left >= 0 && _board[y][left] == sign && markerCount < _winMarker) {
        markerCount++;
        left--;
    }

    int right = x + 1;
    while (right < _columns && _board[y][right] == sign && markerCount < _winMarker) {
        markerCount++;
        right++;
    }
    return markerCount >= _winMarker;
}

bool Board::checkVerticalWin(int x, int y, char sign) {

    int markerCount = 1;

    int up = y - 1;
    while (up >= 0 && _board[up][x] == sign && markerCount < _winMarker) {
        markerCount++;
        up--;
    }

    int down = y + 1;
    while (down < _rows && _board[down][x] == sign && markerCount < _winMarker) {
        markerCount++;
        down++;
    }
    return markerCount >= _winMarker;
}

bool Board::checkDiagonalWin(int x, int y, char sign) {

    // Top left to bottom right diagonal
    int markerCount = 1;

    int upLeftX = x - 1, upLeftY = y - 1;
    while (upLeftX >= 0 && upLeftY >= 0 && _board[upLeftY][upLeftX] == sign && markerCount < _winMarker) {
        markerCount++;
        upLeftX--;
        upLeftY--;
    }

    int downRightX = x + 1, downRightY = y + 1;
    while (downRightX < _columns && downRightY < _rows && _board[downRightY][downRightX] == sign && markerCount < _winMarker) {
        markerCount++;
        downRightX++;
        downRightY++;
    }

    if (markerCount >= _winMarker) {
        return true;
    }

    // Top right to bottom left diagonal
    markerCount = 1;

    int upRightX = x + 1, upRightY = y - 1;
    while (upRightX < _columns && upRightY >= 0 && _board[upRightY][upRightX] == sign && markerCount < _winMarker) {
        markerCount++;
        upRightX++;
        upRightY--;
    }

    int downLeftX = x - 1, downLeftY = y + 1;
    while (downLeftX >= 0 && downLeftY < _rows && _board[downLeftY][downLeftX] == sign && markerCount < _winMarker) {
        markerCount++;
        downLeftX--;
        downLeftY++;
    }

    return markerCount >= _winMarker;
}
