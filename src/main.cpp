//
// Created by zacco on 4/13/2023.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Game.h"
#include "Card.h"
#include "Deck.h"
#include "Player.h"

using namespace std;

int main() {
    srand(time(NULL));

    Deck playerdeck;

    Deck deck1;
//    deck1.addCard(Card(5, 3));
//    deck1.addCard(Card(2, 6));
//    deck1.addCard(Card(7, 2));
//    deck1.addCard(Card(4, 5));
//    deck1.addCard(Card(3, 4));
//
    Deck deck2;
    deck2.addCard(Card(4, 4));
    deck2.addCard(Card(3, 5));
    deck2.addCard(Card(2, 6));
    deck2.addCard(Card(5, 3));
    deck2.addCard(Card(6, 2));

    Player player1("Player 1", playerdeck, player1.getHealth());
    Player player2("Player 2", deck2, player2.getHealth());

    Game game(player1, player2);
    game.play();

    return 0;
}
