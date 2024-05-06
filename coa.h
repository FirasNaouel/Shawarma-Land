#include "program.h"

using namespace std;

// COA does not stand for "Canadian Orthopaedic Association," but rather "Clumps of Atoms."
class COA {
protected:
    // static const int NUM_OF_STATS = 3;
    string name;
    string emoji;
    // int stats[NUM_OF_STATS];
    int health;
    int speed;
    int strength;
public:
    COA();
    // COA(string, int, int, int);
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

