//
// Created by Lev on 3/22/2023.
//

#ifndef SFML_PROJECT_DURAKCARDPARENT_H
#define SFML_PROJECT_DURAKCARDPARENT_H

#include "DurakRank.h"
#include "DurakSuit.h"

class DurakCardParent {
private:
    DurakRanks rank;
    DurakSuits suit;
public:
    DurakCardParent();
    DurakCardParent(DurakRanks rank, DurakSuits suit);
    DurakRanks& getRank();
    DurakSuits& getSuit();
    virtual int getValue();
    bool operator < (DurakCardParent& card);
    friend std::ostream& operator<<(std::ostream& out, DurakCardParent& card);
    DurakCardParent(std::string s, std::string r);
};


#endif //SFML_PROJECT_DURAKCARDPARENT_H
