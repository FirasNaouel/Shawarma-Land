#include "potion.h"
using namespace std;

Potion::Potion() : Item() {
    name = "Vitality Vortex Shawarma Serum";
    emoji = "\U0001F600";
    heal = 25;
    hitRate = 0.85;
    quantity = 1;
}

Potion::Potion(string n, int h, double r, int q) : Item(n, h, r, q) {
    name = n;
    emoji = "\U0001F600";
    heal = h;
    hitRate = r;
    quantity = q;
}

int Potion::usePotion() {
    quantity--;
    return heal;
}
