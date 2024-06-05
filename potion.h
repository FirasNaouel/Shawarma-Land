#include "item.h"
using namespace std;

class Potion : public Item {
private:
public:
    Potion();
    Potion(string, int, double, int);
    int usePotion();
};
