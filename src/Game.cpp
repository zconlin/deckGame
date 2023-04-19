//
// Created by zacco on 4/13/2023.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <unistd.h>  // For sleep()
#include "Game.h"

using namespace std;

Game::Game(Player player1, Player player2) : player1(player1), player2(player2) {
}

// Function to generate a random number
int Game::randomNumber() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 100);

    int num = dis(gen);

    if (num <= 5) {
        return 10;
    } else {
        return std::max(1, (int)(10 - sqrt(num)));
    }
}

void Game::initializeDeck(Player player) {
    // Initialize deck with random cards for the Player
    Player initPlayer = player;
    int deckSize = initPlayer.deck.getDeckSize();
    for (int i = 0; i < deckSize; ++i) {
        int attack = randomNumber();
        int defense = randomNumber();
        player1.deck.addCard(Card(attack, defense));
    }

    //TODO Hardcode opponents rather than randomize
    for (int i = 0; i < deckSize; ++i) {
        int attack = randomNumber();
        int defense = randomNumber();
        player2.deck.addCard(Card(attack, defense));
    }
}

void Game::battle() {
    // Main game loop
    while (player1.health > 0 && player2.health > 0) {
        ++round;
        lineBreak();
        cout << "Round " << round << ":" << endl;

        cout << player1.getName() << "'s health: " << player1.health << "                "
            << "Player 2's health: " << player2.health << endl;

        Card player1Card = hand(player1Card);
//        drawCard(round);

        Card player2Card = player2.deck.getCard(rand() % player2.deck.getSize());

        cout << player1.getName() << "'s card: " << player1Card.attack << "/" << player1Card.defense;
        sleep(1);
        cout << "                 " << "Player 2's card: " << player2Card.attack << "/" << player2Card.defense << endl;
        sleep(2);

        int player1Attack = player1Card.attack;
        int player2Defense = player2Card.defense;

        // Player 1's card defends against Player 2's card
        if (player2Card.attack > player1Card.defense) {
            int damage = player2Card.attack - player1Card.defense;
            cout << player1.getName() << " took " << player2Card.attack - player1Card.defense << " damage.";
            player1.health -= damage;
        } else {
            cout << player1.getName() << " took 0 damage.";
        }
        cout << "              ";

        // Player 2's card defends against Player 1's card
        if (player1Attack > player2Defense) {
            int damage = player1Attack - player2Defense;
            cout << "Player 2 took " << player1Card.attack - player2Card.defense << " damage." << endl;
            player2.health -= damage;
        } else {
            cout << "Player 2 took 0 damage." << endl;
        }

        sleep(2);
        cout << player1.getName() << "'s health: " << player1.health << "                ";
        cout << "Player 2's health: " << player2.health << endl;
        lineBreak();
        cout << "Press c to continue:";
        cin >> input;
        cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
    }
}

// Function to draw a card from the deck and add it to the hand
Card Game::hand(Card card) {
    // Sets the first four cards in the deck into the hand
    if (player1.deck.getSize() == 0) {
        cout << "You have no cards left in your deck. You lose." << endl;
        endGame();
    }
    int i = player1.hand.getSize();
    while (player1.hand.getSize() < 4 && player1.deck.getSize() != i) {
        int drawCardIndex = rand() % player1.deck.getSize();
        Card drawCard = player1.deck.getCard(drawCardIndex);
        player1.hand.addCard(drawCard);
        player1.deck.removeCard(drawCardIndex);
        drawnCards++; //Todo: doesn't do anything at this point
    }
//    cout << endl << player1.getName() << "'s hand: " << endl;
    player1.hand.showHand();

    Card chosenCard = playCard();

    return chosenCard;
}

Card Game::playCard() {
    Card playCard = Card(100, 100);

    cout << "Choose a card to play, or press d to view your deck:" << endl;

    while (input != '1' || input != '2' || input != '3' || input != '4') {
        cin >> input;
        if (input == '1' || input == '2' || input == '3' || input == '4') {
            break;
        }
        else if (input == 'd') { // debug
            player1.deck.printDeck();
            lineBreak();
            cout << "Choose a card to play:" << endl;
            player1.hand.showHand();
        }
        else {
            cout << "Invalid input. Please try again." << endl;
           // show hand again

        }
    }
    if (input == '1') {
        playCard = player1.hand.getCard(0);
        player1.hand.removeCard(0);
    } else if (input == '2') {
        playCard = player1.hand.getCard(1);
        player1.hand.removeCard(1);
    } else if (input == '3') {
        playCard = player1.hand.getCard(2);
        player1.hand.removeCard(2);
    } else if (input == '4') {
        playCard = player1.hand.getCard(3);
        player1.hand.removeCard(3);
    }
    else {
        cout << "Invalid input. Please try again." << endl;
        hand(playCard);
    }
    lineBreak();
    //    cout << endl << "You played: " << playCard.attack << "/" << playCard.defense << endl;
    return playCard;
}

void Game::play() {
    if (firstTime == true) {
        cout << "Welcome to the game!" << endl;
        cout << "Please enter your name:";
        cin >> player1.name;
        initializeDeck(player1);
        firstTime = false;

        cout << "Welcome, " << player1.getName() << "!" << endl << endl;
        cout << "You will be playing against the computer." << endl;
        cout << "Would you like to view your deck? (y/n)";
        cin >> input;
        if (input == 'y') {
            player1.deck.printDeck();
            cout << endl << "Press c to start.";
            cin >> input;
        }
    }
    backupDeck = player1.deck;
    Deck shuffledDeck = player1.deck.shuffleDeck(player1.deck);
    player1.deck = shuffledDeck;

    // while loop that prompts user to shuffle deck if they don't like the order, then print the shuffled deck, c to continue
    cin >> input;// debug start
    while (input != 'c') {
        cout << "Would you like to shuffle your deck? (y/n)";
        cin >> input;
        if (input == 'y') {
            shuffledDeck = player1.deck.shuffleDeck(player1.deck);
            player1.deck = shuffledDeck;
            cout << "Your deck has been shuffled." << endl;
        }
        player1.deck.printDeck();
        cin >> input;
    } // debug end

    while (player1.health > 0 && player2.health > 0) {
        battle();
    }

    endGame();
}

void Game::lineBreak() {
    cout << "_________________________________________________________________________________" << endl;
}

Card Game::takeCard() {
// Player 1 gets a random card from Player 2's deck
    int randomIndex = rand() % player2.deck.getSize();
    Card newCard = player2.deck.getCard(randomIndex);
//    player1.deck.addCard(newCard);
    backupDeck.addCard(newCard);
    cout << "Player 1 gets a new card: " << newCard.attack << "/" << newCard.defense << endl;
    return newCard;
}

void Game::endGame() {
    if (player1.health <= 0 && player2.health <= 0) {
        if (player1.health > player2.health) {
            cout << player1.getName() << " wins!" << endl;
            takeCard();
        }
        if (player2.health == player1.health) {
            cout << "Tie game! ...but in life there are no ties so you lose" << endl;
        } else {
            cout << "Player 2 wins!" << endl;
        }
    }
    else if (player1.health <= 0 && player2.health > 0) {
            cout << "Player 2 wins!" << endl;
    }
    else if (player1.health > 0 && player2.health <= 0) {
        cout << player1.getName() << " wins!" << endl;
        takeCard();
    }
    else {
        cout << "Error: endGame() called when no player has 0 health." << endl;
    }

    while (input != 'y' || input != 'n') {
        cout << "Play again? y/n.";
        cin >> input;

        if (input == 'y') {
            round = 0;
            player1.health = player1.setHealth(player1);
            player2.health = player2.setHealth(player2);
            player1.deck = backupDeck;
            cout << player1.deck.getSize() << endl;
            play();
        }
        else if (input == 'n') {
            cout << "Are you sure? You will lose your current progress. y/n." << endl;
            cin >> input;
            if (input == 'y') {
                break;
            }
            else if (input == 'n') {
                continue;
            }
            break;
        }
    }
}

