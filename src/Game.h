//
// Created by zacco on 4/13/2023.
//

#ifndef GAME_H
#define GAME_H

#include "Player.h"

class Game {
private:
    Player player1;
    Player player2;

public:
    Game();
    Game(Player player1, Player player2);

    int round = 0;
    int i = 0;
    char input;
    bool firstTime = true;
    int drawnCards = 0;

    int randomNumber();
    void battle();
    Card hand(Card card);
    Card chosenCard();
    void initializeDeck(Player player);
    void play();
    static void lineBreak();

    void endGame();

    Card playCard();

    Card takeCard();

};

#endif

