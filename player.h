#include <bits/stdc++.h>
#include "coa.h"
#include "program.h"
#include "sword.h"
#include "potion.h"
#pragma once
using namespace std;

class Player : public COA {
    private:
    static const int emojiSize = 5;
    static const int swordSize = 5;
    static const int potionSize = 3;
    string emojis[emojiSize] = {"\U0001F600", "\U0001F606", "\U0001F602", "\U0001F911", "\U0001F607"};
    Sword* swords[swordSize];
    Sword* swordEquipped;
    Potion* potions[potionSize];
    public:
    Player();
    void customize(bool);
    void playerInfo();
    Sword* getSword(int);
    Potion* getPotion(int);
    Sword* getSwordEquipped();
    void setSwordEquipped(Sword*);
    static int getSwordSize();
    static int getPotionSize();
    void heal(int);
};
