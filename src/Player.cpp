#include "../include/Player.h"

Player::Player() {
    _name = "";
    _sign = ' ';
}

Player::Player(string name, char sign) {
    _name = name;
    _sign = sign;
}
