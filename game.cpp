#include "game.h"

using namespace std;

Game::Game() {
    fstream file("story.txt", ios::in);
    stringstream buffer;
    buffer << file.rdbuf();
    file.close();

    name = "Shawarma Land";
    story = buffer.str();
}

string Game::getName() {
    return name;
}

string Game::getStory() {
    return story;
}

bool Game::getCleared() {
    return cleared;
}

void Game::setCleared(bool c) {
    cleared = c;
}
