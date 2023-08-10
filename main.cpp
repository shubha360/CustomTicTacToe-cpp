#include <iostream>
#include <string>

#include "include/Board.h"
#include "include/GameManager.h"

using namespace std;

int main() {
    GameManager manager;
    manager.init();
    manager.play();
    return 0;
}
