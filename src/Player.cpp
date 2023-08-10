#include "../include/Player.h"

const string Player::DEFAULT_PLAYER_NAME = "";
const char Player::DEFAULT_PLAYER_SIGN = ' ';

Player::Player() {
    _name = "";
    _sign = ' ';
}

Player::Player(string name, char sign) {
    _name = name;
    _sign = sign;
}
