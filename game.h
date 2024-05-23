#include <bits/stdc++.h>
#include "program.h"
#include "player.h"
#include "menu.h"
using namespace std;

class Game {
private:
    string name;
    string story;
    Player* p;
public:
    Game();
    ~Game();
    void startGame();
    void intro();
    void intro(Player& p);
    void tutorial();
    void menu(); 
    void profile(); 
    void backpack(); 
    void credits(); 
};
