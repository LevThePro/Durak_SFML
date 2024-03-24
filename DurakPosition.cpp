//
// Created by Lev on 2/15/2023.
//
#ifndef SFML_PROJECT_POSITION_CPP
#define SFML_PROJECT_POSITION_CPP
#include "DurakPosition.h"
template<typename T, typename S>
void DurakPosition::center(const T &constObj, S &obj) {
    sf::FloatRect bounds = constObj.getGlobalBounds();
    obj.setOrigin(obj.getLocalBounds().width/2, obj.getLocalBounds().height/2); //sets origin to center of object
    obj.setPosition({bounds.left + bounds.width/2, bounds.top + bounds.height/2});//object now moves relative to its center
}
template<typename D, typename E>
void DurakPosition::bottomRight(const D &constObj, E &obj) {
    sf::FloatRect bounds = constObj.getGlobalBounds();
    obj.setOrigin(obj.getLocalBounds().width/2, obj.getLocalBounds().height/2);
    obj.setPosition({bounds.left+18, bounds.top+10});
}

template<typename B, typename C>
void DurakPosition::topLeft(const B &constObj, C &obj) {
    sf::FloatRect bounds = constObj.getGlobalBounds();
    obj.setOrigin(obj.getLocalBounds().width/2, obj.getLocalBounds().height/2);
    obj.setPosition({bounds.left+bounds.width-18, bounds.top+bounds.height-10});
}
#endif //SFML_PROJECT_POSITION_CPP