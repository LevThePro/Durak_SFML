//
// Created by Lev on 4/26/2023.
//

#ifndef SFML_PROJECT_LOADINGSCREEN_H
#define SFML_PROJECT_LOADINGSCREEN_H

#include "DurakFont.h"
#include "DurakDeck.h"
#include "DurakPosition.h"
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>


class LoadingScreen {
public:
    static bool menu(sf::RenderWindow& window);
    static void endScreen(sf::RenderWindow& window, int winner);
};


#endif //SFML_PROJECT_LOADINGSCREEN_H
