//
// Created by zacco on 4/13/2023.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Deck.h"

class Player {
public:
    Player(std::string name, Deck deck, int health);
    std::string getName() const;
    Deck& getDeck();
    int getHealth();
    int setHealth(Player player);
    std::string name;
    Deck deck;
    Deck hand;
    int health = 4;
private:
    int healthValue = 4;
};

#endif
