#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <vector>
#include <conio.h>
#include <string>

#include "Board.h"
#include "Player.h"

class GameManager {
public:
    GameManager();
    void init();

private:
    Board _board;
    vector<Player> _players;
    int _playerCount;

    void reportBadInput();
};

#endif // GAMEMANAGER_H
