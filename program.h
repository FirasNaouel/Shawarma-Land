#include "game.h"
#pragma once
using namespace std;

class Program {
    public:
    static bool question(string, char, char);
    static int question(int, int);
    static string bold();
    static string boldOFF();
    static void clearScreen();
    static void enterContinue();
};
