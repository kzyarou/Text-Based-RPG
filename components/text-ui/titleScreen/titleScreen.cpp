#include "titleScreen.hpp"
#include "../../loading/loadingScreen.hpp"
#include "../clearScreen/clearScreen.hpp"
#include <iostream>

void titleScreen() {
    clearScreen();
    std::cout << "|=================================|\n"
                 "|        Where Ravens Weep        |\n"
                 "|        A text-based RPG         |\n";
    loadingScreen();
}