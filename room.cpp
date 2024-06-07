#include "room.h"
#include <termios.h>
#define STDIN_FILENO 0


Room::Room() {
    srand(time(nullptr));

    // Set player's starting position
    player.x = rand() % SIZE;
    player.y = rand() % SIZE;

    // Set item's position
    item.x = rand() % SIZE;
    item.y = rand() % SIZE;
}

void Room::printGrid() const{
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (i == player.y && j == player.x)
                cout << 'X';
            else
                cout << grid[i][j];
            cout << " ";
        }
        cout << endl;
    }
}

int Room::findDistance() const{
    int distance = abs(player.x - item.x) + abs(player.y - item.y);
    return distance;
}

void Room::makeMove(int i) {
    

    if(i == 0){

        // Black magic to prevent Linux from buffering keystrokes. Also insta key registration without need to click enter
        struct termios t;
        tcgetattr(STDIN_FILENO, &t);
        t.c_lflag &= ~ICANON;
        tcsetattr(STDIN_FILENO, TCSANOW, &t);

        
        char move;
        cout << "Enter your move (W for up, A for left, S for down, D for right): ";
        cin >> move;
        // Update player's position
        switch (move) {
            case 'W':
            case 'w':
              if (player.y > 0)
                  player.y--;
            break;
            case 'A':
            case 'a':
              if (player.x > 0)
                  player.x--;
            break;
            case 'S':
            case 's':
              if (player.y < SIZE - 1)
                  player.y++;
            break;
            case 'D':
            case 'd':
              if (player.x < SIZE - 1)
                  player.x++;
            break;
            default:
                cout << "Invalid move! Please try again.\n";

        
        }
    }

    else {
        // Black magic to prevent Linux from buffering keystrokes.  Also insta key registration without need to click enter
        struct termios t;
        tcgetattr(STDIN_FILENO, &t);
        t.c_lflag &= ~ICANON;
        tcsetattr(STDIN_FILENO, TCSANOW, &t);

        cout << "Enter your move (use arrow keys): ";
        char c,d,e;
        cin >> c;
        cin >> d;
        cin >> e;
        // Using 3 char type, Cause up down right left consist with 3 character
        if ((c==27)&&(d==91)) {
            if (e==65) { 
                if (player.y > 0)
                    player.y--;
            }
            if (e==66) {
                if (player.y < SIZE - 1)
                      player.y++;
            }
            if (e==67) {
                if (player.x < SIZE - 1)
                      player.x++;
            }
            if (e==68) {
                if (player.x > 0)
                      player.x--;
            }
        }
    }
}

bool Room::checkWin() const {
    // Check if player found the item
    if (player.x == item.x && player.y == item.y) {
        return true;
    }
    return false;
}

string Room::hotCold(const int distance, const int previousDis) {
    if (distance < previousDis){
        return "hotter";
    }
    else{
        return "colder";
    }
}
