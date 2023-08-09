#include "../include/Board.h"

Board::Board() {
    _rows = _colummns = -1;
}

Board::Board(int rows, int colummns) {
    _rows = rows;
    _colummns = colummns;
    _rowDivider << "    ----";
    _firstLine << "\n       |";

    for (int i = 0; i < rows; i++) {
        _board.push_back(string(colummns, ' '));
    }

    for (int i = 0; i < colummns; i++) {
        _rowDivider << "-----";
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
