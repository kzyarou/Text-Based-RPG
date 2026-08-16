#include <iostream>
#include "classSelectScreen.hpp"
#include "../../../audio/loadingsfx/loadingSound.hpp"

void classSelectScreen() {
    loadingTickSound();
    std::cout << "|=================================|\n"
                 "| Choose your path.               |\n"
                 "|                                 |\n"
                 "| 1. Warrior                      |\n"
                 "| 2. Huntsman                     |\n"
                 "| 3. Sorcerer                     |\n"
                 "| 4. Paladin                      |\n"
                 "| 5. Priest                       |\n"
                 "|=================================|\n\n";
}
