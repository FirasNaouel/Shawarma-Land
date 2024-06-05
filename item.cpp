#include "item.h"
using namespace std;

Item::Item() {
    
}

Item::Item(string n, int d, double r, bool u) {
    
}

Item::Item(string n, int h, double r, int q) {
    
}

int Item::getDamage() {
    return damage;
}

double Item::getHitRate() {
    return hitRate;
}

string Item::getName() {
    return name;
}

string Item::getEmoji() {
    return emoji;
}

bool Item::getUnlocked() {
    return unlocked;
}

int Item::getQuantity() {
    return quantity;
}

int Item::getHeal() {
    return heal;
}

void Item::setDamage(int d) {
    damage = d;
}

void Item::setHitRate(double r) {
    hitRate = r;
}

void Item::setName(string n) {
    name = n;
}

void Item::setEmoji(string e) {
    emoji = e;
}

void Item::setUnlocked(bool u) {
    unlocked = u;
}

void Item::setQuantity(int q) {
    quantity = q;
}

void Item::setHeal(int h) {
    heal = h;
}
