//
// Created by Lev on 4/24/2023.
//

#ifndef SFML_PROJECT_PLAYER_H
#define SFML_PROJECT_PLAYER_H
#include "DurakCard.h"
#include "DurakDeck.h"

class Player {
private:
    std::vector<DurakCard> hand;
public:
    void removeCard(int index);
    static bool canDefend(DurakCard attackCard, DurakCard defCard, DurakSuits trump);
    Player();
    DurakCard chooseAttack();
    void takeCard(const DurakCard& card);
    void drawHand(DurakDeck& deck);
    std::vector<DurakCard>& get_hand();
    std::vector<int> playableCards(DurakCard attackingCard, DurakSuits trump);
    static bool canDefend(DurakCard attackCard, DurakCard defCard);
    void defense(const std::vector<DurakCard>& attackingCards , DurakSuits trump);
    static bool combat(DurakCard attackingCard, DurakCard defendingCard, DurakSuits trump);
    bool hand_is_empty() const {
        return hand.empty();
    }
};


#endif //SFML_PROJECT_PLAYER_H
