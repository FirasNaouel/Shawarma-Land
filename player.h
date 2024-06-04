#include <bits/stdc++.h>
#include "coa.h"
#include "program.h"
#include "sword.h"
#pragma once
using namespace std;

class Player : public COA {
    private:
    static const int emojiSize = 5;
    static const int backpackSize = 5;
    string emojis[emojiSize] = {"\U0001F600", "\U0001F606", "\U0001F602", "\U0001F911", "\U0001F607"};
    Item* items[backpackSize];
    Item* itemEquipped;
    public:
    Player();
    void customize(bool);
    void playerInfo();
    Item* getItem(int);
    Item* getItemEquipped();
    void setItemEquipped(Item*);
    static int getBackpackSize();
};
