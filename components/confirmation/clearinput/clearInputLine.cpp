#include <iostream>

void clearInputLine() {
    std::cout << "\033[1A\r\033[2K";
}