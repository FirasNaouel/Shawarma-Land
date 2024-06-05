#include <iostream>
#pragma once

using namespace std;

class Room {
private:
    struct Position {
        int x, y;
    };
    Position player;
    Position item;
    static const int SIZE = 10;
    char grid[SIZE][SIZE] = {{'|', '|', '|', '|', '|', '|', '|', '|', '|', '|'},
                           {'|', '|', '|', '|', '|', '|', '|', '|', '|', '|'},
                           {'|', '|', '|', '|', '|', '|', '|', '|', '|', '|'},
                           {'|', '|', '|', '|', '|', '|', '|', '|', '|', '|'},
                           {'|', '|', '|', '|', '|', '|', '|', '|', '|', '|'},
                           {'|', '|', '|', '|', '|', '|', '|', '|', '|', '|'},
                           {'|', '|', '|', '|', '|', '|', '|', '|', '|', '|'},
                           {'|', '|', '|', '|', '|', '|', '|', '|', '|', '|'},
                           {'|', '|', '|', '|', '|', '|', '|', '|', '|', '|'},
                           {'|', '|', '|', '|', '|', '|', '|', '|', '|', '|'}};


public:
    Room();

    void printGrid() const;

    int findDistance() const;

    void makeMove();

    bool checkWin() const;

    static string hotCold(int, int);
};
