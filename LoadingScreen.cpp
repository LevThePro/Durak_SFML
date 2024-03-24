//
// Created by Lev on 4/26/2023.
//

#include "LoadingScreen.h"

void LoadingScreen::endScreen(sf::RenderWindow &window, int winner) {
    sf::Text end_text;
    end_text.setFont(DurakFont::getFont());
    end_text.setString("Player " + std::to_string(winner) + " wins!");
    end_text.setCharacterSize(50);
    end_text.setFillColor(sf::Color::White);
    end_text.setPosition((window.getSize().x - end_text.getGlobalBounds().width) / 2,(window.getSize().y - end_text.getGlobalBounds().height) / 2);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear(sf::Color(0, 0, 50)); // Set the background color
        window.draw(end_text);
        window.display();
    }
}

bool LoadingScreen::menu(sf::RenderWindow &window) {
    DurakDeck deck;
    int xcord = 0;
    int ycord = 0;
    sf::Text start_text;
    start_text.setOrigin(start_text.getLocalBounds().width/2, start_text.getLocalBounds().height/2);
    start_text.setPosition(window.getSize().x / 2,window.getSize().y / 2 - 100);
    start_text.setFont(DurakFont::getFont());
    start_text.setString("DURAK");
    start_text.setCharacterSize(70);
    start_text.setFillColor(sf::Color::White);
    start_text.setOutlineThickness(4);
    sf::RectangleShape button(sf::Vector2f(100, 50));
    button.setFillColor(sf::Color::Transparent);
    button.setPosition((window.getSize().x - 250) / 2,(window.getSize().y - 50) / 2);
    sf::Text button_text;
    button_text.setFont(DurakFont::getFont());
    button_text.setString("START");
    button_text.setCharacterSize(30);
    button_text.setFillColor(sf::Color::Black);
    button_text.setOutlineThickness(5);
    button_text.setOutlineColor(sf::Color::White);
    DurakPosition::center(button, button_text);

    sf::Text name("Lev Tumaykin", DurakFont::getFont());
    name.setPosition(10,10);
    sf::Text crn("CRN: 37045", DurakFont::getFont());
    crn.setPosition(10, 50);
    sf::Text date("Fall 2020", DurakFont::getFont());
    date.setPosition(10, 90);

    while(window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return false;
            } else if (event.type == sf::Event::MouseButtonReleased) {
                sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
                if (button.getGlobalBounds().contains(mouse_position.x, mouse_position.y)) {
                    return true;
                }
            }
        }
        window.clear();
        srand(time(0));
        for(auto i : deck.getCards()){
            i.setPosition(rand() % 500+100,rand() % 300+100);
            window.draw(i);
        }
        window.draw(start_text);
        window.draw(button);
        window.draw(button_text);
        window.draw(name);
        window.draw(crn);
        window.draw(date);

        window.display();
    }
    return false;
}
