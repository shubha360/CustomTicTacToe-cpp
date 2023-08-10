#include "../include/GameManager.h"

GameManager::GameManager() {
    _playerCount = -1;
}

void GameManager::init() {
    cout << "Welcome to Custom Tic Tac Toe!\n\n";

    // Taking the number of players
    do {
        cout << "How many player? <" << Board::MINIMUM_PLAYERS << "-" << Board::MAXIMUM_PLAYERS << ">: ";
        _playerCount = _getch() - 48;
        cout << _playerCount << endl;

        if (_playerCount < Board::MINIMUM_PLAYERS || _playerCount > Board::MAXIMUM_PLAYERS) {
            _reportBadInput();
        }
        else {
            break;
        }
    } while (true);

    // Taking name and sign of every player
    for (int i = 0; i < _playerCount; i++) {

        string name;
        char sign;

        // Name
        do {
            cout << endl << "Enter name for player " << (i + 1) << ": ";
            getline(cin , name);

            if (name == Player::DEFAULT_PLAYER_NAME) {
                cout << "Can't take empty name!\n\n";
            }
            else if (!_nameAvailable(name, i)) {
                cout << "Name already taken!\n\n";
            }
            else {
                break;
            }

        } while (true);

        // Sign
        do {
            cout << "Hello " << name << "! What sign would you like to play with? ";
            sign = _getch();
            cout << sign << endl;

            if (sign == Player::DEFAULT_PLAYER_SIGN || sign < 33 || sign > 126) {
                cout << "Please choose another sign!\n\n";
            }
            else if (!_signAvailable(sign, i)) {
                cout << "Sign already taken!\n\n";
            }
            else {
                break;
            }
        } while(true);

        _players.push_back(Player(name, sign));
    }

    int width, height;

    // width of the board
    do {
        cout << endl << "Enter the width of the board <" << Board::MINIMUM_ROW_COLUMN << "-" << Board::MAXIMUM_ROW_COLUMN << ">: ";
        width = _getch() - 48;
        cout << width << endl;

        if (width < Board::MINIMUM_ROW_COLUMN || width > Board::MAXIMUM_ROW_COLUMN) {
            _reportBadInput();
        }
        else {
            break;
        }
    } while (true);

    // height of the board
    do {
        cout << endl << "Enter the height of the board <" << Board::MINIMUM_ROW_COLUMN << "-" << Board::MAXIMUM_ROW_COLUMN << ">: ";
        height = _getch() - 48;
        cout << height << endl;

        if (height < Board::MINIMUM_ROW_COLUMN || height > Board::MAXIMUM_ROW_COLUMN) {
            _reportBadInput();
        }
        else {
            break;
        }
    } while (true);

    int winMarker;

    // total number of desired markers for winning
    do {
        cout << endl << "How many markers horizontal, vertical, diagonal needed to win? <" << Board::MINIMUM_WIN_MARKERS << "-" << Board::MAXIMUM_WIN_MARKERS << ">: ";
        winMarker = _getch() - 48;
        cout << winMarker << endl;

        if (winMarker < 3 || winMarker > 9) {
            _reportBadInput();
        }
        else {
            cout << endl;
            break;
        }
    } while (true);

    _board = Board(height, width, winMarker);
}

void GameManager::play() {
    cout << "Note that grid coordinates start from top left to bottom right <i.e. 1,1 is the furthest left top>.\n";
    _board.printBoard();

    int turn = 0;
    int totalTurns = _board.getRows() * _board.getColumns();

    bool isTied = true; // used at the end of the main loop to determine if match was tied

    for (int turn = 0; turn < totalTurns; turn++) {

        cout << endl;

        /*
        Example: among 3 players -
        turn 0 % 3 = 0,
        turn 1 % 3 = 1,
        turn 2 % 3 = 2,

        turn 3 % 3 = 0,
        turn 4 % 3 = 1,
        turn 5 % 3 = 2,

        the loop gos on...
        */
        Player currentPlayer = _players[turn % _playerCount];

        cout << currentPlayer.getName() << "'s turn!\n\n";

        int posX, posY;

        // loop until an empty cell is seleted
        do {
            // taking x coordinate
            do {
                cout << "Enter X coordinate. " << "<1-" << _board.getColumns() << ">: ";
                posX = _getch() - 48;
                cout << posX << endl;

                if (posX < 1 || posX > _board.getColumns()) {
                    _reportBadInput();
                }
                else {
                    posX--; // board index starts at 0
                    break;
                }
            } while (true);

            // taking y coordinate
            do {
                cout << "Enter Y coordinate. " << "<1-" << _board.getRows() << ">: ";
                posY = _getch() - 48;
                cout << posY << endl;

                if (posY < 1 || posY > _board.getRows()) {
                    _reportBadInput();
                }
                else {
                    posY--; // board index starts at 0
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

        // check win on every turn after minimum number of winning marks are placed
        // For example, if marks to win is 3, it should start checking after the 3rd turn
        // which turn == 2 because turn starts from zero.
        if (turn >= _board.getWinMarker() - 1 && _board.checkWin(posX, posY, currentPlayer.getSign())) {
            cout << currentPlayer.getName() << " won!\n\nWell played!\n\n";
            isTied = false;
            break;
        }
    }

    if (isTied) {
        cout << "Match tied! Well played!\n\n";
    }
}

void GameManager::_reportBadInput() {
    cout << "Unrecognized input!\n\n";
}

// checks if the name is already taken
bool GameManager::_nameAvailable(string name, int index) {
    for (int i = 0; i < index; i++) {
        if (_players[i].getName() == name) {
            return false;
        }
    }
    return true;
}

// checks if the sign is already taken
bool GameManager::_signAvailable(char sign, int index) {
    for (int i = 0; i < index; i++) {
        if (_players[i].getSign() == sign) {
            return false;
        }
    }
    return true;
}
