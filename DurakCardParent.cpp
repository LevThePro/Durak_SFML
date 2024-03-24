//
// Created by Lev on 3/22/2023.
//
#include <unordered_map>
#include <iostream>
#include "DurakCardParent.h"

DurakCardParent::DurakCardParent() {
    rank = ACE;
    suit = HEARTS;
}

DurakCardParent::DurakCardParent(DurakRanks rank, DurakSuits suit) : suit(suit), rank(rank) {
}

DurakRanks &DurakCardParent::getRank() {
    return rank;
}

DurakSuits &DurakCardParent::getSuit() {
    return suit;
}

DurakCardParent::DurakCardParent(std::string s, std::string r) {
        for (auto & c: s){ //converts suit string to uppercase, removing case sensitivity
            c = toupper(c);
        }
        for(auto & c: r){ //converts rank string to uppercase, removing case sensitivity
            c = toupper(c);
        }
        static std::unordered_map<std::string, DurakSuits> const suitsTable = {{"SPADES", DurakSuits::SPADES}, {"CLUBS", DurakSuits::CLUBS},
                                                                               {"HEARTS", DurakSuits::HEARTS}, {"DIAMONDS", DurakSuits::DIAMONDS}};
        auto found1 = suitsTable.find(s); // finds the string in the key
        if(found1 != suitsTable.end()){ //if it is found in map
            suit =  found1->second; // dereferences value (suit), while found-> first would dereference key
        }
        else{
            std::cout << "unable to set suit, invalid input" << std::endl;
        }
        static std::unordered_map<std::string, DurakRanks> const ranksTable = {{"ACE",   DurakRanks::ACE}, {"SIX", DurakRanks::SIX},
                                                                               {"SEVEN", DurakRanks::SEVEN}, {"EIGHT", DurakRanks::EIGHT},
                                                                               {"NINE",  DurakRanks::NINE}, {"TEN", DurakRanks::TEN},
                                                                               {"JACK",  DurakRanks::JACK}, {"KING", DurakRanks::KING}, {"QUEEN", DurakRanks::QUEEN}};
        auto found2 = ranksTable.find(r);
        if(found2 != ranksTable.end()){
            rank = found2->second;
        }
        else{
            std::cout << "unable to set rank, invalid input" << std::endl;
        }
    }

bool DurakCardParent::operator<(DurakCardParent &card) {
    if(this->getValue() < card.getValue()){
        return true;
    }
    return false;
}

int DurakCardParent::getValue() {
    switch(rank){
        case ACE:
            return 14;
        case SIX:
            return 6;
        case SEVEN:
            return 7;
        case EIGHT:
            return 8;
        case NINE:
            return 9;
        case TEN:
            return 10;
        case JACK:
            return 11;
        case QUEEN:
            return 12;
        case KING:
            return 13;
    }
}

std::ostream &operator<<(std::ostream &out, DurakCardParent &card) {
    out << card.getRank() << " OF " << card.getSuit();
    return out;
}
