#include "sword.h"
using namespace std;

Sword::Sword() : Item() {
    name = "Falafel Fury";
    emoji = "\U0001F600";
    damage = 25;
    hitRate = 0.85;
    unlocked = true;
}

Sword::Sword(string n, int d, double r, bool u) : Item(n, d, r, u) {
    name = n;
    emoji = "\U0001F600";
    damage = d;
    hitRate = r;
    unlocked = u;
}
