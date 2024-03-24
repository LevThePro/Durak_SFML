//
// Created by Dave R. Smith on 2/14/23.
//

#include "DurakRank.h"

DurakRank::DurakRank(){}

DurakRank::DurakRank(DurakRanks rank)
{
    top.setOrigin(top.getPosition());
    bottom.setOrigin(bottom.getPosition());
    top.setFont(DurakFont::getFont());
    bottom.setFont(DurakFont::getFont());
    bottom.setFillColor(sf::Color::Black);
    top.setRotation(180.f);
    bottom.setCharacterSize(30);
    top.setFillColor(sf::Color::Black);
    top.setCharacterSize(30);
    switch(rank){
        case ACE:
            top.setString("A");
            bottom.setString("A");
            break;
        case SIX:
            top.setString("6");
            bottom.setString("6");
            break;
        case SEVEN:
            top.setString("7");
            bottom.setString("7");
            break;
        case EIGHT:
            top.setString("8");
            bottom.setString("8");
            break;
        case NINE:
            top.setString("9");
            bottom.setString("9");
            break;
        case TEN:
            top.setString("10");
            bottom.setString("10");
            break;
        case JACK:
            top.setString("J");
            bottom.setString("J");
            break;
        case QUEEN:
            top.setString("Q");
            bottom.setString("Q");
            break;
        case KING:
            top.setString("K");
            bottom.setString("K");
            break;
    }
}

void DurakRank::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(top, states);
    window.draw(bottom, states);
}

sf::Text &DurakRank::getBottomText() {
    return bottom;
}

sf::Text &DurakRank::getTopText() {
    return top;
}
