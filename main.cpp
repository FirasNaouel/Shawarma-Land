#include "player.h"

using namespace std;

void intro(Game& game) {
    Program::clearScreen();
    cout << game.getStory() << endl;
    cout << endl << "Welcome to " << Program::white() << game.getName() << Program::colourOFF() << endl;
}

void intro(Player& player) {
    player.playerInfo();
}

int main() {
    Game game;
    Player player;
    while(!game.getCleared()) {
        intro(game);
        Program::enterContinue();
        Program::clearScreen();
        player.customize(Program::question("Would you like to customize your character? (y/n)", 'y', 'n'));
        intro(player);
        game.setCleared(true);
    }
}