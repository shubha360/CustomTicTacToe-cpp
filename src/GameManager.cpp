#include "../include/GameManager.h"

GameManager::GameManager() {}

void GameManager::init() {
    cout << "Welcome to Custom Tic Tac Toe!\n\n";

    do {
        cout << "How many player? <2-4>: ";
        _playerCount = getch() - 48;
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
        char sign = getch();
        cout << sign;

        _players.push_back(Player(name, sign));
        cout << endl;
    }

    int width, height;
    do {
        cout << endl << "Enter the width of the board <1 - 12>: ";
        cin >> width;

        if (width < 1 || width > 12) {
            reportBadInput();
        }
        else {
            cout << endl;
            break;
        }
    } while (true);

    do {
        cout << "Enter the height of the board <1 - 12>: ";
        cin >> height;

        if (height < 1 || height > 12) {
            reportBadInput();
        }
        else {
            cout << endl;
            break;
        }
    } while (true);

    cout << endl;
    _board = Board(height, width);
    _board.printBoard();
}

void GameManager::reportBadInput() {
    cout << "Unrecognized input!\n\n";
}
