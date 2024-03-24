//
// Created by Lev on 4/20/2023.
//


#include "Game.h"
#include <dos.h>

Game::Game() {
    attackingPlayer = 1;
    defendingPlayer = 2;
    deck.shuffle();
    trump = deck.getCardAt(0).getSuit();
    for (int i = 0; i < 6; i++) {
        p1.drawHand(deck);
        p2.drawHand(deck);
    }
    endGame = false;
}

void Game::playGame() {
    sf::Clock clock;
    bool combat1 = true;
    const int window_width = 800;
    const int window_height = 600;
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Durak Game");
    if(LoadingScreen::menu(window)){
        drawBoard(window, deck, trump);
        float card_spacing = window_width / (p1.get_hand().size() + 1);
        for(int i = 0; i < p1.get_hand().size(); ++i){
            p1.get_hand()[i].setPosition((i + 1) * card_spacing, window_height - p1.get_hand()[i].getLocalBounds().height - 20);
            window.draw(p1.get_hand()[i]);
        }
        card_spacing = window_width / (p2.get_hand().size() + 1);
        for(int i = 0; i < p2.get_hand().size(); ++i){
            p2.get_hand()[i].setPosition((i + 1) * card_spacing, 20);
            window.draw(p2.get_hand()[i]);
        }
        //set up board: draw cards, etc;
        window.display();
        int winPlayer = -1;
        while(window.isOpen() && !endGame){
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }
            float card_spacing = window_width / (p1.get_hand().size() + 1);
            for (int i = 0; i < p1.get_hand().size(); ++i) {
                p1.get_hand()[i].setPosition((i + 1) * card_spacing, window_height - p1.get_hand()[i].getLocalBounds().height - 20);
                window.draw(p1.get_hand()[i]);
            }
            card_spacing = window_width / (p2.get_hand().size() + 1);
            for (int i = 0; i < p2.get_hand().size(); ++i) {
                p2.get_hand()[i].setPosition((i + 1) * card_spacing, 20);
                window.draw(p2.get_hand()[i]);
            }
            window.clear(sf::Color::Black);
            performTurn(window);
            //combat starts - p1 first
            //here p1 selects card to attack
            if(p1.hand_is_empty()){
                winPlayer = 1;
                endGame = true;
            }
            else if(p2.hand_is_empty()){
                winPlayer = 2;
                endGame = true;
            }
            if(endGame){
                LoadingScreen::endScreen(window, winPlayer);
            }
        }
    }
}

void Game::performTurn(sf::RenderWindow& window) {
    if(p1.hand_is_empty()){
        return;
    }
    if(p2.hand_is_empty()){
        return;
    }
    //std::cout << "again at begin" << std::endl;
    window.clear(sf::Color::Black);
    //std::cout << "maybe uhoh drawboard" << std::endl;
    if(!deck.empty()){
        drawBoard(window, deck, trump);
    }
    else{
        drawBoard(window);
    }
   // std::cout << "AFTER             maybe uhoh drawboard" << std::endl;
    for (const auto& card : p1.get_hand()) {
        window.draw(card);
    }
    for (const auto& card : p2.get_hand()) {
        window.draw(card);
    }
    window.display();

    Player& attackPlayer = getCurrentPlayer();
    Player& defPlayer = getDefendingPlayer();
    int attack_card_index = -1;
    bool should_continue = true;
    while(attack_card_index == -1 && should_continue){
        should_continue = wait_for_card_click(window, attackPlayer, attack_card_index);
    }
    if(!should_continue){
        return;
    }
    std::cout << attack_card_index << std::endl;
    DurakCard& attackingCard = attackPlayer.get_hand()[attack_card_index];
    attackingCard.setPosition((window.getSize().x - 100) / 2,(window.getSize().y - 150) / 2);
    //sf::Vector2f coords;
    //coords.x = (window.getSize().x - 100) / 2;
    //coords.y = (window.getSize().y - 150) / 2;
    //attackingCard.animatedMovement(coords, 1, window, dt);
    //animate_card_movement(attackingCard, coords, window);


    window.clear(sf::Color::Black);
    if(!deck.empty()){
        drawBoard(window, deck, trump);
    }
    else{
        drawBoard(window);
    }
    for (const auto& card : p1.get_hand()) {
        window.draw(card);
    }
    for (const auto& card : p2.get_hand()) {
        window.draw(card);
    }
    window.display();


    int defending_card_index = -1;
    should_continue = true;
    while (defending_card_index == -1 && should_continue) {
        should_continue = wait_for_card_click(window, defPlayer, defending_card_index);
    }
    if (!should_continue) {
        return;
    }
    std::cout << defending_card_index << std::endl;
    DurakCard& defendingCard = defPlayer.get_hand()[defending_card_index];
    defendingCard.setPosition(((window.getSize().x - 100) / 2)-20,((window.getSize().y - 150) / 2)-20);

    window.clear(sf::Color::Black);
    if(!deck.empty()){
        drawBoard(window, deck, trump);
    }
    else{
        drawBoard(window);
    }
    for (const auto& card : p1.get_hand()) {
        window.draw(card);
    }
    for (const auto& card : p2.get_hand()) {
        window.draw(card);
    }
    window.display();
//bool defend = Player::canDefend(attackingCard, defendingCard);
//    std::cout << defend << std::endl;

    if(Player::combat(attackingCard, defendingCard, trump)){
        attackPlayer.removeCard(attack_card_index);
        defPlayer.removeCard(defending_card_index);
        combatLost = false;
        //std::cout<< "combat won" << std::endl;
    }
    else{
        defPlayer.takeCard(attackingCard);
        attackPlayer.removeCard(attack_card_index);
        combatLost = true;
        //std::cout<< "combat lost" << std::endl;
    }
    //std::cout << "after combat lost" << std::endl;
    window.clear(sf::Color::Black);
    if(!deck.empty()){
        drawBoard(window, deck, trump);
    }
    else{
        drawBoard(window);
    }
    //std::cout << "after drawBoard" << std::endl;
    for (const auto& card : p1.get_hand()) {
        window.draw(card);
    }
    for (const auto& card : p2.get_hand()) {
        window.draw(card);
    }
    window.display();
    attack_card_index = -1;
    defending_card_index = -1;
    updateTurn();
    //std::cout << "after end" << std::endl;
}

bool Game::wait_for_card_click(sf::RenderWindow &window, Player &player, int &clicked_card_index) {
    sf::Event event;
    while(window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            window.close();
            return false;
        }
        else if(event.type == event.MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left){ //only registers one click
            for (int i = 0; i < player.get_hand().size(); ++i) {
                if (player.get_hand()[i].contains(event.mouseButton.x, event.mouseButton.y)) {
                    clicked_card_index = i;
                    return true;
                }
            }
        }
    }
    return true;
}

void Game::drawBoard(sf::RenderWindow &window, DurakDeck deck, DurakSuits trump) {
    //std::cout << "deck size is: " << deck.getCards().size() << std::endl;
    DurakSuit trumpSuit(trump);
    trumpSuit.setPosition(20,20);
    DurakCard trumpCard = deck.getCardAt(0);
    sf::RectangleShape background(sf::Vector2f(window.getSize().x, window.getSize().y));
    background.setFillColor(sf::Color(252, 128, 128)); // color
    window.draw(background);

    // Draw lines separating the areas for attacking and defending cards
    float lineY = window.getSize().y / 2.0f;
    sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(0, lineY), sf::Color::White),
            sf::Vertex(sf::Vector2f(window.getSize().x, lineY), sf::Color::White)
    };
    window.draw(line, 2, sf::Lines);
    window.draw(trumpSuit);
    if(!deck.empty()){
        sf::Texture texture;
        texture.loadFromFile("cardback.png");
        sf::Sprite cardBack(texture);
        sf::Rect<float> size = cardBack.getGlobalBounds();
        float xFactor = 120/size.width;
        float yFactor = 170/size.height;
        cardBack.setScale(xFactor, yFactor);
        cardBack.setOrigin(cardBack.getLocalBounds().width/2, cardBack.getLocalBounds().height/2);
        cardBack.setPosition(60,300);
        window.draw(cardBack);
    }
}

Player &Game::getCurrentPlayer() {
    if(attackingPlayer == 1){
        return p1;
    }
    return p2;
}

Player &Game::getDefendingPlayer() {
    if(defendingPlayer == 1){
        return p1;
    }
    return p2;
}

void Game::updateTurn() {
    if(!deck.empty()){
        p1.drawHand(deck);
        p2.drawHand(deck);
    }
    if(!combatLost){
        int temp;
        temp = defendingPlayer;
        defendingPlayer = attackingPlayer;
        attackingPlayer = temp;
    }

}

void Game::drawBoard(sf::RenderWindow &window) {
    sf::RectangleShape background(sf::Vector2f(window.getSize().x, window.getSize().y));
    background.setFillColor(sf::Color(252, 128, 128)); // color
    window.draw(background);

    // Draw lines separating the areas for attacking and defending cards
    float lineY = window.getSize().y / 2.0f;
    sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(0, lineY), sf::Color::White),
            sf::Vertex(sf::Vector2f(window.getSize().x, lineY), sf::Color::White)
    };
    window.draw(line, 2, sf::Lines);
}

void Game::animate_card_movement(DurakCard &card, const sf::Vector2f &target_position, sf::RenderWindow& window, sf::Clock& clock) {
    clock.restart();
    sf::Vector2f current_position = card.getCoords();
    sf::Vector2f delta = target_position - current_position;
    while(window.isOpen() && (current_position != target_position)){
        sf::Time elapsed = clock.restart();
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }
        card.move(elapsed.asSeconds()/delta.x, elapsed.asSeconds()/delta.y);
        window.clear(sf::Color::Black);
        window.draw(card);
        window.display();
        current_position = card.getCoords();
    }
}
/*    window.clear(sf::Color::Black);
    if(!deck.empty()){
        drawBoard(window, deck, trump);
    }
    else{
        drawBoard(window);
    }
    for (const auto& card : p1.get_hand()) {
        window.draw(card);
    }
    for (const auto& card : p2.get_hand()) {
        window.draw(card);
    }*/



/*
 *
 *     sf::Text text;
    text.setFont(DurakFont::getFont());
    text.setString(std::to_string(trump));
    text.setPosition(0, 20);
            attackingCards.push_back(p1.chooseAttack());
            p2.defense(attackingCards, trump);




            float yPos = 20;
                    sf::Text text;
                    text.setFont(DurakFont::getFont());
                    text.setString("clicked on card: "+ std::to_string(i));
                    text.setPosition(0, yPos);
                    window.draw(text);

                        while(!clickedOnCard){
        sf::Event event;
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            clickedOnCard = true;
            std::cout << 4 << std::endl;
            for (size_t i = 0; i < player.get_hand().size(); ++i) {
                if (player.get_hand()[i].contains(event.mouseButton.x, event.mouseButton.y)) {
                    std::cout << i << std::endl;
                    break;
                }
            }
        }
    }


        bool should_continue = true;
    while (clicked_card_index == -1 && should_continue) {
        should_continue = wait_for_card_click(window, attackPlayer, clicked_card_index);
    }
    if (!should_continue) {
        return;
    }
        }*/