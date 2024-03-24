//
// Created by Lev on 2/15/2023.
//

#ifndef SFML_PROJECT_DURAKPOSITION_H
#define SFML_PROJECT_DURAKPOSITION_H
#include <SFML\Graphics.hpp>
class DurakPosition {
public:
    template <typename T, typename S>
    static void center(const T& constObj, S& obj);
    template <typename B, typename C>
    static void topLeft(const B& constObj, C& obj);
    template <typename D, typename E>
    static void bottomRight(const D& constObj, E& obj);
};


#include "DurakPosition.cpp"
#endif //SFML_PROJECT_DURAKPOSITION_H
