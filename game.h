#include <bits/stdc++.h>
#include "program.h"
#include "player.h"
#include "room.h"
using namespace std;

class Game {
private:
    string name;
    string story;
    Player* p;
public:
    Game();
    ~Game();
    void printTxt();
    void startGame();
    void intro();
    void intro(Player& p);
    void displayMenu(); 
    void profile(); 
    void backpack(); 
    void credits(); 
    void battle();
};
