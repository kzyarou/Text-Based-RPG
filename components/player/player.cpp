#include "player.hpp"

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