#include "game.h"

using namespace std;

Game::Game() {
    
}

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

bool Game::getCleared() {
    return cleared;
}

void Game::setName(string n) {
    name = n;
}

void Game::setStory(string s) {
    story = s;
}

void Game::setCleared(bool c) {
    cleared = c;
}

void Game::customize(bool c) {
    string input;
    if (c) {
        cout << "What would you like to call the game?" << endl;
        getline(cin, input);
        name = input;
        cout << "Please enter the prologue of the game" << endl;
        getline(cin, input);
        story = input;
    } else {
        fstream file("story.txt", ios::in);
        string storyline;
        string line;
        while(getline(file, line)) {
            storyline += line + "\n";
        }
        name = "Shawarma Land";
        story = storyline;
    }
}
