#include "game.h"

using namespace std;

string storyline() {
    fstream file("list.txt", ios::in);
    string story;
    string line;
    while(getline(file, line)) {
        story += line + "\n";
    }
    return story;
}

int main() {
    Game game("Shawarma Land", storyline());
    cout << game.getStory();
    cout << endl;
    cout << game.getName();
}
