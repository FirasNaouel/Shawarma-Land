#include "player.h"

using namespace std;

Player::Player() : COA() {
    name = "Zara";
    emoji = "\U0001F600";
    health = 1;
    speed = 2;
    strength = 3;
    items[0] = new Sword();
    items[1] = new Sword("Shawarmaster Blade", 30, 0.8, true);
    items[2] = new Sword("Hummus Havoc", 28, 0.9, false);
    items[3] = new Sword("Kebab Kutter", 35, 0.75, false);
    itemEquipped = items[0];
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
    cout << "Sword: " << Program::white() << itemEquipped->getName() << Program::colourOFF() << endl;
}

Item* Player::getItem(int index) {
    if (index >= 0 && index < 2) {
        return items[index];
    } else {
        return nullptr;
    }
}

Item* Player::getItemEquipped() {
    return itemEquipped;
}

void Player::setItemEquipped(Item* newItem) {
    itemEquipped = newItem;
}

int Player::getBackpackSize() {
    return backpackSize;
}
