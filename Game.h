//
// Created by Lev on 4/20/2023.
//

#ifndef SFML_PROJECT_GAME_H
#define SFML_PROJECT_GAME_H

#include "DurakCard.h"
#include "DurakDeck.h"
#include "Player.h"
#include "DurakPosition.h"
#include "LoadingScreen.h"
#include <SFML/Graphics.hpp>
#include<stdio.h>
#include<stdlib.h>

// need to make 2 player at first..... multiplayer too complex.
// create a render texture that covers cards that arent able to be played during combat
// highlight playable cards
//display which turn it is, etc

class Game {
private:
    bool endGame = false;
    int winPlayer;
    int attackingPlayer;
    int defendingPlayer;
    Player p1;
    Player p2;
    DurakDeck deck;
    DurakSuits trump;
    std::vector<DurakCard> attackingCards;
    bool combatLost;
public:
    Player& getCurrentPlayer();
    Player& getDefendingPlayer();
    Game();
    static void drawBoard(sf::RenderWindow& window, DurakDeck deck, DurakSuits trump);
    static void drawBoard(sf::RenderWindow& window);
    void playGame();
    void performTurn(sf::RenderWindow& window);
    bool wait_for_card_click(sf::RenderWindow& window, Player& player, int& clicked_card_index);
    void updateTurn();
    void animate_card_movement(DurakCard& card, const sf::Vector2f& target_position, sf::RenderWindow& window, sf::Clock& clock);
};


#endif //SFML_PROJECT_GAME_H
