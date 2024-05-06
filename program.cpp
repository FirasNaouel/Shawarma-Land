#include "program.h"

using namespace std;

bool Program::question(string q, char y, char n) {
    char input;
    do {
        cout << q << endl;
        cin >> input;
        input = tolower(input);
        if (input != y && input != n) {
            cout << "Invalid input. Please enter '" << y << "' for Yes or '" << n << "' for No." << endl;
        }
    } while (input != y && input != n);
    return (input == y);
}

int Program::question(int l, int h) {
    int input;
    do {
        cin >> input;
        if (input < l || input > h) {
            cout << "Invalid input. Please enter a digit from " << l << " to " << h << endl;
        }
    } while (input < l || input > h);
    return input;
}

string Program::bold() {
    return "\e[1m";
}

string Program::boldOFF() {
    return "\e[0m";
}

void Program::clearScreen() {
    system("clear");
}

void Program::enterContinue() {
    cout << endl << "Press Enter to Continue";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
