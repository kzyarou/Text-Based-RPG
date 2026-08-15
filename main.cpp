#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "components/text-ui/clearScreen/clearScreen.hpp"
#include "components/text-ui/titleScreen/titleScreen.hpp"
#include "components/text-ui/classSelectScreen/classSelectScreen.hpp"
#include "components/text-ui/classSelect/classSelect.hpp"
#include "components/text-ui/displayClass/displayClass.hpp"
#include "components/confirmation/confSelection/confSelection.hpp"
#include "components/player/player.hpp"
#include "components/player/getPlayerName/getPlayerName.hpp"

void titleScreen();
void classSelectScreen();
void classSelect(PlayerInfo& pInfo);
void displayClass(const PlayerInfo& pInfo);
bool confSelection();
void getPlayerName(PlayerInfo& pInfo);

int main() {
    PlayerInfo pInfo;

    titleScreen();

    std::this_thread::sleep_for(std::chrono::milliseconds(2000)); // pause for 2 seconds.

    bool selection = true;
    while (selection) {
        clearScreen(); // clear the screen.

        classSelectScreen();
        classSelect(pInfo);

        clearScreen();
        displayClass(pInfo);
        if (confSelection()) {
            selection = false;
        }
    }

    clearScreen();
    getPlayerName(pInfo);

    std::cout << "Press enter to exit...";
    std::cin.get();

    return 0;
}