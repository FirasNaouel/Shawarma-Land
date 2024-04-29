#include "program.h"
using namespace std;

void intro(Game& game, Program& backend) {
    system("clear");
    cout << game.getStory() << endl;
    cout << "Welcome to " << backend.boldON() << game.getName() << backend.boldOFF() << endl;
}

int main() {
    Program backend;
    Game game;
    game.customize(backend.yesNo("Would you like to customize the game? (y/n)", '-', 'y', 'n'));
    intro(game, backend);
}
