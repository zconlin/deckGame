//
// Created by zacco on 4/13/2023.
//

#ifndef CARD_H
#define CARD_H

class Card {
public:
    int attack;
    int defense;

    Card(int attack, int defense);
    int getAttack();
    int getDefense();
};

#endif
