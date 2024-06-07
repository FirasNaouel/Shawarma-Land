#include "player.h"

using namespace std;

Player::Player() : COA() {
    name = "Zara";
    emoji = "\U0001F600";
    health = 1;
    speed = 2;
    strength = 3;
    swords[0] = new Sword();
    swords[1] = new Sword("Shawarmaster Blade", 30, 0.8, true);
    swords[2] = new Sword("Hummus Havoc", 28, 0.9, false);
    swords[3] = new Sword("Kebab Kutter", 35, 0.75, false);
    swords[3] = new Sword("4++ Smacker", 999, 0.1, false);
    potions[0] = new Potion();
    potions[1] = new Potion("Inferno Infusion Shawarma Sizzle", 40, 0.7, 2);
    potions[2] = new Potion("buykscbuysrg", 50, 0.7, 0);
    swordEquipped = swords[0];
}

Player::~Player(){
    
}

void Player::customize(bool c) {
    if (c) {
        cout << "Enter your character's name: ";
        getline(cin, name);
        
        cout << "Select an emblem for your journey (Enter corresponding number):" << endl;
        for (int i = 0; i < emojiSize; i++) {
            cout << i << ": " << emojis[i] << endl;
        }
        emoji = emojis[Program::question(0, 4)];
    }
}

void Player::playerInfo() {
    cout << "Name: " << Program::white() << name << Program::colourOFF() << endl;
    cout << "Emoji: " << emoji << endl;
    cout << "Health: " << Program::green() << health << " HP" << Program::colourOFF() << endl;
    cout << "Speed: " << Program::cyan() << speed << " SP" << Program::colourOFF() << endl;
    cout << "Strength: " << Program::red() << strength << " ATK" << Program::colourOFF() << endl;
    cout << "Sword: " << Program::white() << swordEquipped->getName() << Program::colourOFF() << endl;
}

Sword* Player::getSword(int index) {
    if (index >= 0 && index < 2) {
        return swords[index];
    } else {
        return nullptr;
    }
}

Potion* Player::getPotion(int index) {
    if (index >= 0 && index < 2) {
        return potions[index];
    } else {
        return nullptr;
    }
}

Sword* Player::getSwordEquipped() {
    return swordEquipped;
}

void Player::setSwordEquipped(Sword* newItem) {
    swordEquipped = newItem;
}

int Player::getSwordSize() {
    return swordSize;
}

int Player::getPotionSize() {
    return potionSize;
}

void Player::heal(int i) {
    health += potions[i]->usePotion();
}
