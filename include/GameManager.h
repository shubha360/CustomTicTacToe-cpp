#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <conio.h>

#include "Board.h"
#include "Player.h"

class GameManager {
public:
    GameManager();
    void init();
    void play();

private:
    Board _board;
    vector<Player> _players;
    int _playerCount;

    void _reportBadInput();
    bool _nameAvailable(string name, int index); // checks if the name is already taken
    bool _signAvailable(char sign, int index); // checks if the sign is already taken
};

#endif // GAMEMANAGER_H
