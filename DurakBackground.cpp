//
// Created by Dave R. Smith on 2/14/23.
//

#include "DurakBackground.h"

void DurakBackground::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(rectangle, states);
}

DurakBackground::DurakBackground() {
    rectangle.setSize(sf::Vector2f(100, 150));
    rectangle.setFillColor(sf::Color::White);
    rectangle.setPosition(255, 100);
    rectangle.setOutlineThickness(1);
    rectangle.setOutlineColor(sf::Color::Black);
}

sf::RectangleShape DurakBackground::getRect() const {
    return rectangle;
}

sf::RectangleShape &DurakBackground::rect() {
    return rectangle;
}
