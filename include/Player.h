#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

class Player {
public:
    static const string DEFAULT_PLAYER_NAME;
    static const char DEFAULT_PLAYER_SIGN;

    Player();
    Player(string name, char sign);

    string getName() { return _name; }
    char getSign() { return _sign; }

private:
    string _name;
    char _sign;
};

#endif // PLAYER_H
