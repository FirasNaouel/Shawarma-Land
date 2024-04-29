#include <bits/stdc++.h>

using namespace std;

class Game {
private:
    string name;
    string story;
    bool cleared;
public:
    Game();
    Game(string, string);
    string getName();
    string getStory();
    bool getCleared();
    void setName(string);
    void setStory(string);
    void setCleared(bool);
    void customize(bool);
};
