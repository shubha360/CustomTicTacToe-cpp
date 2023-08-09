#include "Player.h"

Player::Player(string name, char sign) {
    _name = name;
    _sign = sign;
}

string Player::getName() {
    return _name;
}

char Player::getSign() {
    return _sign;
}
