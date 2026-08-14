#include <iostream>
#include "getPlayerName.hpp"
#include "../../text-ui/clearScreen/clearScreen.hpp"

void getPlayerName(PlayerInfo& pInfo) {
    std::cout << "Well then " << pInfo.playerClass
              << ", what is your name?\n\n";

    std::cout << '>';
    std::getline(std::cin >> std::ws, pInfo.playerName);

    clearScreen();

    std::cout << "Welcome, " << pInfo.playerName << "!!!\n\n";
}