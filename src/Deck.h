//
// Created by zacco on 4/13/2023.
//

#ifndef DECK_H
#define DECK_H

#include <vector>
#include <iostream>
#include <string>
#include "Card.h"

using namespace std;

class Deck {

public:
    void addCard(Card card);
    void removeCard(int index);
    Card getCard(int index);
    string printDeck();
    string showHand();
    int getSize();

    vector<Card> cards;

    int getDeckSize();
};

#endif
