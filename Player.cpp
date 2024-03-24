//
// Created by Lev on 4/24/2023.
//

#include "Player.h"

void Player::drawHand(DurakDeck &deck) {
    if(deck.empty()){
        return;
    }
    while(hand.size() < 6){
        hand.push_back(deck.dealCard());
    }
}

std::vector<int> Player::playableCards(DurakCard attackingCard, DurakSuits trump) {
    std::vector<int> out;
    for(int i = 0; i < hand.size(); i++){
        if(attackingCard.getSuit() == hand[i].getSuit() && attackingCard.getValue() < hand[i].getValue()){
            out.push_back(1);
        }
        else if(attackingCard.getSuit() != trump && hand[i].getSuit() == trump){
            out.push_back(1);
        }
        else if(attackingCard.getSuit() == trump && hand[i].getSuit() == trump && attackingCard.getValue() < hand[i].getValue()){
            out.push_back(1);
        }
        else{
            out.push_back(0);
        }
    }
}

void Player::defense(const std::vector<DurakCard>& attackingCards, DurakSuits trump) {
    bool loss;
    for(const auto& i : attackingCards){
        for(auto j : playableCards(i, trump)){
            if(j == 1){
                loss = false;
            }
        }
        if(loss){
            break;
        }
    }
    if(loss){
        hand.insert(hand.end(), attackingCards.begin(), attackingCards.end());
    }
    else{
        //select cards to play - SFML
    }
}
DurakCard Player::chooseAttack() {
    //player chooses card
    return DurakCard();
}

std::vector<DurakCard> &Player::get_hand(){
    return hand;
}

bool Player::canDefend(DurakCard attackCard, DurakCard defCard, DurakSuits trump) {
    if(attackCard.getSuit() == defCard.getSuit() && attackCard.getValue() < defCard.getValue()){
        return true;
    }
    else if(attackCard.getSuit() != trump && defCard.getSuit() == trump){
        return true;
    }
    else if(attackCard.getSuit() == trump && defCard.getSuit() == trump && attackCard.getValue() < defCard.getValue()){
        return true;
    }
    else{
        return false;
    }
}

void Player::removeCard(int index) {
    hand.erase(hand.begin()+index);
}

void Player::takeCard(const DurakCard& card) {
    hand.push_back(card);
}

bool Player::canDefend(DurakCard attackCard, DurakCard defCard) {
    if(attackCard.getSuit() == defCard.getSuit() && attackCard.getValue() <= defCard.getValue()){
        return true;
    }
    return false;
}

bool Player::combat(DurakCard attackingCard, DurakCard defendingCard, DurakSuits trump) {
    if(attackingCard.getSuit() == defendingCard.getSuit()){
        return (defendingCard.getValue() > attackingCard.getValue());
    }
    else if(defendingCard.getSuit() == trump){
        if(attackingCard.getSuit() != trump){
            return true;
        }
        else{
            return (defendingCard.getValue() > attackingCard.getValue());
        }
    }
    return false;
}

Player::Player() = default;
