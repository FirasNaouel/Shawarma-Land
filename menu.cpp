#include "menu.h"

using namespace std;

void Menu::menu() {
    Program::clearScreen();
    cout << Program::white() + "=== " +  Program::colourOFF() + Program::yellow() + "Shawarma Land" + Program::colourOFF() + Program::white() + " ===" +  Program::colourOFF() << endl;
    cout << endl << "1 - " + Program::white() + "Profile" +  Program::colourOFF() << endl;
    cout << endl << "2 - " + Program::white() + "Backpack" +  Program::colourOFF() << endl;
    cout << endl << "3 - " + Program::white() + "Battle" +  Program::colourOFF() << endl;
    cout << endl << "4 - " + Program::white() + "Credits" +  Program::colourOFF() << endl;
    switch (Program::question(1, 4)) {
        case 1:
            profile();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
    }
}

void Menu::profile() {
    Program::clearScreen();
    cout << "Profile here" << endl;
    Program::question(0, 0);
    menu();
}
