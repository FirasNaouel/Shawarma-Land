#include "game.h"

using namespace std;

Game::Game(string n, string s) {
    name = n;
    story = s;
}

string Game::getName() {
    return name;
}

string Game::getStory() {
    return story;
}