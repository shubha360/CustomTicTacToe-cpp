#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

class Player {
public:
    Player();
    Player(string name, char sign);

    string getName() { return _name; }
    char getSign() { return _sign; }

private:
    string _name;
    char _sign;
};

#endif // PLAYER_H
