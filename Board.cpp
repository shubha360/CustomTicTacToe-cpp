#include "Board.h"

#include <iostream>
#include <sstream>

Board::Board(int rows, int colummns) {
    _rows = rows;
    _colummns = colummns;
    _board = new char*[rows];
    _rowDivider << "    ---";
    _firstLine << "\n      |";

    for (int i = 0; i < rows; i++) {
        _board[i] = new char[colummns];

        for (int j = 0; j < colummns; j++) {
            _board[i][j] = ' ';

            if (i == 0) {
                _rowDivider << "----";
                _firstLine << " " << j + 1 << " |";
            }
        }
    }
}

Board::~Board() {
    for (int i = 0; i < _rows; i++) {
        delete[] _board[i];
        _board[i] = NULL;
    }
    delete[] _board;
    _board = NULL;
}

void Board::printBoard() {
    for (int i = -1; i < _rows; i++) {
        if (i == -1) {
            cout << _firstLine.str() << endl;
        }
        else {
            stringstream currentRow;
            currentRow << "    ";
            for (int j = -1; j < _colummns; j++) {
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

int Board::getRows() {
    return _rows;
}

int Board::getColummns() {
    return _colummns;
}

char** Board::getBoard() {
    return _board;
}
