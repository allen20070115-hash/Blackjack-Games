<<<<<<< Updated upstream
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
=======
version https://git-lfs.github.com/spec/v1
oid sha256:b0409a01f549f18cfa6aa3f8360765f698aaf78ed64b28b924912c87e2d6b594
size 455
>>>>>>> Stashed changes
