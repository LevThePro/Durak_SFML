//
// Created by Dave R. Smith on 2/14/23.
//

#include "DurakFont.h"
sf::Font DurakFont::font;

void DurakFont::loadFont()
{
    font.loadFromFile("OpenSans-Bold.ttf");
}

sf::Font& DurakFont::getFont()
{
    loadFont();
    return font;
}