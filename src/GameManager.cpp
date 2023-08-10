#include "../include/GameManager.h"

GameManager::GameManager() {
    _playerCount = -1;
}

void GameManager::init() {
    cout << "Welcome to Custom Tic Tac Toe!\n\n";

    do {
        cout << "How many player? <2-4>: ";
        _playerCount = _getch() - 48;
        cout << _playerCount;

        if (_playerCount < 2 || _playerCount > 4) {
            reportBadInput();
        }
        else {
            cout << endl;
            break;
        }
    } while (true);

    for (int i = 0; i < _playerCount; i++) {

        cout << endl << "Enter name for player " << (i + 1) << ": ";
        string name;
        getline(cin , name);

        cout << "Hello " << name << "! What sign would you like to play with? ";
        char sign = _getch();
        cout << sign;

        _players.push_back(Player(name, sign));
        cout << endl;
    }

    int width, height;
    do {
        cout << endl << "Enter the width of the board <1 - 9>: ";
        width = _getch() - 48;
        cout << width;

        if (width < 1 || width > 9) {
            reportBadInput();
        }
        else {
            cout << endl;
            break;
        }
    } while (true);

    do {
        cout << "Enter the height of the board <1 - 9>: ";
        height = _getch() - 48;
        cout << height;

        if (height < 1 || height > 9) {
            reportBadInput();
        }
        else {
            cout << endl;
            break;
        }
    } while (true);

    int winMarker;

    do {
        cout << endl << "How many markers horizontal, vertical, diagonal needed to win? <3 - 9>: ";
        winMarker = _getch() - 48;
        cout << winMarker;

        if (winMarker < 3 || winMarker > 9) {
            reportBadInput();
        }
        else {
            cout << endl << endl;
            break;
        }
    } while (true);

    _board = Board(height, width, winMarker);
}

void GameManager::play() {
    cout << "Note that grid coordinates start from top left to bottom right <i.e. 1,1 is the furthest left top>.\n";
    _board.printBoard();

    int turn = 0;

    for (int turn = 0; turn < _board.getRows() * _board.getColumns(); turn++) {

        cout << endl;
        
        Player currentPlayer = _players[turn % _playerCount];

        cout << currentPlayer.getName() << "'s turn!\n\n";        

        int posX, posY;

        do {
            do {
                cout << "Enter X coordinate. " << "<1-" << _board.getColumns() << ">: ";
                posX = _getch() - 48;
                cout << posX;

                if (posX < 1 || posX > _board.getColumns()) {
                    reportBadInput();
                }
                else {
                    posX--;
                    cout << endl;
                    break;
                }
            } while (true);

            do {
                cout << "Enter Y coordinate. " << "<1-" << _board.getRows() << ">: ";
                posY = _getch() - 48;
                cout << posY;

                if (posY < 1 || posY > _board.getRows()) {
                    reportBadInput();
                }
                else {
                    posY--;
                    cout << endl;
                    break;
                }
            } while (true);

            if (_board.getSignAt(posX, posY) != ' ') {
                cout << "Cell is not empty!\n\n";
            }
            else {
                cout << endl << endl;
                _board.setSignAt(posX, posY, currentPlayer.getSign());
                _board.printBoard();
                cout << endl;
                break;
            }

        } while (true);
        if (_board.checkWin(posX, posY, currentPlayer.getSign())) {
            cout << currentPlayer.getName() << " won!\n\nWell played!\n\n";
            // break;
        }
    }
}

void GameManager::reportBadInput() {
    cout << "Unrecognized input!\n\n";
}
