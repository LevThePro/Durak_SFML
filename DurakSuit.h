//
// Created by Dave R. Smith on 2/14/23.
//

#ifndef CS3A_SPRING23_SFMLCARD_SUIT_H
#define CS3A_SPRING23_SFMLCARD_SUIT_H
#include <SFML/Graphics.hpp>
#include "DurakSuits.h"
#include "DurakImages.h"
class DurakSuit : public sf::Sprite
{
//private:
    //sf::Sprite suitImage;
public:
    DurakSuit();
    DurakSuit(DurakSuits suit);
};


#endif //CS3A_SPRING23_SFMLCARD_SUIT_H
