#include <iostream>
#include <string>
#include <chrono>
#include <thread>

struct PlayerInfo {
    std::string playerName = "Player";
    std::string playerClass{};
    std::string classDesc{};
    double health{};
    double stamina{};
    double damage{};
    double critRate{};
    double critDmg{};
};
void clearScreen();
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

const PlayerInfo classes[] = {
    {
        .playerClass = "Warrior",
        .classDesc = "A fierce mortal ready to hack and slash its way to glory.",
        .health = 110,
        .stamina = 60,
        .damage = 10,
        .critRate = 8.0 / 100,
        .critDmg = 10.0 / 100
    },
    {
        .playerClass = "Huntsman",
        .classDesc = "A skilled marksman able to penetrate even the thickest of defense.",
        .health = 90,
        .stamina = 60,
        .damage = 11,
        .critRate = 15.0 / 100,
        .critDmg = 7.5 / 100
    },
    {
        .playerClass = "Sorcerer",
        .classDesc = "A being of great magical affinity, capable of controlling elements",
        .health = 75,
        .stamina = 100,
        .damage = 15,
        .critRate = 4.0 / 100,
        .critDmg = 6.0 / 100
    },
    {
        .playerClass = "Paladin",
        .classDesc = "A sturdy and headstrong individual that can endure any danger coming their way.",
        .health = 150,
        .stamina = 60,
        .damage = 8,
        .critRate = 3.0 / 100,
        .critDmg = 5.0 / 100
    },
    {
        .playerClass = "Priest",
        .classDesc = "Wields a holy power that is capable of healing their allies and vanquish evil.",
        .health = 85,
        .stamina = 80,
        .damage = 6,
        .critRate = 10.0 / 100,
        .critDmg = 3.0 / 100
    }
};

void titleScreen() {
    std::cout << "|=================================|\n"
                 "|        Where Ravens Weep        |\n"
                 "|        A text-based RPG         |\n"
                 "|=================================|\n\n";
}

void classSelectScreen() {
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

void classSelect(PlayerInfo& pInfo) {
    int choice{};

    bool choosing = true;

    while (choosing) {
        std::cout << '>';
        std::cin >> choice;

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

void displayClass(const PlayerInfo& pInfo) {
    std::cout << pInfo.playerClass << '\n';
    std::cout << "- " << pInfo.classDesc << "\n\n";

    std::cout << "Health: " << pInfo.health << '\n';
    std::cout << "Stamina: " << pInfo.stamina << '\n';
    std::cout << "Damage: " << pInfo.damage << '\n';
    std::cout << "Crit Rate: " << pInfo.critRate * 100.0 << "%\n";
    std::cout << "Crit Damage: " << pInfo.critDmg * 100.0 << "%\n\n";
}

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

void getPlayerName(PlayerInfo& pInfo) {
    std::cout << "Well then " << pInfo.playerClass
              << ", what is your name?\n\n";

    std::cout << '>';
    std::getline(std::cin >> std::ws, pInfo.playerName);

    clearScreen();

    std::cout << "Welcome, " << pInfo.playerName << "!!!\n\n";
}

// uses `cls` if using win, else `clear` for linux
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}