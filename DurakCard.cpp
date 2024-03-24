//
// Created by Dave R. Smith on 2/14/23.
//

#include "DurakCard.h"
#include "DurakPosition.h"

void DurakCard::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(background.getRect(), states);
    window.draw(suit, states);
    window.draw(rank, states);
}

DurakCard::DurakCard(DurakRanks rank, DurakSuits suit): DurakCardParent(rank, suit){
    this->rank = DurakRank(getRank());
    this->suit = DurakSuit(getSuit());
    background = DurakBackground();
    if(suit == HEARTS || suit == DIAMONDS){
        this->rank.getBottomText().setFillColor(sf::Color::Red);
        this->rank.getTopText().setFillColor(sf::Color::Red);
    }
    DurakPosition::topLeft(background.getRect(), this->rank.getTopText());
    DurakPosition::bottomRight(background.getRect(), this->rank.getBottomText());
    DurakPosition::center(background.getRect(), this->suit);

}

void DurakCard::setPosition(float x, float y) {
    background.rect().setPosition(x, y);
    DurakPosition::topLeft(background.getRect(), this->rank.getTopText());
    DurakPosition::bottomRight(background.getRect(), this->rank.getBottomText());
    DurakPosition::center(background.getRect(), this->suit);
}

DurakCard::DurakCard(DurakCardParent card) {
    this->rank = DurakRank(card.getRank());
    this->suit = DurakSuit(card.getSuit());
    background = DurakBackground();
    if(card.getSuit() == HEARTS || card.getSuit() == DIAMONDS){
        this->rank.getBottomText().setFillColor(sf::Color::Red);
        this->rank.getTopText().setFillColor(sf::Color::Red);
    }
    DurakPosition::topLeft(background.getRect(), this->rank.getTopText());
    DurakPosition::bottomRight(background.getRect(), this->rank.getBottomText());
    DurakPosition::center(background.getRect(), this->suit);
}

DurakSuits DurakCard::getSuit() {
    return DurakCardParent::getSuit();
}

int DurakCard::getValue() {
    return DurakCardParent::getValue();
}

DurakRanks DurakCard::getRank() {
    return DurakCardParent::getRank();
}

bool DurakCard::contains(float x, float y) const {
    sf::FloatRect bounds = background.getRect().getGlobalBounds();
    bounds.left += getPosition().x;
    bounds.top += getPosition().y;
    return bounds.contains(x, y);
}

sf::FloatRect DurakCard::getLocalBounds() {
    return background.getRect().getLocalBounds();
}

void DurakCard::setScale(float x, float y) {
    background.getRect().setScale(x,y);
    suit.setScale(x, y);
    rank.getBottomText().setScale(x, y);
    rank.getTopText().setScale(x,y);
}

//void DurakCard::animatedMovement(const sf::Vector2f &targetPos, float duration, sf::RenderWindow &window, float dt){
//    sf::Vector2f currentPos = getPosition();
//    sf::Vector2f diff = targetPos - currentPos;
//    sf::Vector2f step = diff * (dt / duration);
//    if(std::abs(diff.x) > std::abs(step.x) || std::abs(diff.y) > std::abs(step.y)){
//        move(step);
//    }
//    else{
//        setPosition(targetPos.x, targetPos.y);
//    }
//}

void DurakCard::move(float x, float y) {
    Transformable::move(x, y);
}

sf::Vector2f DurakCard::getCoords() {
    return Transformable::getPosition();
}

DurakCard::DurakCard() = default;
