//
// Created by Dave R. Smith on 2/14/23.
//

#ifndef CS3A_SPRING23_SFMLCARD_BACKGROUND_H
#define CS3A_SPRING23_SFMLCARD_BACKGROUND_H


#include <SFML/Graphics.hpp>

class DurakBackground
{
private:
    sf::RectangleShape rectangle;
public:
    DurakBackground();
    sf::RectangleShape getRect() const;
    sf::RectangleShape& rect();
    virtual void draw(sf::RenderTarget& window,
                      sf::RenderStates states) const;
};


#endif //CS3A_SPRING23_SFMLCARD_BACKGROUND_H
