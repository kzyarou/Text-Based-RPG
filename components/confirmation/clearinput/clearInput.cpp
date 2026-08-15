#include <iostream>
#include <limits>

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "\033[1A\r\033[2K";
}