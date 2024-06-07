#include "game.h"
using namespace std;

Game::Game() {
    printTxt();

    name = "Shawarma Land";
    p = new Player();
}

Game::~Game() {
    delete p;
}

void Game::printTxt(){
    cout << "In the bustling streets of Shawarma Land, where savory aromas waft through the air, an epic" << endl
        << "culinary adventure awaits. Players step into the shoes of Zara, a fearless food enthusiast on a" << endl
        << "quest to uncover the secret recipe of the legendary Shawarma Master." << endl << endl
        << "Armed with only her trusty spatula and insatiable appetite, Zara traverses through vibrant" << endl
        << "markets, mysterious alleyways, and bustling kitchens, encountering a colorful cast of characters" << endl
        << "along the way. From quirky spice merchants to rival chefs, each encounter brings new challenges" << endl
        << "and delicious discoveries." << endl << endl
        << "But the journey is perilous, as Zara must navigate through spicy traps, culinary puzzles, and" << endl
        << "savory showdowns to reach the ultimate prize – the fabled Shawarma Master's recipe hidden" << endl
        << "deep within the heart of Shawarma Land." << endl << endl
        << "Will Zara emerge victorious and claim the title of Shawarma Champion? Only those with a hunger" << endl
        << "for adventure and a zest for flavor can uncover the secrets that lie within Shawarma Land." << endl;
}

void Game::startGame() {
    intro();
    intro(*p);
    displayMenu();
}

void Game::intro() {
    cout << story << endl;
    cout << endl << "Welcome to " << Program::white() << name << Program::colourOFF() << endl;
    Program::enterContinue();
}

void Game::intro(Player& p) {
    p.customize(Program::question("Would you like to forge your destiny? (y/n): ", 'y', 'n'));
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
    cout << " - Enter '2' to use a potion" << endl;
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
    Program::clearScreen();
    Room room;
    int previousDistance = room.findDistance();
    int currentDistance;
    int movementChoice = 0;

    cout << "Welcome to the Hot and Cold Game!" << endl;
    cout << "Your goal is to find the hidden item on the grid." << endl;
    cout << "Would you like to play using text keys(0) of arrow keys(1): ";
    do{
        cin >> movementChoice;
    } while(movementChoice != 0 && movementChoice != 1);
    Program::enterContinue();

    while (true) {
        Program::clearScreen();
        if (room.checkWin()) {
            cout << "Congratulations! You've found the item!" << endl;
            Program::enterContinue();
            break;
        } else {
            cout << "You are getting " << Room::hotCold(currentDistance, previousDistance) << "." << endl;
            previousDistance = currentDistance;
        }
        room.printGrid();
        room.makeMove(movementChoice);
        
        currentDistance = room.findDistance();
        
    }
    displayMenu();
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
