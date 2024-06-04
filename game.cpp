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
    tutorial();
    menu();
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

void Game::tutorial() {
    cout << "-- Menu Navigation Tutorial --" << endl;
    cout << endl << " - Enter the corresponding integer of the menu option" << endl;
    cout << " - Enter 0 to return to menu" << endl;
    Program::enterContinue();
}

void Game::menu() {
    Program::clearScreen();
    cout << Program::white() + "=== " +  Program::colourOFF() + Program::yellow() + "Shawarma Land" + Program::colourOFF() + Program::white() + " ===" +  Program::colourOFF() << endl;
    cout << endl << "1 - " + Program::white() + "Profile" +  Program::colourOFF() << endl;
    cout << endl << "2 - " + Program::white() + "Backpack" +  Program::colourOFF() << endl;
    cout << endl << "3 - " + Program::white() + "Battle" +  Program::colourOFF() << endl;
    cout << endl << "4 - " + Program::white() + "Credits" +  Program::colourOFF() << endl << endl;
    switch (Program::question(1, 4)) {
        case 1:
            profile();
            break;
        case 2:
            backpack();
            break;
        case 3:
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
    cout << endl;
    Program::question(0, 0);
    menu();
}

void Game::backpack() {
    int numUnlocked = -1;
    Program::clearScreen();
    cout << Program::white() + "=== " +  Program::colourOFF() + Program::yellow() + "Backpack" + Program::colourOFF() + Program::white() + " ===" +  Program::colourOFF() << endl;
    cout << endl << "-- Backpack Navigation Tutorial --" << endl;
    cout << endl << " - Enter 1 to change swords" << endl;
    cout << " - Enter the corresponding integer of the sword" << endl;
    cout << endl << "Swords:" << endl;
    for (int i = 0; i < Player::getBackpackSize(); i++) {
        if (p->getItem(i) != nullptr) {
            if (p->getItem(i)->getUnlocked()) {
                numUnlocked++;
                if (p->getItem(i) == p->getItemEquipped()) {
                    cout << endl << i << " - " << p->getItem(i)->getName() << " (Equipped)" << endl;
                    cout << "   Emoji: " << p->getItem(i)->getEmoji() << endl;
                    cout << "   Damage: " << p->getItem(i)->getDamage() << endl;
                    cout << "   Hit Rate: " << p->getItem(i)->getHitRate()*100 << endl;
                } else {
                    cout << endl << i << " - " << p->getItem(i)->getName() << endl;
                    cout << "   Emoji: " << p->getItem(i)->getEmoji() << endl;
                    cout << "   Damage: " << p->getItem(i)->getDamage() << endl;
                    cout << "   Hit Rate: " << p->getItem(i)->getHitRate()*100 << endl;
                }
            }
        }
    }
    cout << endl;
    switch (Program::question(0, 1)) {
        case 0:
            menu();
            break;
        case 1:
            if (numUnlocked != -1) {
                cout << "Enter integer corresponding to sword" << endl;
                p->setItemEquipped((p->getItem(Program::question(0, numUnlocked))));
            } else {
                cout << "No unlocked swords available!" << endl;
            }
            backpack();
            break;
    }
}

void Game::credits() {
    Program::clearScreen();
    cout << Program::white() + "=== " +  Program::colourOFF() + Program::yellow() + "Credits" + Program::colourOFF() + Program::white() + " ===" +  Program::colourOFF() << endl;
    cout << endl << "Abdualhakim Aldabibi - Creator" << endl;
    cout << endl << "Firas Naouel - Founder" << endl;
    cout << endl << "Tom Yu (A.K.A Xiucheng) - Skill Issue Consultant" << endl;
    cout << endl << "Ms. Kutschke - 4++ Consultant" << endl;
    cout << endl;
    Program::question(0, 0);
    menu();
}
