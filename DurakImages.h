//
// Created by Dave R. Smith on 2/14/23.
//

#ifndef CS3A_SPRING23_SFMLCARD_IMAGES_H
#define CS3A_SPRING23_SFMLCARD_IMAGES_H
#include <vector>
#include "DurakSuits.h"
#include <SFML/Graphics.hpp>
#include <string>

class DurakImages
{
private:
    static std::vector<sf::Texture> images;
    static std::string getPath(DurakSuits suit);
    static void loadFile(DurakSuits suit);
public:
    static sf::Texture& getImage(DurakSuits suit);
};


#endif //CS3A_SPRING23_SFMLCARD_IMAGES_H
