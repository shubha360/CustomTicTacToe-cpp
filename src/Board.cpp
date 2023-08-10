#include "../include/Board.h"

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

bool Board::checkWin(int x, int y, char sign) {
    return checkHorizontalWin(x, y, sign) || checkVerticalWin(x, y, sign) || checkDiagonalWin(x, y, sign);
}

bool Board::checkHorizontalWin(int x, int y, char sign) {

    int left = x - 1, right = x + 1;
    int markerCount = 1;

    while (left >= 0 && _board[y][left] == sign && markerCount < _winMarker) {
        markerCount++;
        left--;
    }

    while (right < _columns && _board[y][right] == sign && markerCount < _winMarker) {
        markerCount++;
        right++;
    }
    return markerCount >= _winMarker;
}

bool Board::checkVerticalWin(int x, int y, char sign) {
    int up = y - 1, down = y + 1;
    int markerCount = 1;

    while (up >= 0 && _board[up][x] == sign && markerCount < _winMarker) {
        markerCount++;
        up--;
    }

    while (down < _rows && _board[down][x] == sign && markerCount < _winMarker) {
        markerCount++;
        down++;
    }
    return markerCount >= _winMarker;
}

bool Board::checkDiagonalWin(int x, int y, char sign) {
    
    // Top left to bottom right diagonal

    int upLeftX = x - 1, upLeftY = y - 1;
    int downRightX = x + 1, downRightY = y + 1;
    int markerCount = 1;
    
    while (upLeftX >= 0 && upLeftY >= 0 && _board[upLeftX][upLeftY] == sign && markerCount < _winMarker) {
        markerCount++;
        upLeftX--;
        upLeftY--;
    }

    while (downRightX < _columns && downRightY < _rows && _board[downRightX][downRightY] == sign && markerCount < _winMarker) {
        markerCount++;
        downRightX++;
        downRightY++;
    }

    if (markerCount >= _winMarker) {
        return true;
    }

    // Top right to bottom left diagonal

    int upRightX = x + 1, upRightY = y - 1;
    int downLeftX = x - 1, downLeftY = y + 1;
    markerCount = 1;

    while (upRightX < _columns && upRightY >= 0 && _board[upRightX][upRightY] == sign && markerCount < _winMarker) {
        markerCount++;
        upRightX++;
        upRightY--;
    }

    while (downLeftX >= 0 && downLeftY < _rows && _board[downLeftX][downLeftY] == sign && markerCount < _winMarker) {
        markerCount++;
        downLeftX--;
        downRightY++;
    }

    return markerCount >= _winMarker;
}