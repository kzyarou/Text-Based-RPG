#include <iostream>
#include "../../player/player.hpp"

void displayClass(const PlayerInfo& pInfo) {
    std::cout << pInfo.playerClass << '\n';
    std::cout << "- " << pInfo.classDesc << "\n\n";

    std::cout << "Health: " << pInfo.health << '\n';
    std::cout << "Stamina: " << pInfo.stamina << '\n';
    std::cout << "Damage: " << pInfo.damage << '\n';
    std::cout << "Crit Rate: " << pInfo.critRate * 100.0 << "%\n";
    std::cout << "Crit Damage: " << pInfo.critDmg * 100.0 << "%\n\n";
}