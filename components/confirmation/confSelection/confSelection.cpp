#include <iostream>
#include <string>
#include "../clearinput/clearInput.hpp"

bool confSelection() {
    std::cout << "|=======================================================|\n"
                 "| Are you sure this is the path you want to take? [Y/N] |\n"
                 "|=======================================================|\n\n";

    std::string decision{};

    while (true) {
        std::cout << '>';
        std::getline(std::cin, decision);

        if (decision == "Y" || decision == "y") {
            return true;
        }

        if (decision == "N" || decision == "n") {
            return false;
        }

        clearInputLine();
    }
}