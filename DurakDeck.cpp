//
// Created by Lev on 3/13/2023.
//

#include "DurakDeck.h"
#include <stdlib.h>
#include <time.h>
#include <map>

bool DurakDeck::empty() {
    return deck.empty();
}

void DurakDeck::shuffle() {
    srand(time(0));
    for(int i = 0; i<36; i++){
        int r = i + (rand() % (36 -i));
        DurakCard temp;
        temp = deck[i];
        deck[i] = deck[r];
        deck[r] = temp;
    }

}

DurakCard DurakDeck::dealCard() {
    DurakCard dealt_card = deck.back();
    deck.pop_back();
    return dealt_card;
}

DurakCard DurakDeck::getCardAt(int index) {
    return deck[index];
}


DurakDeck::DurakDeck() {
    int index = 0;
    std::map<int, DurakSuits> const suitsMap {{1, HEARTS}, {2, SPADES}, {3, CLUBS}, {4, DIAMONDS}};
    std::map<int, DurakRanks> const ranksMap {{1,  ACE}, {6, SIX}, {7, SEVEN},
                                              {8,  EIGHT}, {9, NINE}, {10, TEN},
                                              {11, JACK}, {12, QUEEN}, {13, KING}};
    for(auto i : suitsMap){
        for(auto j : ranksMap){
            deck.emplace_back(j.second, i.second);
            index++;
        }
    }
}

std::vector<DurakCard> DurakDeck::getCards() {
    return deck;
}
