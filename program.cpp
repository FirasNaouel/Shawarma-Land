#include "program.h"

using namespace std;

Program::Program() {
    
}

bool Program::yesNo(string q, char c, char y, char n) {
    cout << q << endl;
    cin >> c;
    while (c != y && c != n) {
        cout << q << endl;
        cin >> c;
    }
    cin.ignore();
    if (c == y) {
        return true;
    }
    return false;
}

string Program::boldON() {
    return "\e[1m";
}

string Program::boldOFF() {
    return "\e[0m";
}
