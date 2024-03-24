//
// Created by Dave R. Smith on 2/14/23.
//

#ifndef CS3A_SPRING23_SFMLCARD_CARD_H
#define CS3A_SPRING23_SFMLCARD_CARD_H

#include "DurakBackground.h"
#include "DurakRank.h"
#include "DurakSuit.h"
#include "DurakPosition.h"
#include "DurakCardParent.h"
#include <SFML/Graphics.hpp>
class DurakCard : public sf::Drawable, sf::Transformable, DurakCardParent
{
private:
    DurakBackground background;
    DurakRank rank;
    DurakSuit suit;
public:
    //void animatedMovement(const sf::Vector2f& targetPos, float duration, sf::RenderWindow& window, float dt);
    DurakSuits getSuit();
    DurakRanks getRank();
    bool contains(float x, float y) const;
    int getValue() override;
    DurakCard();
    sf::Vector2f getCoords();
    void move(float x, float y);
    void setScale(float x, float y);
    sf::FloatRect getLocalBounds();
    DurakCard(DurakRanks rank, DurakSuits suit);
    DurakCard(DurakCardParent card);
    void setPosition(float x, float y);
    virtual void draw(sf::RenderTarget& window,
                      sf::RenderStates states) const;

};


#endif //CS3A_SPRING23_SFMLCARD_CARD_H
