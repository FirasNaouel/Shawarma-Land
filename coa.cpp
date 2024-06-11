#include "coa.h"
using namespace std;

// Implementation of the COA class methods
// These methods handle the attributes and behaviors of a Character Object in a game
// Attributes include name, health, speed, strength, and emoji representation
// Getter methods retrieve the values of these attributes, while setter methods modify them

COA::COA() {
    
}
COA::~COA(){
    
}

string COA::getName() {
    return name;
}

int COA::getHealth() {
    return health;
}

int COA::getSpeed() {
    return speed;
}

int COA::getStrength() {
    return strength;
}

string COA::getEmoji() {
    return emoji;
}

void COA::setHealth(int h) {
    health = h;
}

void COA::setSpeed(int sp) {
    speed = sp;
}

void COA::setStrength(int st) {
    strength = st;
}

void COA::setEmoji(string e) {
    emoji = e;
}
