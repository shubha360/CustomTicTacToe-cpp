#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

class Player {
public:
    Player(string name, char sign);
    string getName();
    char getSign();

private:
    string _name;
    char _sign;
};

#endif // PLAYER_H
