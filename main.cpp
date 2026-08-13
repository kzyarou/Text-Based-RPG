#include <iostream>

struct Classes {
    double health;
    double stamina;
    double damage;
    double range;
    std::string description;
};

void characterVerification(char& proceed);
void checkCharacter(std::string& character, char& proceed, bool& hasCharacter, std::string& usedCharacter);
void printStats(const Classes& character);

using text = std::string;

int main () {

    int role = {};
    text character;
    char proceed;
    bool hasCharacter = false;
    std::string usedCharacter;
    
    Classes warrior;
    Classes archer;
    Classes sorcerer;
    Classes tanker;
    Classes warden;

    

    std::cout << " ______________________________________\n";
    std::cout << "|                                      |\n";
    std::cout << "|  Welcome to AnimA, A text based RPG  |\n";
    std::cout << "|______________________________________|\n";

    do {
    // Class selection
    std::cout << "\nPlease choose a class.\n";
    std::cout << "1. Warrior\n";
    std::cout << "2. Archer\n";
    std::cout << "3. Sorcerer\n";
    std::cout << "4. Tanker\n";
    std::cout << "5. Warden\n";
    std::cin >> role;

    switch (role) {
        case 1:
            character = "warrior";
            warrior.health = 110;
            warrior.stamina = 50;
            warrior.damage = 10;
            warrior.range = 5;
            warrior.description = "The Warrior:\nA fierce mortal ready to hack and slash its way to glory.\n";
            printStats(warrior);
            
            characterVerification(proceed);
            break;
        case 2:
            character = "archer";
            archer.health = 110;
            archer.stamina = 50;
            archer.damage = 10;
            archer.range = 5;
            archer.description = "The Archer:\nA long range combatant able to penetrate even the thickest of defense.\n";
            printStats(archer);
            
            characterVerification(proceed);
            break;
        case 3:
            character = "sorcerer";
            sorcerer.health = 110;
            sorcerer.stamina = 50;
            sorcerer.damage = 10;
            sorcerer.range = 5;
            sorcerer.description = "The Sorcerer:\nA powerful magical being capable of controlling matter.\n";
            printStats(sorcerer);
            
            characterVerification(proceed);
            break;
        case 4:
            character = "tanker";
            tanker.health = 110;
            tanker.stamina = 50;
            tanker.damage = 10;
            tanker.range = 5;
            tanker.description = "The Tanker:\nHeavy weight capable of absorbing any damage that comes in its way.\n";
            printStats(tanker);
            
            characterVerification(proceed);
            break;
        case 5:
            character = "warden";
            warden.health = 110;
            warden.stamina = 50;
            warden.damage = 10;
            warden.range = 5;
            warden.description = "The Warden:\nAn ancient mystique capable of healing its allies and debuffing its enemies.\n";
            printStats(warrior);
            
            characterVerification(proceed);
            break;
        default:
            std::cout << "Please enter only 1-5!\n";
            break;
    }

    if (proceed == 'Y') {
    std::cout << "You are now a " << character << '\n';
    hasCharacter = true;
    }
    
    
    }while(hasCharacter == false);

}

void checkCharacter (std::string& character, char& proceed, bool& hasCharacter, std::string& usedCharacter) {
    if (proceed == 'Y' || proceed == 'y') {
        character = usedCharacter;
        hasCharacter = true;
    } else if (proceed == 'N' || proceed == 'n') {
        // Do nothing
    } else {
        std::cout << "Please enter only Y/N\n";
    }
}
void printStats (const Classes & character) {
    std::cout << character.description;
    std::cout << "Health: " << character.health << '\n';
    std::cout << "Stamina: " << character.stamina << '\n'; 
    std::cout << "Damage: " << character.damage << '\n';
    std::cout << "Range: " << character.range << '\n'; 
}

void characterVerification (char& proceed){
    char proceedChoice;
    std::cout << "Do you want to proceed?";
    std::cin >> proceedChoice;
    
    if (proceedChoice == 'Y' || proceedChoice == 'y') {
        proceed = 'Y';
    } else if (proceed == 'N' || proceed == 'n') {
        // Do nothing
    } else {
        std::cout << "Please enter a valid character (Y/N)";
    }
}