//
// Created by Lev on 3/13/2023.
//

#ifndef POKERPROJ_DECK_H
#define POKERPROJ_DECK_H
#include <iostream>
#include "DurakCard.h"


class DurakDeck {
private:
    std::vector<DurakCard> deck;// this is your final deck of cards
    const int DECK_SIZE = 36;// this is the size of your deck
public:
    std::vector<DurakCard> getCards();
    bool empty(); //returns true if deck has no cards
    void shuffle(); // puts cards in random order
    DurakCard dealCard(); // returns the next card in the deck
    DurakCard getCardAt(int index);// gets the DurakCard at the given index
    DurakDeck(); // this is the constructor
};


#endif //POKERPROJ_DECK_H
