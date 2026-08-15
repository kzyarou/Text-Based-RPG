#include <iostream>

bool confSelection() {
    std::cout << "|=======================================================|\n"
                 "| Are you sure this is the path you want to take? [Y/N] |\n"
                 "|=======================================================|\n\n";

    char decision{};

    while (true) {
        std::cout << '>';
        std::cin >> decision;

        if (decision == 'N' || decision == 'n') {
            return false;
        }
        else if (decision == 'Y' || decision == 'y') {
            return true;
        }

        std::cout << "|=======================================|\n"
                     "| I worry for you... (Try again. [Y/N]) |\n"
                     "|=======================================|\n";
    }
}
