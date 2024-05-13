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
    bool getCleared();
    void setCleared(bool);
};