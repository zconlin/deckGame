//
// Created by zacco on 4/13/2023.
//

#include <random>
#include "Card.h"

Card::Card(int attack, int defense) {
    this->attack = attack;
    this->defense = defense;
}

int Card::getAttack() {
    return attack;
}

int Card::getDefense() {
    return defense;
}