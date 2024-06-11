#include <bits/stdc++.h>
using namespace std;

// COA does not stand for "Canadian Orthopaedic Association," but rather "Clumps of Atoms."
// COA represents a Character Object in a game, encapsulating attributes like name, health, speed, strength, and emoji representation.
// It provides methods for accessing and modifying these attributes.
class COA {
protected:
    string name;
    string emoji;
    int health;
    int speed;
    int strength;
public:
    COA();
    COA(string, string, int, int, int);
    virtual ~COA();
    virtual string getName();
    virtual int getHealth();
    virtual int getSpeed();
    virtual int getStrength();
    virtual string getEmoji();
    virtual void setHealth(int);
    virtual void setSpeed(int);
    virtual void setStrength(int);
    virtual void setEmoji(string);
};
