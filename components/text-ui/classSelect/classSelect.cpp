#include <iostream>
#include "../../player/player.hpp"
#include "../clearScreen/clearScreen.hpp"
#include "../classSelectScreen/classSelectScreen.hpp"
#include "../../confirmation/clearinput/clearInput.hpp"

void classSelect(PlayerInfo& pInfo) {
    int choice{};

    bool choosing = true;

    while (choosing) {
        std::cout << '>';
        std::cin >> choice;

        clearInput();

        switch (choice) {
            case 1:
                pInfo = classes[0];
                choosing = false;
                break;

            case 2:
                pInfo = classes[1];
                choosing = false;
                break;

            case 3:
                pInfo = classes[2];
                choosing = false;
                break;

            case 4:
                pInfo = classes[3];
                choosing = false;
                break;

            case 5:
                pInfo = classes[4];
                choosing = false;
                break;

            default:
                clearScreen();
                classSelectScreen();

                std::cout << "|====================================================================|\n"
                             "| Being blind would not make your journey easy im afraid. (1-5 only) |\n"
                             "|====================================================================|\n\n";
                break;
        }
    }
}