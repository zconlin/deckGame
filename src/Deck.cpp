//
// Created by zacco on 4/13/2023.
//

#include "Deck.h"
#include "Game.h"
#include "Player.h"

void Deck::addCard(Card card) {
    cards.push_back(card);
}

void Deck::removeCard(int index) {
    cards.erase(cards.begin() + index);
}

Card Deck::getCard(int index) {
    return cards[index];
}

string Deck::printDeck() { // Currently just a void with couts, change to return output
    string output = "";
    Game::lineBreak();
    for (int i = 0; i < cards.size(); i++) {
        cout << "Card " << i + 1 << ": " << cards[i].getAttack() << "/" << cards[i].getDefense() << endl;
    }
    Game::lineBreak();
    return output;
}

string Deck::showHand() {
    string output = "";
    Game::lineBreak();
//    cout << endl << player1.getName() << "'s hand: " << endl; // How do I make this work?

    cout << endl << "Your hand: " << endl;
    for (int i = 0; i < cards.size(); i++) {
        cout << "[" << i + 1 << "] " << cards[i].getAttack() << "/" << cards[i].getDefense() << endl;
    }
    Game::lineBreak();
    return output;
}

Deck Deck::shuffleDeck (Deck deck) {
    Deck shuffledDeck;
    int deckSize = deck.getDeckSize();
    for (int i = 0; i < deckSize; i++) {
        int drawCardIndex = rand() % deck.getSize();
        Card drawCard = deck.getCard(drawCardIndex);
        shuffledDeck.addCard(drawCard);
        deck.removeCard(drawCardIndex);
    }
    return shuffledDeck;
}

int Deck::getDeckSize() {
    int deckSize = 20;
    return deckSize;
}

int Deck::getSize() {
    return cards.size();
}
