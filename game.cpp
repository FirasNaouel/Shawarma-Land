#include "game.h"
using namespace std;

Game::Game() {
    fstream file("story.txt", ios::in);
    stringstream buffer;
    buffer << file.rdbuf();
    file.close();

    name = "Shawarma Land";
    story = buffer.str();
    p = new Player();
}

Game::~Game() {
    delete p;
}

void Game::startGame() {
    intro();
    intro(*p);
    displayMenu();
}

void Game::intro() {
    Program::clearScreen();
    cout << story << endl;
    cout << endl << "Welcome to " << Program::white() << name << Program::colourOFF() << endl;
    Program::enterContinue();
}

void Game::intro(Player& p) {
    p.customize(Program::question("Would you like to forge your destiny? (y/n): ", 'y', 'n'));
    Program::clearScreen();
    p.playerInfo();
    Program::enterContinue();
}

void Game::displayMenu() {
    Program::clearScreen();
    cout << Program::white() + "=== " +  Program::colourOFF() + Program::yellow() + "Shawarma Land" + Program::colourOFF() + Program::white() + " ===" +  Program::colourOFF() << endl;
    cout << endl << "1 - " + Program::white() + "Profile" +  Program::colourOFF() << endl;
    cout << endl << "2 - " + Program::white() + "Backpack" +  Program::colourOFF() << endl;
    cout << endl << "3 - " + Program::white() + "Battle" +  Program::colourOFF() << endl;
    cout << endl << "4 - " + Program::white() + "Credits" +  Program::colourOFF() << endl << endl;
    cout << "Note: Enter the corresponding integer of the menu options to access it" << endl << endl;
    switch (Program::question(1, 4)) {
        case 1:
            profile();
            break;
        case 2:
            backpack();
            break;
        case 3:
            battle();
            break;
        case 4:
            credits();
            break;
    }
}

void Game::profile() {
    Program::clearScreen();
    cout << Program::white() + "=== " +  Program::colourOFF() + Program::yellow() + "Character Profile" + Program::colourOFF() + Program::white() + " ===" +  Program::colourOFF() << endl;
    cout << endl;
    p->playerInfo();
    cout << endl << "Note: Enter '0' to return to menu" << endl << endl;
    Program::question(0, 0);
    displayMenu();
}

void Game::backpack() {
    int numUnlocked = -1;
    Program::clearScreen();
    cout << Program::white() + "=== " +  Program::colourOFF() + Program::yellow() + "Backpack" + Program::colourOFF() + Program::white() + " ===" +  Program::colourOFF() << endl;
    cout << endl << "-- Backpack Navigation Tutorial --" << endl;
    cout << endl << " - Enter '1' to change swords" << endl;
    cout << " - Enter '0' to return to menu" << endl;
    cout << endl << "Swords:" << endl;
    for (int i = 0; i < Player::getSwordSize(); i++) {
        if (p->getSword(i) != nullptr) {
            if (p->getSword(i)->getUnlocked()) {
                numUnlocked++;
                if (p->getSword(i) == p->getSwordEquipped()) {
                    cout << endl << i << " - " << Program::white() << p->getSword(i)->getName() << Program::colourOFF() << Program::cyan() << " (Equipped)" << Program::colourOFF() << endl;
                    cout << "   Emoji: " << p->getSword(i)->getEmoji() << endl;
                    cout << "   Damage: " << Program::red() << p->getSword(i)->getDamage() << Program::colourOFF() << endl;
                    cout << "   Hit Rate: " << p->getSword(i)->getHitRate()*100 << endl;
                } else {
                    cout << endl << i << " - " << Program::white() << p->getSword(i)->getName() << Program::colourOFF() << endl;
                    cout << "   Emoji: " << p->getSword(i)->getEmoji() << endl;
                    cout << "   Damage: " << Program::red() << p->getSword(i)->getDamage() << Program::colourOFF() << endl;
                    cout << "   Hit Rate: " << p->getSword(i)->getHitRate()*100 << endl;
                }
            }
        }
    }
    cout << endl << "Potions:" << endl;
    for (int i = 0; i < Player::getPotionSize(); i++) {
        if (p->getPotion(i) != nullptr) {
            if (p->getPotion(i)->getQuantity() != 0) {
                cout << endl << i << " - " << Program::white() << p->getPotion(i)->getName() << Program::colourOFF() << endl;
                cout << "   Emoji: " << p->getPotion(i)->getEmoji() << endl;
                cout << "   Heal: " << Program::green() << p->getPotion(i)->getHeal() << Program::colourOFF() << endl;
                cout << "   Hit Rate: " << p->getPotion(i)->getHitRate()*100 << endl;
                cout << "   Quantity: " << p->getPotion(i)->getQuantity() << endl;
            }
        }
    }
    cout << endl;
    switch (Program::question(0, 2)) {
        case 0:
            displayMenu();
            break;
        case 1:
            if (numUnlocked != -1) {
                cout << "Enter integer corresponding to sword" << endl;
                p->setSwordEquipped((p->getSword(Program::question(0, numUnlocked))));
            } else {
                cout << "No unlocked swords available!" << endl;
            }
            backpack();
            break;
        case 2:
            p->heal(Program::question(0, 2));
            backpack();
            break;
    }
}

void Game::battle(){
    Room room;
    int previousDistance = room.findDistance();
    int currentDistance;

    cout << "Welcome to the Hot and Cold Game!" << endl;
    cout << "Your goal is to find the hidden item on the grid." << endl;
    Program::enterContinue();

    while (true) {
        Program::clearScreen();
        if (room.checkWin()) {
            cout << "Congratulations! You've found the item!" << endl;
            break;
        } else {
            cout << "You are getting " << Room::hotCold(currentDistance, previousDistance) << "." << endl;
            previousDistance = currentDistance;
        }
        room.printGrid();
        room.makeMove();
        
        currentDistance = room.findDistance();
        
    }
}

void Game::credits() {
    Program::clearScreen();
    cout << Program::white() + "=== " +  Program::colourOFF() + Program::yellow() + "Credits" + Program::colourOFF() + Program::white() + " ===" +  Program::colourOFF() << endl;
    cout << endl << "Abdualhakim Aldabibi - Creator" << endl;
    cout << endl << "Firas Naouel - Founder" << endl;
    cout << endl << "Tom Yu (A.K.A Xiucheng) - Skill Issue Consultant" << endl;
    cout << endl << "Ms. Kutschke - 4++ Consultant" << endl;
    cout << endl << "Note: Enter '0' to return to menu" << endl << endl;
    Program::question(0, 0);
    displayMenu();
}
