//
// Created by zacco on 4/13/2023.
//

#include "Player.h"

Player::Player(std::string name, Deck deck, int health) : name(name), deck(deck), health(health) {}

std::string Player::getName() const {
    return name;
}

Deck& Player::getDeck() {
    return deck;
}

int Player::getHealth() {
    health = 20;
    return health;
}

int Player::setHealth(Player player) {
    health = 20;
    return health;
}
