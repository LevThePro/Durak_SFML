//
// Created by Dave R. Smith on 2/14/23.
//

#include "DurakSuit.h"
DurakSuit::DurakSuit(DurakSuits suit)
{
    setTexture(DurakImages::getImage(suit));
    sf::Rect<float> size = getGlobalBounds();
    float xFactor = 50/size.width;
    float yFactor = 50/size.height;
    sf::Sprite::setScale(xFactor,yFactor);
}

DurakSuit::DurakSuit() {
    setTexture(DurakImages::getImage(HEARTS));
}
