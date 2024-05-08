#ifndef GAME_H
#define GAME_H

#include <bits/stdc++.h>

using namespace std;

class Game {
private:
    string name;
    string story;
    bool cleared;
public:
    Game();
    string getName();
    string getStory();
    bool getCleared() const;
    void setCleared(bool);
};

#endif
