#include "menu.h"

using namespace std;

void intro(Game& game) {
    Program::clearScreen();
    cout << game.getStory() << endl;
    cout << endl << "Welcome to " << Program::white() << game.getName() << Program::colourOFF() << endl;
    Program::enterContinue();
    Program::clearScreen();
}

void intro(Player& player) {
    player.customize(Program::question("Would you like to forge your destiny? (y/n): ", 'y', 'n'));
    Program::clearScreen();
    player.playerInfo();
    Program::enterContinue();
}

void startGame() {
    Menu::menu();
}

int main() {
    Game game;
    Player player;
    while(!game.getCleared()) {
        intro(game);
        intro(player);
        game.setCleared(true);
    }
}
