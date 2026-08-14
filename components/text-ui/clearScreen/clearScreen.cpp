#include "clearScreen.hpp"
#include <iostream>
#include <string>
#include <chrono>
#include <thread>

// uses `cls` if using win, else `clear` for linux
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}