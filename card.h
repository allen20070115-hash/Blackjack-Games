#ifndef CARD_H
#define CARD_H
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;

class Card {
public:
    enum class Suit { Spades, Hearts, Diamonds, Clubs };
    Card(int v, Suit s, string n);

    void draw(sf::RenderWindow& window, sf::Vector2f pos, bool faceUp, const sf::Font& font) const;
    int getValue() const;
    string getName() const;

private:
    int value;
    Suit suit;
    string name;
};

#endif