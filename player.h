#include "coa.h"
#include "game.h"
#pragma once
using namespace std;
const int emojiSize = 4;

class Player : public COA{
private:
    string name;
    string emoji;
    int health;
    int speed;
    int strength;
    string emojis[4];

public:
    Player();

    void customize(bool c);

    void playerInfo() const;
};