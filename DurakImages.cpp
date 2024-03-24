//
// Created by Dave R. Smith on 2/14/23.
//

#include "DurakImages.h"

std::vector<sf::Texture> DurakImages::images(LAST_SUIT, sf::Texture());

std::string DurakImages::getPath(DurakSuits suit)
{
    switch(suit)
    {
        case HEARTS: return "suits/heart.png";
        case DIAMONDS: return "suits/diamonds.png";
        case SPADES: return "suits/spades.png";
        case CLUBS: return "suits/club.png";
    }
}

void DurakImages::loadFile(DurakSuits suit)
{
    images[suit].loadFromFile(getPath(suit));
}

sf::Texture& DurakImages::getImage(DurakSuits suit)
{
    loadFile(suit);
    return images[suit];
}