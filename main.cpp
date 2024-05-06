#include "player.h"

using namespace std;

void intro(Game& game) {
    Program::clearScreen();
    cout << game.getStory() << endl;
    cout << endl << "Welcome to " << Program::bold() << game.getName() << Program::boldOFF() << endl;
}

void intro(Player& player) {
    cout << "Character: " << Program::bold() << player.getName() << Program::boldOFF() << endl;
    cout << "Emoji: " << player.getEmoji() << endl;
    cout << "Health: " << player.getHealth() << endl;
    cout << "Speed: " << player.getSpeed() << endl;
    cout << "Strength: " << player.getStrength() << endl;
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
