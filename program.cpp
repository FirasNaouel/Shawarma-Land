#include "program.h"
using namespace std;

bool Program::question(string q, char y, char n) {
    char input;
    do {
        cout << q;
        cin >> input;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        input = tolower(input);
        if (input != y && input != n) {
            cout << "Invalid input. Please enter '" << y << "' for Yes or '" << n << "' for No." << endl;
            cout << "Input: ";
        }
    } while (input != y && input != n);
    return (input == y);
}

int Program::question(int l, int h) {
    int input;
    do {
        cout << "Enter action: ";
        while (!(cin >> input)) {
            cout << "Invalid Input! (only integer)" << endl;
            cout << "Enter action: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (input < l || input > h) {
            if (l == h) {
                cout << "Invalid Integer! (only " << l << ")" << endl;
            } else {
                cout << "Invalid Integer! (between " << l << " and " << h << ")" << endl;
            }
        }
    } while (input < l || input > h);
    return input;
}

string Program::white() {
    return "\033[1;37m";
}

string Program::cyan() {
    return "\033[1;36m";
}

string Program::yellow() {
    return "\033[1;33m";
}

string Program::green() {
    return "\033[1;32m";
}

string Program::red() {
    return "\033[1;31m";
}

string Program::colourOFF() {
    return "\u001B[0m";
}

void Program::clearScreen() {
    system("clear");
}

void Program::enterContinue() {
    cout << endl << "Press Enter to Continue";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    clearScreen();
}

void alpha(string items[], int length, int start, int mid, int end) {
    string temp[length];
    int pos1 = start;
    int pos2 = mid + 1;
    int spot = start;
    while (!(pos1 > mid && pos2 > end)) {
        if ((pos1 > mid) || ((pos2 <= end) && (items[pos2] < items[pos1]))) {
            temp[spot] = items[pos2];
            pos2 += 1;
        } else {
            temp[spot] = items[pos1];
            pos1 += 1;
        }
        spot += 1;
    }

/* copy values from temp back to items */
    for (int i = start; i <= end; i++) {
        items[i] = temp[i];
    }
}


void alphaSort(string items[], int start, int end, int length) {
    if (start < end) {
        int mid = (start + end) / 2;
        alphaSort(items, start, mid, length);
        alphaSort(items, mid + 1, end, length);
        alpha(items, length, start, mid, end);
    }
}
